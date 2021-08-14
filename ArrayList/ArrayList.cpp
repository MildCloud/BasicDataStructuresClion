#include <iostream>
using namespace std;

typedef class listNode * list;
class listNode {
    public:
        int array[100];//last <= 99
        int last;
    public:
        listNode () {           
            array[100] = {0};
            last = -1;
            //The same way of enumerate, which
            //means that if writing last = -1 
            //before array argument, the last 
            //will still be 0 
        }
};

int find (int findElement, list list) {
    for (int i=0; i <= list->last; i++) {
        if (findElement == list->array[i]) {return i;}
    }
    return -1;
}

//insert newElement in array[i] (i >= 0 && i <= last)
void insert (int newElement, int i, list list) {
    for (int j = list->last; j >= i; j--) {
        list->array[j+1] = list->array[j];
    }
    list->last++;
    list->array[i] = newElement;
}

//delete an element in array[i] (i >= 0 && i <= last)
void deleteL (int i, list list) {
    for (int j = i; j <= list->last; j++) {
        list->array[j] = list->array[j+1];
    }
    list->last--;
}
// Be caerful when using "j" an "i"

int main () {
    int findElement, insertElement, insertPos, deletePos;
    listNode lNode;
    list lPointer = &lNode;

    cout << "last is " << lNode . last << endl;

    for (int i=0; i < 10; i++) {
        insert ((i+10), i, lPointer);
        cout << "last is " << lPointer -> last << endl;
    }

    for (int i=0; i <= lPointer->last; i++) {
        cout << "array[" << i << "] = " << lPointer -> array[i] << endl;
    }

    cout << "find the following element: " << endl;
    cin >> findElement;
    cout << "This element is in array[" << find (findElement, lPointer) << "]." << endl;

    cout << "Insert a new elment:" << endl;
    cin >> insertElement;
    cout << "in: " <<endl;
    cin >> insertPos;
    insert (insertElement, insertPos, lPointer);

    for (int i=0; i <= lPointer->last; i++) {
        cout << "array[" << i << "] = " << lPointer -> array[i] << endl;
    }

    cout << "Delet a element in the following position: " << endl;
    cin >> deletePos;
    deleteL (deletePos, lPointer);

    for (int i=0; i <= lPointer->last; i++) {
        cout << "array[" << i << "] = " << lPointer -> array[i] << endl;
    }

    return 0;
}