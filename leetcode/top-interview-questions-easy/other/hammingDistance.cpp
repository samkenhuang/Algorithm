#include "../../util/stl.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x != 0 || y != 0) {
            if (x % 2 != y % 2) count++;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(-1, 4) << endl; // 2
    return 0;
}