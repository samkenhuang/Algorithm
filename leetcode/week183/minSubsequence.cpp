#include "../util/stl.h"

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        int sumAll = 0,sum = 0;
        sort(nums.begin(), nums.end()); // 排序
        vector<int>::reverse_iterator iter = nums.rbegin();
        for (; iter != nums.rend(); ++iter) {
            sumAll += *iter;
        }
        for (iter = nums.rbegin(); iter != nums.rend() && sum <= sumAll / 2; ++iter) {
            res.push_back(*iter);
            sum += *iter;
        }
        return res;
    }
};

int main() {
    int a[5] = {6};
    vector<int> vec1(a, a + 1);
    Solution s;
    s.minSubsequence(vec1);
    cout << 1 << endl;
    return 0;
}

  