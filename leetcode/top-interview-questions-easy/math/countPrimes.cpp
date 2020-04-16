#include "../../util/stl.h"

class Solution {
public:
    int countPrimes(int n) {
        vector<int> primeList;
        vector<int> checkList(n + 1 , 0);
        for (int i = 2; i < n; i ++) {
            if (checkList[i] == 0) {
                primeList.push_back(i);
                int times = 2;
                while (i * times <= n) {
                    checkList[i * times] = 1;
                    times ++;
                }
            }
        }
        return primeList.size();
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(499979) << endl; // 41537
    cout << s.countPrimes(10) << endl; // 4
    return 0;
}