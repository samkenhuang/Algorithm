#include "../util/stl.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0 + nums[0];
        for (int i = 0; i <= max && i < nums.size(); i++) {
            if (i + nums[i] > max) max = i + nums[i];
        }
        if (max >= nums.size() - 1) return true;
        return false;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {2,3,1,1,4};
    // cout << s.canJump(nums) << endl;
    // vector<int> nums1 = {3,2,1,0,4};
    // cout << s.canJump(nums1) << endl;
    vector<int> nums2 = {1,2,3};
    cout << s.canJump(nums2) << endl;
    return 0;
}