#include "../../util/stl.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    Solution s;
    ListNode* node = new ListNode({1,2,3,4});
    s.deleteNode(node);
}