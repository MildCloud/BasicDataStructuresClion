#include <stdio.h>

#define MaxSize 10

struct sNode {
    char Data[MaxSize];
    int Top;
};
typedef struct sNode * stack;

void push (stack Stack, char Item) {
    if (Stack->Top == MaxSize - 1) {
        printf("The stack is already full.\n");
    }
    else {
        Stack->Data[++Stack->Top] = Item;
    }
}

char pop (stack Stack) {
    return Stack->Data[Stack->Top--];
}

void showStack (stack Stack) {
    for (int i = 0; i <= Stack->Top; i++) {
        printf ("Stack[%d] = %c\n", i, (Stack->Data[i]));
    }
}


struct unionSNode {
    char Data[MaxSize];
    int Top1, Top2;
};
typedef struct unionSNode * unionStack;

void pushUnion (unionStack UnionStack, char Item, int Position) {
    if (UnionStack->Top1 + 1 == UnionStack->Top2) {
        printf ("The union stack is already full.\n");
    }
    else {
        if (Position == 1) {
            UnionStack->Data[++UnionStack->Top1] = Item;
        }
        else {
            UnionStack->Data[--UnionStack->Top2] = Item;
        }
    }
}

char popUnion (unionStack UnionStack, int Position) {
    if (Position == 1) {
        return UnionStack->Data[UnionStack->Top1--];
    }
    else if (Position == 2) {
        return UnionStack->Data[UnionStack->Top2++];
    }
    else {
        return 'E';
    }
}

void showUnionStack (unionStack UnionStack) {
    for (int i = 0; i <= UnionStack->Top1; i++) {
        printf ("Stack1[%d] = %c\n", i, (UnionStack->Data[i]));
    }
    for (int i = UnionStack->Top2; i < MaxSize; i++) {
        printf ("Stack2[%d] = %c\n", i, (UnionStack->Data[i]));
    }
}

int main () {
    struct sNode SNode;
    SNode.Top = -1;//Tradition
    stack Stack = & SNode;
    for (int i = 0; i <= 11; i++) {
        push (Stack, ('a' + i));
    }
    showStack (Stack);
    printf ("\n");
    for (int i = 0; i <= 9; i++) {
        int Order = 9 - i;
        char Last = pop (Stack);
        printf ("Stack[%d] = %c\n", Order, Last);
    }
    showStack (Stack);
    printf ("\n");

    struct unionSNode UnionSNode;
    UnionSNode.Top1 = -1;//Tradition
    UnionSNode.Top2 = MaxSize;
    unionStack UnionStack = & UnionSNode;
    for (int i = 0; i <= 6; i++) {
        pushUnion (UnionStack, ('a' + 2 * i), 1);
    }
    printf ("Show UnionStack\n");
    showUnionStack (UnionStack);
    printf ("\n");
    for (int i = 0; i <= 6; i++) {
        pushUnion (UnionStack, ('a' + 2 * i), 2);
    }
    printf ("Show UnionStack\n");
    showUnionStack (UnionStack);
    printf ("\n");
    for (int i = 0; i <= 6; i++) {
        int Order = 6 - i;
        char Last = popUnion (UnionStack, 1);
        printf ("Stack1[%d] = %c\n", Order, Last);
    }
    printf ("Show UnionStack\n");
    showUnionStack (UnionStack);
    printf ("\n");
    for (int i = 0; i <= 2; i++) {
        int Order = 2 - i;
        char Last = popUnion (UnionStack, 2);
        printf ("Stack2[%d] = %c\n", Order, Last);
    }
    printf ("Show UnionStack\n");
    showUnionStack (UnionStack);
    printf ("\n");  
    return 0;
}