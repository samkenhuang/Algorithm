#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end()) {
            if (s.count(*iter) != 0){
                return true;
            } else {
                s.insert(*iter);
            }
            iter++;
        }
        return false;
    }
};

int main() {
    int a[4] = {1,2,3,3};
    vector<int> vec(a, a + 4);
    Solution s;
    cout << s.containsDuplicate(vec) << endl;
    return 0;
}