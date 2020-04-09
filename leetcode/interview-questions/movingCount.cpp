#include "../util/stl.h"

int digitsSum(int n) {
    int res = 0;
    while(n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int posNum = 0;
        int matrix[100][100] = {0};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (((i > 0 && matrix[i-1][j] == 1) || (j > 0 && matrix[i][j-1] == 1) || (i == 0 && j ==0))
                    && digitsSum(i) + digitsSum(j) <= k) {
                    matrix[i][j] = 1;
                    posNum ++; 
                }
            }
        }
        return posNum;
    }
};

int main() {
    Solution s;
    cout << s.movingCount(38, 15, 9) << endl; // 135
    cout << s.movingCount(16, 8, 4) << endl; // 15
    return 0;
}