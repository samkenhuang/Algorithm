#include "../../util/stl.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i ++) {
            char t = s[i];
            s[i] = s[size - 1 - i];
            s[size - 1 - i] = t;
        }
    }
};

int main() {
    Solution s;
    vector<char> v = {'h','e','l','l','o'};
    s.reverseString(v);
    return 0;
}

  