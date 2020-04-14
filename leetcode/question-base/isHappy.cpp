#include "../util/stl.h"

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true; else if (n == 0) return false;
        set<int> occured;
        while(occured.count(n) == 0) {
            occured.insert(n);
            int x = n; n = 0;
            while(x != 0) {
                n += pow(x % 10, 2);
                x = x / 10;
            }
        }
        if (n == 1) return true;
        return false;
    }
};

int main() {
    Solution s;
    s.isHappy(2);
    return 0;
}