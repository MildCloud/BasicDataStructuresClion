#include <iostream>
using namespace std;

class sNode {
    private:
        char Data;
        sNode * Next;
    public:
        void setNewData (int Item);
        void setNewNext (sNode * Stack);
        sNode * next ();
        friend sNode * createStack ();
        friend int isEmpty (sNode * Stack);
        friend void push (char Item, sNode * Stack);
};
typedef sNode * stack;

void sNode :: setNewData (int Item) {
    Data = Item;
}

void sNode :: setNewNext (sNode * Stack) {
    Next = Stack;
}

sNode * sNode :: next () {
    return Next;
}

stack createStack () {
    stack Stack = new sNode;
    Stack->Next = NULL;
    return Stack;
}

int isEmpty (stack Stack) {
    return (Stack->Next == NULL);
}

//considering the existence of the empty head, the push function is actually acted as insert function.
void push (char Item, stack Stack) {
    stack NewNode = new sNode;
    NewNode->setNewData (Item);
    NewNode->setNewNext (Stack->next())
    Stack->setNewNext (NewNode);
}


int main () {
    return 0;
}