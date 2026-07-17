#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool check(char c) {
        if (c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u') {
            return true;
        }

        return false;
    }

    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < k; i++) {
            if (check(s[i])) cnt++;
        }

        ans = cnt;
       
        for (int right = k; right < static_cast<int>(s.size()); right++) {
            if (check(s[right - k])) cnt--;
            if (check(s[right])) cnt++;
            ans = max(ans, cnt);
        }

        return ans;
    }
};
