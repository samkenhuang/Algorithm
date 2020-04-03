#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"

using namespace std;

typedef int ElemType;

int main()
{
    BiTree T = (struct BiTNode*)malloc(sizeof(struct BiTNode));
    ElemType initData[] = {1,2,3,4,5,6,7,8,9,10};
    init(T, initData, 10);
    cout << "先序遍历:";PreOrder(T);cout << endl;
    cout << "中序遍历:";InOrder(T);cout << endl;
    cout << "后序遍历:";PostOrder(T);cout << endl;
    cout << "非循环前序遍历:";PreOrderNoncyclic(T);cout << endl;
    cout << "非循环中序遍历:";InOrderNoncyclic(T);cout << endl;
    cout << "非循环后序遍历:";PostOrderNoncyclic(T);cout << endl;
    cout << "层次遍历:";LevelOrder(T);cout << endl;
    return 0;
}
