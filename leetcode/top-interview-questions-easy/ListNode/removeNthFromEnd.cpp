#include "../../util/stl.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* preN = curr;
        while(n--) curr = curr->next;
        if (curr == NULL) return head->next;
        while(curr->next != NULL) {
            curr = curr->next;
            preN = preN->next;
        }
        preN->next == NULL ? preN = NULL : preN->next = preN->next->next;
        return head;
    }
};

int main() {
    Solution s;
    ListNode* node2 = new ListNode({1});
    s.removeNthFromEnd(node2, 1);
    ListNode* node1 = new ListNode({1,2,3});
    s.removeNthFromEnd(node1, 3);
    ListNode* node = new ListNode({1,2,3,4, 5});
    s.removeNthFromEnd(node, 1);
    s.removeNthFromEnd(node, 2);
}