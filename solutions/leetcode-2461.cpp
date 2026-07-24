#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        long long sum = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            m[nums[i]]++;
        }

        long long ans = 0;
        if (static_cast<int>(m.size()) == k) {
            ans = sum;
        }

        for (int i = k; i < n; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            m[nums[i - k]]--;
            m[nums[i]]++;

            if (m[nums[i - k]] == 0) {
                m.erase(nums[i - k]);
            }
            if (static_cast<int>(m.size()) == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
