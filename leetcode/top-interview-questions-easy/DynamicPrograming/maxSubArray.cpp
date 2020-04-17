#include "../../util/stl.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        vector<int> dp = {nums[0]};
        for (int i = 1; i < nums.size(); i ++) {
            if (dp[i - 1] < 0) dp.push_back(nums[i]);
            else dp.push_back(dp[i - 1] + nums[i]);
            if (max < dp[i]) max = dp[i];
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v) << endl;
    return 0;
}