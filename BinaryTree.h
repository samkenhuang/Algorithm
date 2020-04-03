#ifndef BINARYTREE_BITREE_H
#define BINARYTREE_BITREE_H

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

typedef int ElemType;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/*
 * 访问单个二叉树结点
 */
ElemType visit(BiTree T) {
    cout << T->data << " ";
    return T->data;
}

/**
 * 遍历二叉树
 * @param T 二叉树根节点
 */
void PreOrder(BiTree T) {
    if(T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T) {
    if(T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T) {
    if(T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
/**
 * 遍历二叉树 - 非递归方法
 * @param T 二叉树根节点
 */
void PreOrderNoncyclic(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {
            visit(p);
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();s.pop();
            p = p->rchild;
        }
    }
}
void InOrderNoncyclic(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();s.pop();
            visit(p);
            p = p->rchild;
        }
    }
}
void PostOrderNoncyclic(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    BiTree r = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            } else { // 记录上次出栈的节点，防止重复访问
                r = s.top();
                visit(r);
                s.pop();
                p = NULL;
            }
        }

    }
}

/**
 * 层次遍历
 */
void LevelOrder(BiTree T) {
    queue<BiTree> q;
    BiTree t;
    q.push(T);
    while (!q.empty()) {
        t = q.front(); q.pop();
        visit(t);
        if (t->lchild) q.push(t->lchild);
        if (t->rchild) q.push(t->rchild);
    }
}


/**
 * 顺序存储结构初始化二叉树
 * 采用递归方式
 * @param T
 * @param data
 * @param len
 * @param currentPos 放入节点位置
 */
void init(BiTree &T, ElemType data[], int len, int currentPos = 1) {
    if (currentPos <= len && currentPos > 0) {
        if (data[currentPos - 1] == -1) {
            T = NULL;
        } else {
            BiTree node = (struct BiTNode*)malloc(sizeof(struct BiTNode));
            node->data = data[currentPos - 1];
            node->rchild = node->lchild = NULL;
            T = node;
            init(node->lchild, data, len, currentPos * 2);
            init(node->rchild, data, len, currentPos * 2 + 1);
        }
    } else {
        T = NULL;
    }
}



#endif //BINARYTREE_BITREE_H
