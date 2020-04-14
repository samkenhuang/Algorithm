#include "../util/stl.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a[3] = {LLONG_MIN, LLONG_MIN, LLONG_MIN};
        for (int i = 0; i < nums.size(); i ++) {
            if(a[0] != nums[i] && a[1] != nums[i] && a[2] != nums[i]) {
                if(a[0] < nums[i]) {
                    a[2] = a[1];a[1] = a[0]; a[0] = nums[i];
                } else if (a[1] < nums[i]) {
                    a[2] = a[1]; a[1] = nums[i];
                } else if (a[2] < nums[i]) {
                    a[2] = nums[i];
                }
            }
        }
        return a[2] == LLONG_MIN ? a[0] : a[2];
    }
};


int main() {
    Solution s;
    vector<int> v = {1,1,-2147483648};
    cout << s.thirdMax(v) << endl; // 1
    return 0;
}