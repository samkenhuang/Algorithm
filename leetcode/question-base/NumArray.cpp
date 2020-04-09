#include "../util/stl.h"

class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (; i <= j; i ++) {
            sum += nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
    vector<int> v;
    int arr[6] = {-2, 0, 3, -5, 2, -1};
    vectorD1(v, arr, 6);
    NumArray *obj = new NumArray(v);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
    return 0;
}