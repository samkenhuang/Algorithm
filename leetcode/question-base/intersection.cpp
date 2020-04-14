#include "../util/stl.h"

class Solution {
private:
    bool between(double t, int a, int b) {
        return (t >= a && t <= b) || (t >= b && t <= a);
    }
    // 重叠线段所求的坐标值为第二大的数字坐标值
    double findPos(int a, int b, int c, int d) {
        vector<int> v({a, b, c, d});
        sort(v.begin(), v.end());
        return v[1];
    }
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector<double> inter;
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int X1 = start2[0], Y1 = start2[1], X2 = end2[0], Y2 = end2[1];
        // 下列为表达式
        int a1 = y2 - y1, b1 = x1 - x2, c1 = x1 * y2 - x2 * y1;
        int a2 = Y2 - Y1, b2 = X1 - X2, c2 = X1 * Y2 - X2 * Y1;
        int D = a1 * b2 - a2 * b1, y = a1 * c2 - a2 * c1, x = b2 * c1 - b1 * c2;
        if (D != 0) {
            double interX = x != 0 ? (double)x / D : 0, interY = y != 0 ? (double)y / D : 0;
            if (between(interX, x1, x2) && between(interY, y1, y2) &&
                between(interX, X1, X2) && between(interY, Y1, Y2)) {
                    inter = {interX, interY};
                }
        } else {
            // 分为平行与重叠, 先假定其都为线段
            // 直线重叠且平行于x轴
            if (a1 == 0 && c1 * b2 == c2 * b1) {
                if(between(x1, X1, X2) || between(x2, X1, X2) || between(X1, x1, x2) || between(X2, x1, x2)) {
                    inter = { findPos(x1, x2, X1, X2), (double)y1 };
                }
            } else if (b1 == 0 && c1 * a2 == c2 * a1) { // 直线重叠且平行于y轴
                if(between(y1, Y1, Y2) || between(y2, Y1, Y2) || between(Y1, y1, y2) || between(Y2, y1, y2)) {
                    inter = { (double)x1, findPos(y1, y2, Y1, Y2)};
                }
            } else if (c1 * b2 == c2 * b1){ // 不平行于坐标轴且重叠
                if(between(x1, X1, X2) || between(x2, X1, X2) || between(X1, x1, x2) || between(X2, x1, x2)) {
                    inter = { findPos(x1, x2, X1, X2), findPos(y1, y2, Y1, Y2)};
                }
            }
        }
        return inter;
    }
};


int main() {
    Solution s;
    // vector<int> start1({0, 0}), end1({1, 0});
    // vector<int> start2({1, 1}), end2({0, -1});
    // s.intersection(start1, end1, start2, end2); // {0.5, 0}
    // vector<int> start3({0, 0}), end3({3, 3});
    // vector<int> start4({1, 1}), end4({2, 2});
    // s.intersection(start3, end3, start4, end4); // {1, 1}
    vector<int> start5({0, 0}), end5({1, 1});
    vector<int> start6({1, 0}), end6({2, 1});
    s.intersection(start5, end5, start6, end6); // {}
    return 0;
}