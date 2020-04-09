// 未完成
#include "../util/stl.h"

int vectorInsert(vector<string> &t, string prefix, string suffix, vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        t.push_back(prefix + v[i] + suffix);
    }
    return t.size();
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back(vector<string>({"()"}));
        dp.push_back(vector<string>({"(())", "()()"}));
        dp.push_back(vector<string>({"((()))", "(()())", "(())()", "()(())", "()()()"}));
        if (n - 1 > 2) {
            for(int i = 3; i < n; i ++) {
                vector<string> current;
                vectorInsert(current, "(", ")", dp[i - 1]);
                vectorInsert(current, "()", "", dp[i - 1]);
                vectorInsert(current, "((", "))()", dp[i - 3]);
                dp.push_back(current);
            }
        }
        return dp[n - 1];
    }
};


int main() {
    Solution s;
    s.generateParenthesis(4);
    return 0;
}