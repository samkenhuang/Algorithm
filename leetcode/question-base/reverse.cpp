#include "../util/stl.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0) {
            int reminder = x % 10;
            x = x / 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && reminder > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && reminder < -8)) return 0;
            res = res * 10 + reminder;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.reverse(1534236469);
    // s.reverse(123);
    // s.reverse(-123);
    // s.reverse(120);
    cout << 1 << endl;
    return 0;
}