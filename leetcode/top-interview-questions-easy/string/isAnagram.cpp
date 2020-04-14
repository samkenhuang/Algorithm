#include "../../util/stl.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int size = t.size();
        map<char, int> tmap;
        for (int i = 0; i < size; i ++) {
            map<char, int>::const_iterator it = tmap.find(t[i]);
            if (it == tmap.end()) tmap[t[i]] = 1;
            else tmap[t[i]] += 1;
        }
        for (int i = 0; i < size; i++) {
            map<char, int>::const_iterator it = tmap.find(s[i]);
            if (it == tmap.end()) return false;
            else {
                tmap[s[i]] -= 1;
                if (tmap[s[i]] < 0) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isAnagram("aacc", "ccac") << endl; // false
    cout << s.isAnagram("anagram", "nagaram") << endl; // true
    cout << s.isAnagram("rat", "car") << endl; // false;
    return 0;
}

  