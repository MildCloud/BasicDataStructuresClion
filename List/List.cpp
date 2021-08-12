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

//insert newElement in i (i >= 0 && i <= last)
void insert (int newElement, int i, list list) {
    list->last++;
    list->array[i] = newElement;
}

int main () {
    int findElement;
    listNode lNode;
    list lPointer = &lNode;

    cout << "last is " << lNode . last << endl;

    for (int i=0; i < 10; i++) {
        insert((i+10), i, lPointer);
        cout << "last is " << lPointer -> last << endl;
    }

    for (int i=0; i <= lPointer->last; i++) {
        cout << "array[" << i << "] = " << lPointer -> array[i] << endl;
    }

    cout << "find the following element: " << endl;
    cin >> findElement;
    cout << "This element is in array[" << find (findElement, lPointer) << "]." << endl;
    return 0;
}