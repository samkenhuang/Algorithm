#include "../../util/stl.h"

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int res = 0;
        bool positive = x > 0 ? true : false;
        while(x != 0) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && x % 10 < -8)) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.reverse(123);
    s.reverse(-123);
    s.reverse(120);
    s.reverse(2147483647);
    return 0;
}

  