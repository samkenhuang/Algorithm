#include "../util/stl.h"

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string::iterator iter = s.begin();
        string res = "";
        string word = "";
        while (iter != s.end()) {
            if(*iter != ' ') {
                word += *iter;
            } else {
                if(word.size() > 0) v.push_back(word);
                word= "";
            }
            iter ++;
        }
        if(word.size() > 0) v.push_back(word);
        for(int i=v.size()-1; i >= 0; i --) {
            res += v[i];
            if(i != 0) res += " ";
        }
        return res;
    }
};


int main() {
    Solution s;
    s.reverseWords("a good   example");
    return 0;
}