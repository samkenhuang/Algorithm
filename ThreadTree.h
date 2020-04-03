#ifndef BINARYTREE_THREADTREE_H
#define BINARYTREE_THREADTREE_H

#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    /**
     * 标志域
     * ltag 0 lchild域指示节点的左孩子
     *      1 lchild域指示节点的前驱
     * rtag 0 lchild域指示节点的右孩子
     *      1 lchild域指示节点的后驱
     */
    int ltag, rtag;
} ThreadNode, *ThreadTree;

#endif //BINARYTREE_THREADTREE_H
