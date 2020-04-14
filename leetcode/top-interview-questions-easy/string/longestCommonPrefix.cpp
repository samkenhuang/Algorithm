#include "../../util/stl.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 0) return prefix;
        else if (strs.size() == 1) return strs[0];

        bool run = true;
        for (int i = 0; i < strs[0].size() && run; i ++) {
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[j][i] != strs[0][i]) {
                    run = false;
                    break;
                }
            }
            if (!run) break;
            prefix += strs[0][i];
        }
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> v({"flower","flow","flight"});
    cout << s.longestCommonPrefix(v) << endl;
    return 0;
}

  