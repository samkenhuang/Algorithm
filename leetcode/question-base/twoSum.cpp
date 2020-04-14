#include "../util/stl.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                res = {low + 1, high + 1}; break;
            } else if (numbers[low] + numbers[high] < target) {
                low++;
            } else {
                high--;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    s.twoSum(v, 9);
    return 0;
}