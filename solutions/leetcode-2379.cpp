#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                count++;
            }
        }

        ans = count;

        for (int i = k; i < static_cast<int>(blocks.size()); i++) {
            char lc = blocks[i - k];
            char rc = blocks[i];

            if (lc == 'W') {
                count--;
            }
            if (rc == 'W') {
                count++;
            }

            ans = min(ans, count);
        }

        return ans;
    }
};
