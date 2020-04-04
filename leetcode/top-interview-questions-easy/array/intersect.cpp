#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator iter1 = nums1.begin();
        while(iter1 != nums1.end()) {
            vector<int>::iterator iter2 = nums2.begin();
            while (iter2 != nums2.end()) {
                if(*iter1 == *iter2) {
                    res.push_back(*iter1);
                    nums2.erase(iter2);
                    break;
                }
                iter2++;
            }
            iter1++;
        }
        return res;
    }
};

int main() {
    int a[4] = {1,2,2,1}, b[2] = {2,2};
    vector<int> vec1(a, a + 4), vec2(b, b + 2);
    Solution s;
    s.intersect(vec1, vec2);
    cout << 1 << endl;
    return 0;
}