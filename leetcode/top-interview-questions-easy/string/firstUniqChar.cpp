#include "../../util/stl.h"

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> stag(s.size(), 0);
        for (int i = 0; i < s.size(); i ++) {
            if (stag[i] == 0) {
                for (int j = i + 1; j < s.size(); j ++) {
                    if (s[i] == s[j]) {
                        stag[i] = 1;
                        stag[j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < s.size(); i ++) {
            if (stag[i] == 0) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;; // 0
    cout << s.firstUniqChar("loveleetcode") << endl; // 2
    cout << s.firstUniqChar("ll22") << endl; // -1
    return 0;
}

  