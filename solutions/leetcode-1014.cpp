#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_left = values[0];
        int ans = INT_MIN;

        for (int i = 1; i < static_cast<int>(values.size()); ++i) {
            ans = max(ans, max_left + values[i] - i);
            max_left = max(max_left, values[i] + i);
        }

        return ans;
    }
};
