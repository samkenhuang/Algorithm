#include "../util/stl.h"

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        while (s != "1") {
            res += 1;
            if (s[s.length() - 1] == '0') {
                s.erase(s.length() - 1, 1);
            } else {
                int flag = 1;
                for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++ it) {
                    *it += flag;
                    if (*it == '2') {
                        flag = 1; *it = '0';
                    } else {
                        flag = 0;
                    }
                }
                if (flag == 1) {
                    s.insert(0, "1");
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.numSteps("1111011110000011100000110001011011110010111001010111110001");
    cout << 1 << endl;
    return 0;
}