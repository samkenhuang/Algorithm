#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int>::iterator iter = nums.begin() + 1;
        while(iter != nums.end()) {
            if (*iter == *(iter - 1)) {
                nums.erase(iter - 1);
            } else {
                ++iter;
            }
            
        }
        return nums.size();
    }
};

int main() {
    int a[5] = {0,1,1,3,3};
    vector<int> vec(a, a + 5);
    Solution s;
    
    cout << s.removeDuplicates(vec) << endl;;
    return 0;
}