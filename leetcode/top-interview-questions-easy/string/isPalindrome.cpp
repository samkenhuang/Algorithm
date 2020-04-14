#include "../../util/stl.h"

class Solution {
private:
    bool validDigit(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool equal(char c1, char c2) {
        if (c1 == c2) return true;
        if (((c1 >= 'a' && c1 <= 'z' && c2 >= 'A' && c2 <= 'Z' && (c2 - c1 == 'A' - 'a')) ||
            (c2 >= 'a' && c2 <= 'z' && c1 >= 'A' && c1 <= 'Z' && (c1 - c2 == 'A' - 'a')))) {
                return true;
            } 
        return false;
    }
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int low = 0, high = s.size() - 1;
        while (low < high) {
            while (!validDigit(s[low]) && low < high) low ++;
            while (!validDigit(s[high]) && low < high) high --;
            if (equal(s[low], s[high])) {
                low ++; high --;
            } else return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(".,") << endl;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl; // true
    cout << s.isPalindrome("race a car") << endl; // false 
    return 0;
}

  