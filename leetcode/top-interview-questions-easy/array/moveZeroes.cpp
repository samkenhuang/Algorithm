#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        int zeroNum = 0;
        while (iter != nums.end()) {
            if (*iter == 0) {
                zeroNum++;
                iter = nums.erase(iter);
            } else {
                iter++;
            }
        }
        nums.insert(nums.end(), zeroNum, 0);
    }
};

int main() {
    int a[5] = {1,2,0,8, 0};
    vector<int> vec1(a, a + 5);
    Solution s;
    s.moveZeroes(vec1);
    cout << 1 << endl;
    return 0;
}