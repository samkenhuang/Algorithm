#include "../util/stl.h"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int count[] = {a, b, c};
        int sequence[] = {0, 0, 0};
        while (true) {
            int choice = -1;

            // 每次选择最大的可能放置字符串
            int max = 0;
            for (int i = 0; i < 3; i ++) {
                if (sequence[i] < 2 && count[i] > max) {
                    max = count[i];
                    choice = i;
                }
            }
            // 没有选择，退出循环
            if (choice == -1) {
                break;
            }
            // 有选择,字符串拼凑, 修改相应的数据
            res += (char) 'a' + choice;
            for(int i = 0; i < 3; i ++) {
                if (choice == i) {
                    count[i] --;
                    sequence[i] ++;
                } else {
                    sequence[i] = 0;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    s.longestDiverseString(7, 2, 8);
    cout << 1 << endl;
    return 0;
}