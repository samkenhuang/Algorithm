#include "../util/stl.h"

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution s;
    vector<vector<int>> m2 = {{1,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,1,1,1},{1,1,1,0,0,1,1,1,1,0},{0,1,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,1,1,0},{1,1,1,1,1,1,0,1,1,1},{0,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,0,0,1,1,1},{0,1,0,1,1,0,1,1,1,1},{1,1,1,0,1,0,1,1,1,1}};
    s.updateMatrix(m2);
    vector<vector<int>> m1 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    s.updateMatrix(m1);
    return 0;
}