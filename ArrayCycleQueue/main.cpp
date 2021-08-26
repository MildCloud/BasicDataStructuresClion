#include <iostream>
using namespace std;
#define Maxsize 10

class qNode {
public:
    char Data[Maxsize];
    int Rear;
    int Front;
};
typedef qNode * queue;

queue createQueue () {
    queue Queue = new qNode;
    Queue->Rear = -1;
    Queue->Front = -1;
    return Queue;
}

void addQueue (char Item, queue Queue) {
    if ((Queue->Rear + 1) % Maxsize != Queue->Front) {
        Queue->Rear = (Queue->Rear + 1) % Maxsize;
        Queue->Data[Queue->Rear] = Item;
        cout << "Queue->Data[" << Queue->Rear << "] = " << Item << endl;
    }
}

char outQueue (queue Queue) {
    Queue->Front = (Queue->Front + 1) % Maxsize;
    return Queue->Data[Queue->Front];
}

void showQueue (queue Queue) {
    cout << "Show the queue:";
    if (Queue->Rear < Queue->Front) {
        for (int i = Queue->Front + 1; i < Maxsize; i++) {
            cout << Queue->Data[i];
        }
        for (int i = 0; i <= Queue->Rear; i++) {
            cout << Queue->Data[i];
        }
    }
    else {
        for (int i = Queue->Front + 1; i <= Queue->Rear; i++) {
            cout << Queue->Data[i];
        }
    }
}

int main() {
    queue Queue = createQueue ();
    showQueue (Queue);
    for (int i = 0; i < 10; i++) {
        addQueue ('a' + i, Queue);
    }
    showQueue (Queue);
    for (int i = 0; i < 4; i++) {
        cout << endl;
        cout << "The out is: " << outQueue (Queue) << endl;
        showQueue (Queue);
    }

    for (int i = 0; i < 10; i++) {
        addQueue ('q' + i, Queue);
    }
    showQueue (Queue);
    for (int i = 0; i < 4; i++) {
        cout << endl;
        cout << "The out is: " << outQueue (Queue) << endl;
        showQueue (Queue);
    }
    return 0;
}
