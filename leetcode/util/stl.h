#include <vector>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
void vectorD2(vector<vector<T>> &v, const T **arr, int row, int col) {
    for(int i = 0; i < row; i ++) {
        vector<T> tmp;
        for(int j = 0; j < col; j ++) {
            tmp.push_back(arr[i][j]);
        }
        v.push_back(tmp);
    }
}

template<typename T>
void vectorD1(vector<T> &v, T arr[], int len) {
    for(int i = 0; i < len; i ++) {
        v.push_back(arr[i]);
    }
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(vector<int> v) {
        vector<int>::iterator it = v.begin();
        val = v[0]; ++ it;
        ListNode *curr = this;
        while (it != v.end()) {
            ListNode* node = new ListNode(*it);
            curr->next = node;
            curr = curr->next;
            ++ it;
        }
        curr->next = NULL;
    }
};

/**
 * 二叉树 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(vector<int> v) : val(v[0]) { // 通过顺序遍历数组构建二叉树
        vector<int> leftv, rightv;
        int currentIndex = 1, level = 2;
        while (currentIndex < v.size()) {
            for (int pivot = currentIndex + level / 2; currentIndex < pivot && currentIndex < v.size(); currentIndex ++) {
                leftv.push_back(v[currentIndex]);
            }
            for (int pivot = currentIndex + level / 2; currentIndex < pivot && currentIndex < v.size(); currentIndex ++) {
                rightv.push_back(v[currentIndex]);
            }
            level *= 2;
        }
        // 会有警告, 目前没想好怎么处理
        left = leftv.size() > 0 && leftv[0] != NULL ? new TreeNode(leftv) : NULL;
        right = rightv.size() > 0 && rightv[0] != NULL ? new TreeNode(rightv) : NULL;
    }
 };