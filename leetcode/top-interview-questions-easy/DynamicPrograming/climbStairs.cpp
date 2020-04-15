#include "../../util/stl.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> v = {1, 2};
        for (int i = 2; i < n; i ++) {
            v.push_back(v[i - 1] + v[i - 2]);
        }
        return v[n - 1];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(4) << endl;
    return 0;
}

