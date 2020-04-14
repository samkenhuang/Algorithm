#include "../util/stl.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, current = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if(nums[i] == 1) {
                current ++;
                if(current > max) max = current;
            } else {
                current = 0; 
            }
        }
        return max;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,1,0,1,1,1};
    s.findMaxConsecutiveOnes(v);
    return 0;
}