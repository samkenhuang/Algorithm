#include "../util/stl.h"

class Solution {
public:
    // K > 0, N > 0
    int superEggDrop(int K, int N) {
        if (K == 1) return N;
        if (N == 1) return 1;
        vector<vector<int>> v(K + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= K; i ++) {
            for (int j = 1; j <= N; j++) {
                if (i == 1) v[i][j] = j;
                else if (j == 1 || j == 2) v[i][j] = j;
                else {
                    // 此处可以循环查找得到对应的层数
                    // 由于一个单调递增，一个递减, 所以可以二分查找加快速度
                    int low = 1, high = j;
                    int floor = (low + high) / 2;
                    while (low + 1 < high) {
                        if (v[i -1][floor - 1] > v[i][j - floor]) {
                            high = floor;
                            floor = (low + high) / 2;
                        } else {
                            low = floor;
                            floor = (low + high) / 2;
                        }
                    }
                    // 找到前后相等的floor，可以尝试往前前进一位，以防特殊情况
                    if(v[i -1][floor - 2] == v[i][j - floor + 1]) floor --;
                    v[i][j] = 1 + max(v[i - 1][floor - 1], v[i][j - floor]);
                }
            }
        }
        return v[K][N];
    }
};


int main() {
    Solution s;
    cout << s.superEggDrop(8, 10000) << endl; // 14
    cout << s.superEggDrop(2, 6) << endl; // 3
    cout << s.superEggDrop(2, 9) << endl; // 4
    cout << s.superEggDrop(3, 14) << endl; // 4
    cout << s.superEggDrop(10, 100) << endl; // 7
    return 0;
}