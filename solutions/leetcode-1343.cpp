#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int cnt = 0;
        if (sum >= threshold * k) {
            cnt++;
        }

        for (int r = k; r < static_cast<int>(arr.size()); r++) {
            sum -= arr[r - k];
            sum += arr[r];

            if (sum >= threshold * k) {
                cnt++;
            }
        }

        return cnt;
    }
};
