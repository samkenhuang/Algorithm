#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end()) {
            if(s.count(*iter) != 0) {
                s.erase(*iter);
            } else {
                s.insert(*iter);
            }
            iter++;
        }
        return *(s.begin());
    }
};

int main() {
    int a[5] = {4,1,2,1,2};
    vector<int> vec(a, a + 5);
    Solution s;
    cout << s.singleNumber(vec) << endl;
    return 0;
}