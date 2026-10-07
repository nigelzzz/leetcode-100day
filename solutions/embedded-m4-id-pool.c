// M4 Bitset drill: bit-based ID pool (0 .. n-1), smallest free ID first.
// Build: gcc -std=c11 -Wall -Wextra -O2 -fsanitize=address,undefined embedded-m4-id-pool.c
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define WORD_BITS 32u
#define WORD_SHR  5u                /* log2(32) */
#define WORD_MASK (WORD_BITS - 1u)  /* 31 */

typedef struct id_pool {
    uint32_t *bits;   /* 1 = used, 0 = free */
    size_t    n;      /* number of valid IDs */
    size_t    nwords;
} id_pool;

id_pool *id_pool_create(size_t n) {
    /* n == 0: nothing to manage. n > INT_MAX: an ID would not fit in the int return value. */
    if (n == 0 || n > (size_t)INT_MAX) {
        return NULL;
    }

    id_pool *p = malloc(sizeof(*p));
    if (p == NULL) {
        return NULL;
    }

    /* Round up without computing n + 31, so this cannot overflow. */
    p->nwords = n / WORD_BITS + (n % WORD_BITS != 0);
    p->n      = n;

    /* calloc checks nwords * size for overflow and zeroes the memory (all IDs free). */
    p->bits = calloc(p->nwords, sizeof(uint32_t));
    if (p->bits == NULL) {
        free(p);              /* do not leak the struct when the second allocation fails */
        return NULL;
    }

    /* Mark the unused tail bits of the last word as "used", so alloc never returns an ID >= n. */
    unsigned r = (unsigned)(n & WORD_MASK);  /* valid bits in the last word, 0 means the word is full */
    if (r != 0) {
        p->bits[p->nwords - 1] = ~((1u << r) - 1u);  /* r is 1..31, so the shift is defined */
    }
    return p;
}

void id_pool_destroy(id_pool *p) {
    if (p == NULL) {
        return;
    }
    free(p->bits);
    free(p);
}

int id_pool_alloc(id_pool *p) {
    if (p == NULL) {
        return -1;
    }
    for (size_t w = 0; w < p->nwords; w++) {
        uint32_t word = p->bits[w];
        if (word == UINT32_MAX) {
            continue;                         /* all 32 IDs in this word are used */
        }
        /* word != 0xFFFFFFFF, so ~word != 0, so ctz is defined. */
        unsigned b = (unsigned)__builtin_ctz(~word);
        p->bits[w] = word | (1u << b);
        return (int)(w * WORD_BITS + b);      /* < n <= INT_MAX, because the tail bits are set */
    }
    return -1;                                /* pool is full */
}

int id_pool_free(id_pool *p, int id) {
    /* Reject negative IDs and IDs in the tail. This keeps the tail bits at 1. */
    if (p == NULL || id < 0 || (size_t)id >= p->n) {
        return -1;
    }
    size_t   i    = (size_t)id;
    uint32_t mask = 1u << (i & WORD_MASK);
    uint32_t *word = &p->bits[i >> WORD_SHR];

    if ((*word & mask) == 0) {
        return -1;                            /* double free, or this ID was never allocated */
    }
    *word &= ~mask;
    return 0;
}

int main(void) {
    /* n == 0 and n too large are rejected. */
    assert(id_pool_create(0) == NULL);
    assert(id_pool_create((size_t)INT_MAX + 1) == NULL);

    /* n = 40: 2 words, 24 tail bits. */
    id_pool *p = id_pool_create(40);
    assert(p != NULL);
    for (int i = 0; i < 40; i++) {
        assert(id_pool_alloc(p) == i);        /* smallest free ID first */
    }
    assert(id_pool_alloc(p) == -1);           /* full: the tail ID 40 is never returned */

    assert(id_pool_free(p, 5) == 0);
    assert(id_pool_free(p, 35) == 0);
    assert(id_pool_alloc(p) == 5);            /* smallest free ID wins */
    assert(id_pool_alloc(p) == 35);

    assert(id_pool_free(p, 7) == 0);
    assert(id_pool_free(p, 7) == -1);         /* double free */
    assert(id_pool_free(p, 40) == -1);        /* out of range, inside the tail */
    assert(id_pool_free(p, 45) == -1);
    assert(id_pool_free(p, -1) == -1);
    assert(id_pool_alloc(p) == 7);
    id_pool_destroy(p);

    /* n = 32: exactly one full word, no tail. */
    p = id_pool_create(32);
    for (int i = 0; i < 32; i++) {
        assert(id_pool_alloc(p) == i);
    }
    assert(id_pool_alloc(p) == -1);
    id_pool_destroy(p);

    /* n = 1: smallest pool. */
    p = id_pool_create(1);
    assert(id_pool_alloc(p) == 0);
    assert(id_pool_alloc(p) == -1);
    assert(id_pool_free(p, 0) == 0);
    id_pool_destroy(p);

    id_pool_destroy(NULL);                    /* must not crash */

    puts("all tests passed");
    return 0;
}
