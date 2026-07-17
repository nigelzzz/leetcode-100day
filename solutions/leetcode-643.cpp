#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        // First window: [0, k - 1]
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;

        // r is the index of the new element entering the window.
        for (int r = k; r < static_cast<int>(nums.size()); r++) {
            sum -= nums[r - k];
            sum += nums[r];
            maxSum = max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / k;
    }
};
