#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m; // num->vector<id1, id2, id3, ...>
        unordered_map<int, vector<int>>::iterator mgot = m.begin();
        vector<int>::iterator iter = nums.begin();
        vector<int> res;

        for (; iter != nums.end(); ++iter) {
            mgot = m.find(*iter);
            if (mgot != m.end()) {
                (mgot->second).push_back(iter - nums.begin());
            } else {
                vector<int> t;
                t.push_back(iter - nums.begin());
                m.insert({{*iter, t}});
            }
        }
        unordered_map<int, vector<int>>::iterator miter = m.begin();
        for (; miter != m.end(); ++miter) {
            int mtarget = target - miter->first;
            mgot = m.find(mtarget);
            if (mgot != m.end() && mgot != miter) {
                res.push_back(miter->second.front());
                res.push_back(mgot->second.front());
                break;
            } else if (mgot == miter && mgot->second.size() > 1) {
                vector<int> v = mgot->second;
                res.assign(v.begin(), v.begin() + 2);
                break;
            }
        }
        return res;
    }
};

int main() {
    int a[3] = {3,3,1};
    vector<int> vec1(a, a + 3);
    Solution s;
    s.twoSum(vec1, 4);
    cout << 1 << endl;
    return 0;
}