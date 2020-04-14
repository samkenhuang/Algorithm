#include "../util/stl.h"

bool comp(const int a, const int b) {
    string as = to_string(a), bs = to_string(b);
    return as + bs < bs + as;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), comp);
        for (int i = 0; i < nums.size(); i ++) {
            res += to_string(nums[i]);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v = {824,938,1399,5607,6973,5703,9609,4398,8247};
    s.minNumber(v);
    return 0;
}