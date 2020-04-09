#include "../util/stl.h"

class Solution {
public:
    int sumNums(int n) {
        int res = 0;
        n && (res = n + sumNums(n - 1));
        return res;
    }
};

int main() {
    Solution s;
    cout << s.sumNums(7) << endl;
    return 0;
}