#include "../util/stl.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};


int main() {
    Solution s;
    cout << s.trailingZeroes(23);
    return 0;
}