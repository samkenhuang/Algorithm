#include "../../util/stl.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            if (n % 2 == 1) res ++;
            n /= 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.hammingWeight(11);
}