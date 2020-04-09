#include "../util/stl.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) return 0;
        else if (cost.size() == 1) return cost[0];
        else if (cost.size() == 2) return min(cost[0], cost[1]);
        int *dp = new int[cost.size()];
        dp[0] = cost[0]; dp[1] = cost[1];
        int i = 2;
        for (; i < cost.size(); i ++) {
            dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
        }
        return min(dp[i - 1], dp[i - 2]);
    }
};


int main() {
    Solution s;
    vector<int> v;
    int arr[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vectorD1(v, arr, 10);
    cout << s.minCostClimbingStairs(v) << endl;// 6
    return 0;
}