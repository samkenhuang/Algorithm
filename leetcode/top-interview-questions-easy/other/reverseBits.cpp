#include "../../util/stl.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (uint i = 0; i < 32; i ++) {
            res = res * 2;
            res += n % 2;
            n /= 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(43261596) << endl; // 964176192
    return 0;
}