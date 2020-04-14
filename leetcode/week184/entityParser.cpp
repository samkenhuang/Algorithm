#include "../util/stl.h"
#include <regex>

class Solution {
private:
public:
    string entityParser(string text) {
        string res = "";
        string::iterator it = text.begin();
        for (; it != text.end(); it++) {
            if (*it == '&') {
                string m6 = text.substr(it - text.begin(), 6), m7 = text.substr(it - text.begin(), 7), m5 = text.substr(it - text.begin(), 5), m4 = text.substr(it - text.begin(), 4);
                if (m6 == "&quot;") {
                    res += "\""; it += 5;
                } else if (m6 == "&apos;") {
                    res += "'"; it += 5;
                } else if (m5 == "&amp;") {
                    res += "&"; it += 4;
                } else if (m4 == "&gt;") {
                    res += ">"; it += 3;
                } else if (m4 == "&lt;") {
                    res += ">"; it += 3;
                } else if (m7 == "&frasl;") {
                    res += "/"; it += 6;
                } else {
                    res += *it;
                }
            } else {
                res += *it;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.entityParser("&amp; is an HTML entity but &ambassador; is not.&quot;&apos;ppp&apos;");
    cout << 1 << endl;
    return 0;
}