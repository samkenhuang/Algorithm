#include "../../util/stl.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char a = board[0][0];
        char b = board[0][1];
        int row = board.size(), col = board[0].size();
        vector<set<char>> rowSet(9), colSet(9), boxSet(9);
        vector<int> rowCount(9, 0), colCount(9, 0), boxCount(9, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(board[i][j] !=  '.') {
                    rowSet[i].insert(board[i][j]);
                    rowCount[i]++;
                    colSet[j].insert(board[i][j]);
                    colCount[j]++;
                    int index = (i / 3) * 3 + (j / 3);
                    boxSet[index].insert(board[i][j]);
                    boxCount[index]++;
                }
                
            }
        }
        for (int i = 0; i < 9; i ++) {
            if (rowSet[i].size() != rowCount[i] || 
                colSet[i].size() != colCount[i] ||
                boxSet[i].size() != boxCount[i]) {
                    return false;
            }
        }
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

  