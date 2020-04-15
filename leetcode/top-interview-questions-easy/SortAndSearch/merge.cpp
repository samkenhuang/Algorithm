#include "../../util/stl.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int index1 = 0, index2 = 0;
        while (index1 < m && index2 < n) {
            if (nums1[index1] < nums2[index2]) {
                nums3.push_back(nums1[index1]); index1 ++;
            } else {
                nums3.push_back(nums2[index2]); index2 ++;
            }
        }
        while(index1 < m) {
            nums3.push_back(nums1[index1]); index1 ++;
        }
        while(index2 < n) {
            nums3.push_back(nums2[index2]); index2 ++;
        }
        nums1 = nums3;
    }
};

int main() {
    Solution s;
    vector<int> nums3 = {4, 0,0,0,0,0}, nums4 = {1,2,3,5,6};
    s.merge(nums3, 1, nums4, 5);
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    return 0;
}

