#include "../util/stl.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int maxlen = 0;
        for (int i = 1; i < s.size(); i ++) {
            if (s[i] == '(') dp[i] = 0;
            else { // 碰到')',需要往前匹配
                int matchPos = i - 1, back = dp[matchPos];
                while (back != 0) {
                    matchPos = matchPos - back;
                    back = (matchPos >= 0 ? dp[matchPos] : 0);
                }
                // 匹配到 '(', 计算各种情况
                if(matchPos >= 0 && s[matchPos] == '(') {
                    dp[i] = 2 + dp[i - 1] + (matchPos > 0 ? dp[matchPos - 1] : 0);
                    if (maxlen < dp[i]) maxlen = dp[i];
                }
            }

        }
        return maxlen;
    }
};


int main() {
    Solution s;
    cout << s.longestValidParentheses("())") << endl;
    cout << s.longestValidParentheses("(())") << endl; // 4
    cout << s.longestValidParentheses(")(())()(())") << endl; // 10
    cout << s.longestValidParentheses("(()") << endl; // 2
    cout << s.longestValidParentheses(")()())") << endl; // 4
    return 0;
}