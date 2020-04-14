#include "../util/stl.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int *p = new int[nums.size() + 1]{0};
        for (int i = 0; i < nums.size(); i ++) {
            p[nums[i]] += 1;
        }

        for (int i = 0; i < nums.size() + 1; i ++) {
            if(p[i] == 0) return i;
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<int> v = {8,6,4,2,3,5,7,0,1};
    cout << s.missingNumber(v) << endl; // 9
    return 0;
}