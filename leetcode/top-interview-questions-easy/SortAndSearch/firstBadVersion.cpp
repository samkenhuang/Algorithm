#include "../../util/stl.h"

class Solution {
private:
    bool isBadVersion(int v) {
        if (v >=1702766719) return true;
        return false;
    }
public:
    int firstBadVersion(int n) {
        // 二分查找
        int low = 1, high = n;
        while (low < high) {
            int mid = ((long)low + (long)high) / 2;
            if (isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution s;
    // cout << s.firstBadVersion(5) << endl;
    cout << s.firstBadVersion(2126753390) << endl;
    return 0;
}

