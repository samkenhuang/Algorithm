#include "../util/stl.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = INT_MAX;
        vector<int>::iterator iter = prices.begin();
        for (; iter != prices.end(); ++iter) {
            if(lowestPrice > *iter) lowestPrice = *iter;
            int currentProfit = *iter - lowestPrice;
            maxProfit = currentProfit > maxProfit ? currentProfit : maxProfit;
        }
        return maxProfit;
    }
};

int main() {
    Solution s;
    vector<int> v;
    int arr[6] = {7,1,5,3,6,4};
    vectorD1(v, arr, 6);
    cout << s.maxProfit(v) << endl; // 135
    return 0;
}