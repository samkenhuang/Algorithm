#include "../../util/stl.h"

class Solution {
private:
    vector<int> numbers;
public:
    Solution(vector<int>& nums) : numbers(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = numbers;
        for (int i = 1; i < numbers.size(); i ++) {
            // srand(time(NULL));
            int r = rand() % (i + 1);
            swap(res[r], res[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
}