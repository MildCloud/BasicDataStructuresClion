#include <iostream>
using namespace std;

class aVLNode {
public:
    int Data;
    int Height;
    aVLNode * Left;
    aVLNode * Right;
};
typedef aVLNode * aVLTree;

aVLTree createAVLTree () {
    aVLTree NewAVLNode = new aVLNode;
    NewAVLNode->Left = nullptr;
    NewAVLNode->Right = nullptr;
    return NewAVLNode;
}

aVLTree createAVLTree (int NewData) {
    aVLTree NewAVLNode = new aVLNode;
    NewAVLNode->Data = NewData;
    NewAVLNode->Height = 0;
    NewAVLNode->Left = nullptr;
    NewAVLNode->Right = nullptr;
    return NewAVLNode;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int getHeight (aVLTree AVLTree) {
    if (AVLTree) {
        return 1 + max(getHeight(AVLTree->Left), getHeight(AVLTree->Right));
    }
    else {
        return -1;
    }
}

//aVLTree singleRightRotation (aVLTree AVLTree) {
//    aVLTree OriAVLTree = AVLTree;
//    AVLTree->Right->Left = AVLTree;
//    AVLTree->Right = OriAVLTree->Right->Left;
//    AVLTree = OriAVLTree->Right;
//    return AVLTree;
//}
//The result of the function is that the right pointer of the root is point to itself
//and original right of the root has no pointer points to, while its right point to the root.

aVLTree singleRightRotation (aVLTree AVLTree) {
    aVLTree OriRight = AVLTree->Right;//Because the value of the AVLTree->Right needs to be modified.
    AVLTree->Right = OriRight->Left;
    AVLTree->Height -= 2;
    OriRight->Left = AVLTree;
    return OriRight;
}

aVLTree singleLeftRotation (aVLTree AVLTree) {
    aVLTree OriLeft = AVLTree->Left;
    AVLTree->Left = OriLeft->Right;
    AVLTree->Height -= 2;
    OriLeft->Right = AVLTree;
    return OriLeft;
}

aVLTree doubleLeftRightRotation (aVLTree AVLTree) {
    aVLTree OriLeft = AVLTree->Left, OriLeftRight = AVLTree->Left->Right;
    AVLTree->Left = OriLeftRight->Right;
    AVLTree->Height -= 2;
    OriLeft->Right = OriLeftRight->Left;
    OriLeft->Height--;
    OriLeftRight->Right = AVLTree;
    OriLeftRight->Left = OriLeft;
    OriLeftRight->Height++;
    return OriLeftRight;
    //The modification order is from the below of the new tree to the root of the new tree.
}

aVLTree doubleRightLeftRotation (aVLTree AVLTree) {
    aVLTree OriRight = AVLTree->Right, OriRightLeft = AVLTree->Right->Left;
    AVLTree->Right = OriRightLeft->Left;
    AVLTree->Height -= 2;
    OriRight->Left = OriRightLeft->Right;
    OriRight->Height--;
    OriRightLeft->Right = OriRight;
    OriRightLeft->Left = AVLTree;
    OriRightLeft->Height++;
    return OriRightLeft;
}

aVLTree insertAVLTree (aVLTree AVLTree, int NewData) {
    if (!AVLTree) {
        AVLTree = createAVLTree(NewData);
    }
    else {
        if (NewData < AVLTree->Data) {
            AVLTree->Left = insertAVLTree(AVLTree->Left, NewData);
            AVLTree->Height = getHeight(AVLTree);
            if ((getHeight(AVLTree->Left) - getHeight(AVLTree->Right) > 1)) {
                if (getHeight(AVLTree->Left->Left) > getHeight(AVLTree->Left->Right)) {
                    AVLTree = singleLeftRotation (AVLTree);
                }
                else {
                    AVLTree = doubleLeftRightRotation(AVLTree);
                }
            }
        }
        else if (NewData > AVLTree->Data) {
            AVLTree->Right = insertAVLTree(AVLTree->Right, NewData);
            AVLTree->Height = getHeight(AVLTree);
            if (getHeight(AVLTree->Right) - getHeight(AVLTree->Left) > 1) {
                if (getHeight(AVLTree->Right->Right) > getHeight(AVLTree->Right->Left)) {
                    AVLTree = singleRightRotation(AVLTree);
                }
                else {
                    AVLTree = doubleRightLeftRotation(AVLTree);
                }
            }
        }
    }
    return AVLTree;
}

int main() {
    aVLTree AVLTree1 = createAVLTree(0);
    AVLTree1->Left = createAVLTree(-1);
    AVLTree1->Right = createAVLTree(2);
    AVLTree1->Right->Left = createAVLTree(1);
    AVLTree1->Right->Right = createAVLTree(3);
    AVLTree1->Right->Right->Right = createAVLTree(4);
    AVLTree1 = singleRightRotation(AVLTree1);

    aVLTree  AVLTree2 = createAVLTree(0);
    AVLTree2->Right = createAVLTree(2);
    AVLTree2->Right->Left = createAVLTree(1);
    AVLTree2->Right->Right = createAVLTree(3);
    AVLTree2->Left = createAVLTree(-5);
    AVLTree2->Left->Left = createAVLTree(-6);
    AVLTree2->Left->Right = createAVLTree(-3);
    AVLTree2->Left->Right->Right = createAVLTree(-2);
    AVLTree2->Left->Right->Left = createAVLTree(-4);
    AVLTree2->Left->Right->Right->Right = createAVLTree(-1);
    AVLTree2->Left->Left->Left = createAVLTree(-7);
    AVLTree2 = doubleLeftRightRotation(AVLTree2);

    aVLTree AVLTree3 = nullptr;
    AVLTree3 = insertAVLTree(AVLTree3, 0);
    AVLTree3 = insertAVLTree(AVLTree3, -1);
    AVLTree3 = insertAVLTree(AVLTree3, 3);
    AVLTree3 = insertAVLTree(AVLTree3, 4);
    AVLTree3 = insertAVLTree(AVLTree3, 1);
    AVLTree3 = insertAVLTree(AVLTree3, 2);

    cout << getHeight(AVLTree1) << getHeight(AVLTree2) << getHeight(AVLTree3) << endl;

    aVLTree AVLTree4 = nullptr;
    AVLTree4 = insertAVLTree(AVLTree4, 0);
    AVLTree4 = insertAVLTree(AVLTree4, -6);
    AVLTree4 = insertAVLTree(AVLTree4, -8);
    AVLTree4 = insertAVLTree(AVLTree4, -9);
    AVLTree4 = insertAVLTree(AVLTree4, -10);
    AVLTree4 = insertAVLTree(AVLTree4, -7);

    return 0;
}

//Sle code in ZOJ.
//typedef struct AVLNode *Position;
//typedef Position AVLTree; /* AVL树类型 */
//struct AVLNode{
//    ElementType Data; /* 结点数据 */
//    AVLTree Left;     /* 指向左子树 */
//    AVLTree Right;    /* 指向右子树 */
//    int Height;       /* 树高 */
//};
//
//int Max ( int a, int b )
//{
//    return a > b ? a : b;
//}
//
//AVLTree SingleLeftRotation ( AVLTree A )
//{ /* 注意：A必须有一个左子结点B */
//  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
//
//    AVLTree B = A->Left;
//    A->Left = B->Right;
//    B->Right = A;
//    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
//    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
//
//    return B;
//}
//
//AVLTree DoubleLeftRightRotation ( AVLTree A )
//{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
//  /* 将A、B与C做两次单旋，返回新的根结点C */
//
//    /* 将B与C做右单旋，C被返回 */
//    A->Left = SingleRightRotation(A->Left);
//    /* 将A与C做左单旋，C被返回 */
//    return SingleLeftRotation(A);
//}
//
///*************************************/
///* 对称的右单旋与右-左双旋请自己实现 */
///*************************************/
//
//AVLTree Insert( AVLTree T, ElementType X )
//{ /* 将X插入AVL树T中，并且返回调整后的AVL树 */
//    if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
//        T = (AVLTree)malloc(sizeof(struct AVLNode));
//        T->Data = X;
//        T->Height = 0;
//        T->Left = T->Right = NULL;
//    } /* if (插入空树) 结束 */
//
//    else if ( X < T->Data ) {
//        /* 插入T的左子树 */
//        T->Left = Insert( T->Left, X);
//        /* 如果需要左旋 */
//        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
//            if ( X < T->Left->Data )
//               T = SingleLeftRotation(T);      /* 左单旋 */
//            else
//               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
//    } /* else if (插入左子树) 结束 */
//
//    else if ( X > T->Data ) {
//        /* 插入T的右子树 */
//        T->Right = Insert( T->Right, X );
//        /* 如果需要右旋 */
//        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
//            if ( X > T->Right->Data )
//               T = SingleRightRotation(T);     /* 右单旋 */
//            else
//               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
//    } /* else if (插入右子树) 结束 */
//
//    /* else X == T->Data，无须插入 */
//
//    /* 别忘了更新树高 */
//    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
//
//    return T;
//}
//The remaining questions:
//1, Why not use GetHeight(T)?
//2, Why not use ++ -- in the four rotations functions?
//3, Can we update the height of the node immediately after we link the left node or the right node?