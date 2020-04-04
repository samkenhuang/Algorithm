#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int>::iterator iter = prices.begin();
        int low = *iter;
        ++ iter;
        int maxProfit = 0;
        while (iter != prices.end()) {
            if (*iter > low) {
                maxProfit += (*iter - low);
            }
            low = *iter;
            ++ iter;
        }
        return maxProfit;
    }
};

int main() {
    int a[5] = {7,6,4,3,1};
    vector<int> vec(a, a + 5);
    Solution s;
    
    cout << s.maxProfit(vec) << endl; // 0
    return 0;
}