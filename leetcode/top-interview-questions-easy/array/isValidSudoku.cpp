#include "../../util/stl.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return true;
    }
};

int main() {
    vector<vector<char>> vec1;
    const char *c1[9] = {
        "53..7....","6..195...",".98....6.",
        "8...6...3","4..8.3..1","7...2...6",
        ".6....28.","...419..5","....8..79"
    };
    vectorD2(vec1, c1, 9, 9);

    Solution s;
    s.isValidSudoku(vec1);
    cout << 1 << endl;
    return 0;
}

  