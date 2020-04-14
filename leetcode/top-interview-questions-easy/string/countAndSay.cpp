#include "../../util/stl.h"

class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for (int i = 1; i < n; i ++) {
            string tmp = "";
            int count = 1, number = curr[0] - '0';
            for (int j = 1; j < curr.length(); j ++) {
                if (curr[j] == curr[j - 1]) count ++;
                else {
                    tmp += to_string(count) + to_string(number);
                    count = 1; number = curr[j] - '0';
                }
            }
            tmp += to_string(count) + to_string(number);
            curr = tmp;
        }
        
        return curr;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(5) << endl;
    return 0;
}

  