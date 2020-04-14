#include "../util/stl.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] > 0 ? -nums[abs(nums[i]) - 1] : nums[abs(nums[i]) - 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v = {4,3,2,7,8,2,3,1};
    s.findDisappearedNumbers(v);// [5, 6]
    return 0;
}