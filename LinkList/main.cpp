#include <iostream>
using namespace std;

class lNode {
public:
    int Data;
    lNode * Next;
public:
    lNode () {
        Data = -99;
        Next = nullptr;
    }
};
typedef lNode * list;
//initially it is not an empty list, but a list that contains only one element

//Position >= 0 && Position <= lengthList
//Be careful about the discontinuity of the Linked List
list insertList (int InsertData ,int Position, list List) {
    list NewNode = new lNode, OriList = List;
    NewNode->Next = nullptr;

    if (Position == 0) {
        NewNode->Data = InsertData;
        NewNode->Next = OriList;
        return NewNode;
    }
    else {
        for (int i = 0; i < Position - 1; i++) {
            List = List->Next;
        }
        list LastList = List->Next;
        List->Next = NewNode;
        NewNode->Data = InsertData;
        NewNode->Next = LastList;
        return OriList;
    }
}
//remember to link the front of the node and the back of the node;
//common mistake (from line 31 -> line 34)
//list LastList = List;
//List->Next = NewNode;
//NewNode->Data = InsertData;
//NewNode->Next = LastList->Next;
//It causes error, since "List->Next = NewNode" changes the value of "LastList->Next";
//The object (that LastList points to) doesn't change, but the value of the object changed.

list deleteList (int Position, list List) {
    list OriList = List;
    if (Position == 0) {
        return List->Next;
    }
    for (int i = 0; i < Position - 1; i++) {
        List = List->Next;
    }
    List->Next = List->Next->Next;
    return OriList;
}
//only change the value of the object that the pointer points to can cause effect
//common mistake:
//for (int i = 0; i < Position; i++) {
//  List = List->Next;
//}
//List = List->Next;
//return OriList;

int lengthList (list List) {
    int j = 0;
    while (List != nullptr) {
        List = List->Next;
        j++;
    }
    return j;
}

//Position >= 0 && Position <= lengthList - 1
list findKthList (int Position, list List) {
    for (int i = 0; i < Position; i++) {
        if (List == nullptr) {break;}
        List = List->Next;
    }
    return List;
}

list findElementList (int Element, list List) {
    while (List != nullptr) {
        if (List->Data == Element) {
            return List;
        }
        List = List->Next;
    }
    return nullptr;
}

void showList (list List) {
    cout << "The List has a length of " << lengthList (List) << "." << endl;
    int ListOrder = 0;
    while (List != nullptr) {
        cout << "List[" << ListOrder++ << "] = " << List->Data << endl;
        List = List->Next;
    }
}

int main () {
    int Array[10];
    lNode LNode;
    list List;//Will not call the constructor
    List = & LNode;
    if (List->Next == nullptr) {cout << "Null" << endl;}

    for (int i = 0; i < 10; i++) {
        Array[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        List = insertList ((Array[i]), i, List);
    }
    showList (List);

    List = insertList (-4, 0, List);
    showList (List);

    List = insertList (-60, 5, List);
    showList (List);

    List = deleteList (12, List);
    showList (List);

    List = deleteList (5, List);
    showList (List);

    List = deleteList (0, List);
    showList (List);

    cout << "0" << findKthList (0, List)->Data << endl;
    cout << "4" << findKthList (4, List)->Data << endl;
    cout << "9" << findKthList (9, List)->Data << endl;

    cout << "0" << findElementList (0, List)->Data << endl;
    cout << "4" << findElementList (4, List)->Data << endl;
    cout << "9" << findElementList (9, List)->Data << endl;

    return 0;
}
