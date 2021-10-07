#include <iostream>
using namespace std;

class lNode {
public:
    int Data;
    lNode * Next;
};
typedef lNode* list;

list createList () {
    list List = new lNode;
    List->Next = nullptr;
    return List;
}

void showList (list List) {
    if (List->Next) {
        List = List->Next;
        while (List) {
            cout << List->Data;
            List = List->Next;
        }
        cout << endl;
    }
    else {
        cout << "Empty!" << endl;
    }
}

//Since no recursion is applied, the function need to return the original List;
list insertList (list List, int NewData, int NewPosition) {
    list OriList = List;
    for (int i = 0; i < NewPosition; i++) {
        if (!List) {break;}
        List = List->Next;
    }
    if (List && NewPosition >= 0) {
        list NewNode = createList();
        NewNode->Data = NewData;
        NewNode->Next = List->Next;
        List->Next = NewNode;
    }
    else {
        cout << "Insert Error!" << endl;
    }
    return OriList;
}

list deleteList (list List, int DeletePosition) {
    int length = 0;
    list Temp1 = List, OriList = List;
    while (Temp1->Next) {
        Temp1 = Temp1->Next;
        length++;
    }
    if (DeletePosition >= 0 && DeletePosition < length) {
        for (int i = 0; i < DeletePosition; i++) {
            List = List->Next;
        }
        list Temp2 = List->Next;
        List->Next = List->Next->Next;
        delete Temp2;
    }
    else {
        cout << "Delete List Error!" << endl;
    }
    return OriList;
}

list pushStack (list List, int NewData) {
    list OriList = List;
    while (List->Next) {
        List = List->Next;
    }
    list NewNode = createList();
    NewNode->Data = NewData;
    List->Next = NewNode;
    return OriList;
}

int popStack (list List) {
    if (List->Next) {
        while (List->Next->Next) {
            List = List->Next;
        }
        list Temp = List->Next;
        int PopData = Temp->Data;
        List->Next = nullptr;
        delete Temp;
        return PopData;
    }
    else {
        cout << "Stack Pop Error!" << endl;
        return 0;
    }
}

list insertQueue (list List, int NewData) {
    return pushStack(List, NewData);
}

int deleteQueue (list List) {
    if (List->Next) {
        list Temp = List->Next;
        int DeleteData = Temp->Data;
        List->Next = List->Next->Next;
        delete Temp;
        return DeleteData;
    }
    else {
        cout << "Queue Delete Error!" << endl;
        return 0;
    }
}

class binaryNode {
public:
    int Data;
    binaryNode * Left;
    binaryNode * Right;
};
typedef binaryNode * bSTree;

//The following class and function just the copy of the lNode class and its relevant function
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class lNodeForTree {
public:
    bSTree Data;
    lNodeForTree * Next;
};
typedef lNodeForTree* listForTree;

listForTree createListForTree () {
    listForTree List = new lNodeForTree;
    List->Next = nullptr;
    return List;
}

listForTree pushStackForTree (listForTree List, bSTree NewData) {
    listForTree OriList = List;
    while (List->Next) {
        List = List->Next;
    }
    listForTree NewNode = createListForTree();
    NewNode->Data = NewData;
    List->Next = NewNode;
    return OriList;
}

bSTree popStackForTree (listForTree List) {
    if (List->Next) {
        while (List->Next->Next) {
            List = List->Next;
        }
        listForTree Temp = List->Next;
        bSTree PopData = Temp->Data;
        List->Next = nullptr;
        delete Temp;
        return PopData;
    }
    else {
        cout << "Stack Pop Error!" << endl;
        return nullptr;
    }
}

listForTree insertQueueForTree (listForTree List, bSTree NewData) {
    return pushStackForTree(List, NewData);
}

bSTree deleteQueueForTree (listForTree List) {
    if (List->Next) {
        listForTree Temp = List->Next;
        bSTree DeleteData = Temp->Data;
        List->Next = List->Next->Next;
        delete Temp;
        return DeleteData;
    }
    else {
        cout << "Queue Delete Error!" << endl;
        return nullptr;
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

bSTree findMin (bSTree BST) {
    if (BST->Left) {
        BST = findMin(BST->Left);
    }
    return BST;
}

void preOrderTraversal (bSTree BST) {
    if (BST) {
        cout << BST->Data;
        preOrderTraversal(BST->Left);
        preOrderTraversal(BST->Right);
    }
}

void inOrderTraversal (bSTree BST) {
    if (BST) {
        inOrderTraversal(BST->Left);
        cout << BST->Data;
        inOrderTraversal(BST->Right);
    }
}

void inOrderTraversalWithoutRecursion (bSTree BST) {
    listForTree Stack = createListForTree();
    while (true) {
        while (BST) {
            Stack = pushStackForTree(Stack,BST);
            BST = BST->Left;
        }
        BST = popStackForTree(Stack);
        cout << BST->Data;
        BST = BST->Right;
        if (!Stack->Next && !BST) {break;}
    }
}

void postOrderTraversal (bSTree BST) {
    if (BST) {
        postOrderTraversal(BST->Left);
        postOrderTraversal(BST->Right);
        cout << BST->Data;
    }
}

bSTree insertBST (bSTree BST, int NewData) {
    if (!BST) {
        bSTree NewNode = new binaryNode;
        NewNode->Data = NewData;
        NewNode->Left = nullptr;
        NewNode->Right = nullptr;
        BST = NewNode;
    }
    else {
        if (NewData < BST->Data) {
            BST->Left = insertBST(BST->Left, NewData);
        }
        else if (NewData > BST->Data) {
            BST->Right = insertBST(BST->Right, NewData);
        }
    }
    return BST;
}

bSTree deleteBST (bSTree BST, int DeleteData) {
    if (!BST) {
        cout << "Delete Error!" << endl;
    }
    else {
        if (DeleteData < BST->Data) {
            BST->Left = deleteBST(BST->Left, DeleteData);
        }
        else if (DeleteData > BST->Data) {
            BST->Right = deleteBST(BST->Right, DeleteData);
        }
        else {
            bSTree Temp;
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
    }
    return BST;
}

int main() {
    bSTree BST1 = nullptr;
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
    cout << "InOrderTraversalWithoutRecursion : ";
    inOrderTraversalWithoutRecursion(BST1);
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
    cout << "InOrderTraversalWithoutRecursion : ";
    inOrderTraversalWithoutRecursion(BST1);
    cout << endl;
    cout << "PostOrderTraversal : ";
    postOrderTraversal(BST1);
    cout << endl;
    list List = createList(), Stack = createList(), Queue = createList();
    cout << "List : ";
    showList(List);
    insertList(List, 1, 10);
    for (int i = 0; i < 9; i++) {
        List = insertList(List, i, i);
    }
    cout << "List : ";
    showList(List);
    List = insertList(List, 99, 10);
    cout << "List : ";
    showList(List);
    List = deleteList(List, 0);
    cout << "List : ";
    showList(List);
    List = deleteList(List, 7);
    cout << "List : ";
    showList(List);
    List = deleteList(List, 10);
    List = deleteList(List, -1);
    List = deleteList(List, 2);
    cout << "List : ";
    showList(List);
    for (int i = 0; i < 9; i++) {
        Stack = pushStack(Stack, i);
    }
    cout << "Stack : ";
    showList(Stack);
    cout << popStack(Stack) << endl;
    cout << "Stack : ";
    showList(Stack);
    for (int i = 0; i < 9; i++) {
        cout << popStack(Stack);
    }
    cout << endl;
    cout << "Stack : ";
    showList(Stack);
    for (int i = 0; i < 9; i++) {
        Queue = insertQueue(Queue, i);
    }
    cout << "Queue : ";
    showList(Queue);
    for (int i = 0; i < 10; i++) {
        cout << deleteQueue(Queue);
    }
    cout << endl;
    cout << "Queue : ";
    showList(Queue);
    return 0;
}
