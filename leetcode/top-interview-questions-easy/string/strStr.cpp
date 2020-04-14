#include "../../util/stl.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        else if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i ++) {
            for (int j = 0; j < needle.size(); j ++) {
                if (haystack[i + j] != needle[j]) break;
                if (j == needle.size() - 1) return i; 
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hello", "ll") << endl; // 2
    cout << s.strStr("hell", "ll") << endl; // 2
    cout << s.strStr("ll", "ll") << endl; // 2
    return 0;
}

  