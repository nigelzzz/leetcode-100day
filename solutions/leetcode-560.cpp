#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;

        int prefix = 0;
        int ans = 0;
        for (int x : nums) {
            prefix += x;
            ans += count[prefix - k];
            ++count[prefix];
        }
        return ans;
    }
};
