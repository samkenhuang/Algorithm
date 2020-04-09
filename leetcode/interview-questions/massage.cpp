#include "../util/stl.h"

class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else if (nums.size() == 3) return max(nums[0] + nums[2], nums[1]);
        int *dp = new int[nums.size()];
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]); dp[2] = max(nums[0] + nums[2], nums[1]);
        for (int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};


int main() {
    Solution s;
    vector<int> v;
    int arr[8] = {2,1,4,5,3,1,1,3};
    vectorD1(v, arr, 8);
    cout << s.massage(v) << endl;
    return 0;
}