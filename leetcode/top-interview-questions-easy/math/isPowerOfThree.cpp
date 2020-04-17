#include "../../util/stl.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        while(n % 3 == 0) {
            n /= 3;
        }
        if (n == 1) return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(45) << endl; // false
    return 0;
}