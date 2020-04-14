#include "../util/stl.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator got =  m.find(nums[i]);
            if(got == m.end()) m.insert({nums[i], i});
            else {
                int lastPos = got->second;
                if(i - lastPos > k) m[nums[i]] = i;
                else return true;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,2,3,1};
    cout << s.containsNearbyDuplicate(v, 3) << endl;
    v = {}
    cout << s.containsNearbyDuplicate({}, 0) << endl;
    return 0;
}