#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int a[size];
        int i = 0;
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end()) {
            a[i++] = *iter;
            iter++;
        }
        for (i = 0, iter = nums.begin(); iter != nums.end(); i++, iter++)
        {
            int index = (i + size - k % size) % size;
            *(iter) = a[index];
        }
    }
};

int main() {
    int a[2] = {1,2};
    vector<int> vec(a, a + 2);
    Solution s;
    s.rotate(vec, 3); // 2,1
    cout << 1 << endl;
    return 0;
}