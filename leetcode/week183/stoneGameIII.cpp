#include "../util/stl.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        int sum = 0;
        int *dp = new int[size];
        // 最佳策略
        for(int i = size - 1; i >= 0; i --) {
            sum += stoneValue[i];
            if (i == size - 1) { dp[i] = stoneValue[i]; }
            else {
                if(i == size - 2) dp[i] = max({sum - dp[i + 1], sum, sum});
                else if (i == size - 3) dp[i] = max({sum - dp[i + 1], sum - dp[i + 2], sum});
                else dp[i] = max({sum - dp[i + 1], sum - dp[i + 2], sum - dp[i + 3]});
            }
        }
        if(dp[0] > sum - dp[0]) return "Alice";
        else if (dp[0] < sum - dp[0]) return "Bob";
        else return "Tie";
    }
};

int main() {
    Solution s;
    vector<int> v;
    int arr[] = {1,2,3,-1,-2,-3,7};
    vectorD1(v, arr, 7);
    cout << s.stoneGameIII(v) << endl;
    cout << 1 << endl;
    return 0;
}