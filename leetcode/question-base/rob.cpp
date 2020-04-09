#include "../util/stl.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int *dp = new int[nums.size()];
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size();i ++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    Solution s;
    vector<int> v;
    int arr[5] = {2,7,9,3,1};
    vectorD1(v, arr, 5);
    cout << s.rob(v) << endl; // 135
    return 0;
}