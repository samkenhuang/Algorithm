#include "../../util/stl.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }
        if (s.empty()) return NULL;
        ListNode* res = new ListNode(s.top());s.pop();
        ListNode* curr = res;
        while(!s.empty()) {
            ListNode* node = new ListNode(s.top());s.pop();
            curr->next = node;
            curr = curr->next;
        }
        return res;
    }
};

int main() {
    Solution s;
    ListNode* node = new ListNode({1,2,3,4});
    s.reverseList(node);
}