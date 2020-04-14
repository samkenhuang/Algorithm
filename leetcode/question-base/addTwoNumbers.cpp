#include "../util/stl.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* curr1 = l1; 
        ListNode* curr2 = l2;
        while (curr1 != NULL) {
            s1.push(curr1->val);
            curr1 = curr1->next;
        }
        while (curr2 != NULL) {
            s2.push(curr2->val);
            curr2 = curr2->next;
        }

        vector<int> v;
        int digit = 0;
        while (!s1.empty() || !s2.empty()) {
            int a = 0, b = 0;
            if (!s1.empty()) {
                a = s1.top(); s1.pop();
            }
            if (!s2.empty()) {
                b = s2.top(); s2.pop();
            }
            v.push_back((a + b + digit) % 10);
            digit = (a + b + digit > 9) ? 1 : 0;
        }
        if (digit == 1) v.push_back(digit);
        // 根据v倒序输出ListNode
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        for (int i = v.size() - 1; i >= 0; i --) {
            ListNode* node = new ListNode(v[i]);
            curr->next = node;
            curr = curr->next;
        }
        return res->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode({7, 2, 4, 3});
    ListNode* l2 = new ListNode({5, 6, 4});
    s.addTwoNumbers(l1, l2);
    return 0;
}