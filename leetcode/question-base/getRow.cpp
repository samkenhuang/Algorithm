#include "../util/stl.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 0; i < rowIndex + 1; i ++) {
            vector<int> row;
            for (int j = 0; j <= i; j ++) {
                if (j == 0) row.push_back(1);
                else if (j == i) row.push_back(1);
                else {
                    row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
            res.push_back(row);
        }
        return res[rowIndex];
    }
};


int main() {
    Solution s;
    s.getRow(7);
    return 0;
}