#include "../../util/stl.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

int main() {
    Solution s;
    TreeNode* t = new TreeNode({5,1,4,NULL,NULL,3,6});
    TreeNode* t1 = new TreeNode({2,1,3});
    cout << s.isValidBST(t) << endl; // false
    cout << s.isValidBST(t1) << endl; // true
    return 0;
}