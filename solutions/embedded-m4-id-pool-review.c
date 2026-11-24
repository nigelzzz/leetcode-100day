// M4 review (2026-11-23): rewrite id_pool from memory. Do not open embedded-m4-id-pool.c.
// Build: gcc -std=c11 -Wall -Wextra -O2 -fsanitize=address,undefined embedded-m4-id-pool-review.c && ./a.out
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct id_pool id_pool;   /* TODO: define the struct */

/* Manage IDs 0 .. n-1. Return NULL for invalid n or when allocation fails. */
id_pool *id_pool_create(size_t n);

void id_pool_destroy(id_pool *p);

/* Return the smallest free ID and mark it used. Return -1 when the pool is full. */
int id_pool_alloc(id_pool *p);

/* Mark id as free. Return 0 on success, -1 for an invalid id or an id that is already free. */
int id_pool_free(id_pool *p, int id);

/* ---- your implementation below ---- */



/* ---- tests: do not change ---- */
int main(void) {
    id_pool *p = id_pool_create(40);
    assert(p != NULL);

    for (int i = 0; i < 40; i++) {
        assert(id_pool_alloc(p) == i);
    }
    assert(id_pool_alloc(p) == -1);         /* full: tail bits 40..63 must not be handed out */

    assert(id_pool_free(p, 33) == 0);
    assert(id_pool_free(p, 5) == 0);
    assert(id_pool_free(p, 5) == -1);       /* double free */
    assert(id_pool_free(p, 40) == -1);      /* out of range */
    assert(id_pool_free(p, -1) == -1);      /* negative */

    assert(id_pool_alloc(p) == 5);          /* smallest free first */
    assert(id_pool_alloc(p) == 33);
    assert(id_pool_alloc(p) == -1);
    id_pool_destroy(p);

    p = id_pool_create(64);                 /* n is a multiple of 32: no tail bits */
    assert(p != NULL);
    for (int i = 0; i < 64; i++) {
        assert(id_pool_alloc(p) == i);
    }
    assert(id_pool_alloc(p) == -1);
    id_pool_destroy(p);

    assert(id_pool_create(0) == NULL);

    puts("all tests passed");
    return 0;
}
