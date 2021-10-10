#include <iostream>
using namespace std;

class treeNode {
public:
    int Data;
    treeNode * Left;
    treeNode * Right;
};
typedef treeNode * binaryTree;

binaryTree createBinary () {
    binaryTree BinaryTree = new treeNode;
    BinaryTree->Left = nullptr;
    BinaryTree->Right = nullptr;
    return BinaryTree;
}

//void preOrderTraversal (binaryTree BinaryTree) {
//    cout << BinaryTree->Data;
//    if (BinaryTree->Left) {preOrderTraversal(BinaryTree->Left);}
//    if (BinaryTree->Right) {preOrderTraversal(BinaryTree->Right);}
//    //Need to mention that in such structure, where there is no if
//    //condition judgement before the stdout, the other two conditions
//    //can't be BinaryTree.
//    //Otherwise, it will appear that nullptr->Data and cause 139 error
//}
//
//void inOrderTraversal (binaryTree BinaryTree) {
//    if (BinaryTree->Left) {inOrderTraversal(BinaryTree->Left);}
//    cout << BinaryTree->Data;
//    if (BinaryTree->Right) {inOrderTraversal(BinaryTree->Right);}
//}
//
//void postOrderTraversal (binaryTree BinaryTree) {
//    if (BinaryTree->Left) {postOrderTraversal(BinaryTree->Left);}
//    if (BinaryTree->Right) {postOrderTraversal(BinaryTree->Right);}
//    cout << BinaryTree->Data;
//}
//
////When using recursion for a non-void function, a variable needs to use to access return value.
//binaryTree insert (binaryTree BST, int NewData) {
//    if (BST && NewData < BST->Data) {
//        BST->Left = insert(BST->Left, NewData);
//    }
//    if (BST && NewData > BST->Data) {
//        BST->Right = insert(BST->Right, NewData);
//    }
//    if (!BST) {
//        //Need to emphasize that only the nullptr should use the following function,
//        //otherwise, all the other BST(BST, BST->Left, BST->Left->Left...).
//        //Hence, the result of leaving out the condition is that Data of the 1st BST, the root,
//        //will continuously be modified by the NewData;
//        binaryTree NewTreeNode = createBinary();
//        NewTreeNode->Data = NewData;
//        BST = NewTreeNode;
//    }
//    return BST;
//}

void preOrderTraversal (binaryTree BT) {
    if (BT) {
        cout << BT->Data;
        preOrderTraversal(BT->Left);
        preOrderTraversal(BT->Right);
    }
}

void inOrderTraversal (binaryTree BT) {
    if (BT) {
        inOrderTraversal(BT->Left);
        cout << BT->Data;
        inOrderTraversal(BT->Right);
    }
}

void postOrderTraversal (binaryTree BT) {
    if (BT) {
        postOrderTraversal(BT->Left);
        postOrderTraversal(BT->Right);
        cout << BT->Data;
    }
}

binaryTree insertBST (binaryTree BST, int NewData) {
    if (!BST) {
        BST = createBinary();
        BST->Data = NewData;
    }
    else {
        if (NewData < BST->Data) {
            BST->Left = insertBST(BST->Left, NewData);
            //Use pointer to link the tree again after the recursion.
        }
        if (NewData > BST->Data) {
            BST->Right = insertBST(BST->Right, NewData);
        }
    }
    return BST;
}

binaryTree findMin (binaryTree BST) {
    while (BST->Left) {
        BST = BST->Left;
    }
    return BST;
}

//The node that is truly deleted should be the maximum of
//the left tree of the node that has the value that needs
//to be deleted.
binaryTree deleteBST (binaryTree BST, int DeleteData) {
    binaryTree Temp;
    if (!BST) {
        cout << "The element that needs to be deleted doesn't exist!" << endl;
    }
    else if (DeleteData < BST->Data) {
        BST->Left = deleteBST(BST->Left, DeleteData);
    }
    else if (DeleteData > BST->Data) {
        BST->Right = deleteBST(BST->Right, DeleteData);
    }
    else {
        if (BST->Left && BST->Right) {
            Temp = findMin(BST->Right);
            BST->Data = Temp->Data;
            BST->Right = deleteBST(BST->Right, Temp->Data);
        }
        else {
            Temp = BST;
            if (BST->Right) {
                BST = BST->Right;
            }
            else {
                BST = BST->Left;
            }
            delete Temp;
        }
    }
    return BST;
}

int main() {
    binaryTree BST1 = nullptr;
    BST1 = insertBST(BST1, 0);
    BST1 = insertBST(BST1, -2);
    BST1 = insertBST(BST1, -3);
    BST1 = insertBST(BST1, -4);
    BST1 = insertBST(BST1, -1);
    BST1 = insertBST(BST1, 4);
    BST1 = insertBST(BST1, 5);
    BST1 = insertBST(BST1, 3);
    BST1 = insertBST(BST1, 1);
    BST1 = insertBST(BST1, 2);
    cout << "PreOrderTraversal : ";
    preOrderTraversal(BST1);
    cout << endl;
    cout << "InOrderTraversal : ";
    inOrderTraversal(BST1);
    cout << endl;
    cout << "PostOrderTraversal : ";
    postOrderTraversal(BST1);
    cout << endl;
    BST1 = deleteBST(BST1, -3);
    BST1 = deleteBST(BST1, 4);
    BST1 = deleteBST(BST1, 10);
    BST1 = deleteBST(BST1, 0);
    cout << "PreOrderTraversal : ";
    preOrderTraversal(BST1);
    cout << endl;
    cout << "InOrderTraversal : ";
    inOrderTraversal(BST1);
    cout << endl;
    cout << "PostOrderTraversal : ";
    postOrderTraversal(BST1);
    cout << endl;
    return 0;
}
