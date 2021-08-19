#include <iostream>
using namespace std;

class sNode {
private:
    char Data;
    sNode * Next;
public:
    void setNewData (char Item);
    void setNewNext (sNode * Stack);
    sNode * next ();
    friend sNode * createStack ();
    friend int isEmpty (sNode * Stack);
    friend void push (char Item, sNode * Stack);
};
typedef sNode * stack;

void sNode :: setNewData (char Item) {
    Data = Item;
}

void sNode :: setNewNext (sNode * Stack) {
    Next = Stack;
}

sNode * sNode :: next () {
    return Next;
}

stack createStack () {
    auto Stack = new sNode;
    Stack->Next = nullptr;
    return Stack;
}

int isEmpty (stack Stack) {
    return (Stack->Next == nullptr);
}

//considering the existence of the empty head, the push function is actually acted as insert function.
void push (char Item, stack Stack) {
    auto NewNode = new sNode;
    NewNode->setNewData (Item);
    NewNode->setNewNext (Stack->next());
    Stack->setNewNext (NewNode);
}


int main () {
    return 0;
}