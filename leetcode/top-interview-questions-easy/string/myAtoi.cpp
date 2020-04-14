#include "../../util/stl.h"

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool positive = true;
        int i = 0;
        // 先读取正负标志符号
        while (i < str.length()) {
            if (str[i] == '-') {
                positive = false; i ++; break;
            } else if (str[i] == '+') {
                i ++; break;
            } else if (str[i] >= '0' && str[i] <= '9') {
                res += str[i] - '0'; i ++; break;
            } else if (str[i] != ' ') {
                return 0;
            }
            i ++;
        }
        // 继续操作后面的数字
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            if (positive && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' >= 7))) return INT_MAX;
            if (!positive && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' >= 8))) return INT_MIN;
            res *= 10;
            res += str[i] - '0';
            i++;
        }
        return (positive ? 1 : -1) * res;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("-2147483648") << endl; // -2147483648
    cout << s.myAtoi("+1") << endl; // 1
    cout << s.myAtoi("4193 with words") << endl; // 4193
    cout << s.myAtoi("   -42") << endl; // -42
    cout << s.myAtoi("words and 987") << endl; // 0 
    cout << s.myAtoi("-91283472332") << endl; // -2147483648
    return 0;
}

  