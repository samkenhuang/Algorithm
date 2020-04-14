#include "../util/stl.h"

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // sort(words.begin(), words.end(), cmp);
        vector<int> matchPos(words.size(), 0);
        vector<string> match;
        for (int i = 0; i < words.size(); i ++) {
            if (matchPos[i] == 0) {
                for (int j = 0; j < words.size(); j ++) {
                    if (matchPos[j] == 0 && j != i) {
                        std::size_t found = words[i].find(words[j]);
                        if (found!=std::string::npos) {
                            matchPos[j] = 1; match.push_back(words[j]);
                        }
                    }
                }
            }   
        }
        return match;
    }
};

int main() {
    Solution s;
    vector<string> words({"mass","as","hero","superhero"});
    s.stringMatching(words);
    vector<string> words1({"blue","green","bu"});
    s.stringMatching(words1);
    cout << 1 << endl;
    return 0;
}