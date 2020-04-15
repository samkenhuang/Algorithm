#include "../../util/stl.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* t = new TreeNode({3,9,20,NULL,NULL,15,7});
    cout << s.maxDepth(t) << endl; // 3
}