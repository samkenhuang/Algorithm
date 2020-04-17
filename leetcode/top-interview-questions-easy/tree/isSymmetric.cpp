#include "../../util/stl.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left != NULL && right != NULL && left->val == right->val) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        return false;
    }
};

int main() {
    Solution s;
    TreeNode* t = new TreeNode({1,2,2,3,4,4,3});
    cout << s.isSymmetric(t) << endl;
    TreeNode* t1 = new TreeNode({1,2,2,NULL,3,NULL,3});
    cout << s.isSymmetric(t1) << endl;
    TreeNode* t2 = new TreeNode({});
    cout << s.isSymmetric(t2) << endl;
    return 0;
}