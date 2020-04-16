#include "../../util/stl.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int maxP = 0, min = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            if (min > prices[i]) min = prices[i];
            int curr = prices[i] - min;
            if (curr > maxP) maxP = curr;
        }
        return maxP;
    }
};

int main() {
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    cout << s.maxProfit(v) << endl; // 5
    vector<int> v1 = {};
    cout << s.maxProfit(v1) << endl;
    return 0;
}