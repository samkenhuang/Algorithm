#include "../util/stl.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int spos = 0;
        for (int tpos = 0; tpos < t.length() && spos < s.length(); tpos ++) {
            if (t[tpos] == s[spos]) {
                spos ++;
            }
        }
        if (spos != s.length()) return false;
        return true;
    }
};


int main() {
    Solution s;
    s.isSubsequence("abc", "ahbgdc");
    return 0;
}