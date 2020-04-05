#include "../util/stl.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        vector<int>::iterator iter = height.begin();
        for (; iter != height.end() - 1; ++iter) {
            int gap = (*iter != 0 && (area / *iter) > 1) ? (area / *iter) : 1;
            vector<int>::iterator it = iter + gap;
            if(gap < height.end() - iter) {
                while(it != height.end()) {
                    int areat = min(*it, *iter) * (it - iter);
                    area = area < areat ? areat : area;
                    it++;
                }
            }
        }
        return area;
    }
};

int main() {
    Solution s;
    vector<int> v;
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vectorD1(v, a, 9);
    s.maxArea(v);
    cout << 1 << endl;
    return 0;
}