#include "../util/stl.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        int max = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else dp[i] = nums[i];
            max = dp[i] > max ? dp[i] : max;
        } 
        return max;
    }
};


int main() {
    Solution s;
    vector<int> v;
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vectorD1(v, arr, 9);
    cout << s.maxSubArray(v) << endl;// 6
    return 0;
}