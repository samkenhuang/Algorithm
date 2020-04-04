#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator iter = digits.end();
        vector<int> res;
        vector<int>::iterator insertPos = res.begin();
        int flag = 1;
        while (iter != digits.begin()) {
            int digit = *(iter - 1) + flag;
            if (digit < 10) {
                insertPos = res.insert(insertPos, digit);
                flag = 0;
            } else {
                insertPos = res.insert(insertPos, digit % 10);
                flag = 1;
            }
            iter--;
        }
        if (flag == 1) {
            res.insert(insertPos, flag);
        }
        
        return res;
    }
};

int main() {
    int a[4] = {1,2,4,8};
    vector<int> vec1(a, a + 4);
    Solution s;
    s.plusOne(vec1);
    cout << 1 << endl;
    return 0;
}