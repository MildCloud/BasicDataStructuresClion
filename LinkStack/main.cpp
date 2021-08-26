#include <iostream>
using namespace std;

class sNode {
private:
    char Data;
    sNode * Next;
public:
    void setNewData (char Item);
    void setNewNext (sNode * Stack);
    sNode * next () const;
    char data () const;
    friend void showStack (sNode * Stack);
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

void showStack (stack Stack) {
    int length = 0;
    stack OriStack = Stack;
    while (Stack->next() != nullptr) {
        Stack = Stack->next();
        length++;
    }
    cout << "This is a stack with a length of " << length << "." << endl;
    for (int i = 0; i < length; i++) {
        OriStack = OriStack->next();
        cout << "Stack[" << length - 1 - i << "] = " << OriStack->data() << endl;
    }
}

sNode * sNode :: next () const {
    return Next;
}

char sNode :: data () const {
    return Data;
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

char pop (stack Stack) {
    char PopData = Stack->next()->data();
    Stack->setNewNext(Stack->next()->next());
    return PopData;
}

int main () {
    stack Stack = createStack();
    for (int i = 0; i < 10; i++) {
        push ('a' + i, Stack);
    }
    showStack (Stack);
    cout << "Show the pop result: ";
    for (int i = 0; i < 10; i++) {
        char a = pop (Stack);
        cout << a ---0;
    }
    cout << endl;
    showStack (Stack);
    return 0;
}