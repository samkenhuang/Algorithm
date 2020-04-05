#include "../util/stl.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        vector<int>::iterator it1 = nums.begin();
        for (; it1 != nums.end() - 3; ++it1) {
            vector<int>::iterator it2 = it1 + 1;
            for (; it2 != nums.end() - 2; ++it2) {
                vector<int>::iterator it3 = it2 + 1;
                vector<int>::iterator it4 = nums.end() - 1;
                while(it3 != it4) {
                    if (*it1 + *it2 + *it3 + *it4 == target) {
                        res.push_back({*it1, *it2, *it3, *it4});
                        while (*it3 == *(it3 + 1) && *it3 != *it4) it3++;
                        it3 ++;
                    } else if (*it1 + *it2 + *it3 + *it4 > target){
                        *it4--;
                    } else {
                        *it3++;
                    }
                }
                while (*it2 == *(it2 + 1) && it2 != nums.end() - 2) it2++;
            }
            while (*it1 == *(it1 + 1) && it1 != nums.end() - 3) it1++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v;
    int a[8] = {-3,-2,-1,0,0,1,2,3};
    vectorD1(v, a, 8);
    s.fourSum(v, 0);
    cout << 1 << endl;
    return 0;
}