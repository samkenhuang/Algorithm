// 旋转图像
#include "../../util/stl.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> copy = matrix;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = copy[size - 1 - j][i];
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7, 8, 9}};
    s.rotate(v);
    vector<vector<int>> v1 = {{5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16}};
    s.rotate(v1);
    cout << 1 << endl;
    return 0;
}

  