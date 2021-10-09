#include <iostream>
using namespace std;

#define MaxData 10

class maxHeap {
public:
    int * Data;
    int Size;
    int MaxSize;
};

maxHeap * createMaxHeap (int MaxSize) {
    maxHeap * MaxHeap = new maxHeap;
    MaxHeap->Data = new int[MaxSize];
    MaxHeap->Size = 0;
    MaxHeap->MaxSize = MaxSize;
    *MaxHeap->Data = MaxData;
    return MaxHeap;
}

bool isEmpty (maxHeap MaxHeap) {
    if (MaxHeap.Size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull (maxHeap MaxHeap) {
    if (MaxHeap.Size + 1 == MaxHeap.MaxSize) {
        return true;
    }
    else {
        return false;
    }
}

//Use void but not the pointer of MaxHeap indicates that
//recursion will not appear in the following function.
//Subsequently, why not use recursion?
//The insert process starts from the below.
//Use integer division so that the order of all child nodes divided
//by 2 is the order of the parent nodes.
void insert (maxHeap * MaxHeap, int NewData) {
    if (isFull(*MaxHeap)) {
        cout << "The MaxHeap is already full!" << endl;
        return;
    }
    else {
        if (NewData > MaxData) {
            cout << "Larger than MaxData!" << endl;
            return;
        }
        else {
            int i = ++MaxHeap->Size;
            for (; MaxHeap->Data[i/2] < NewData; i /= 2) {
                MaxHeap->Data[i] = MaxHeap->Data[i/2];
            }
            MaxHeap->Data[i] = NewData;
        }
    }
}

//The critical idea of deleteMaxHeap is that consider one parent node,
//whose left child and right child are both MaxHeap, then how to adjust
//the whole structure to realize a MaxHeap.
int deleteMaxHeap (maxHeap * MaxHeap) {
    if (isEmpty(*MaxHeap)) {
        cout << "The MaxHeap is already empty!" << endl;
        return -1;
    }
    else {
        int RootValue = MaxHeap->Data[1], OriLeaf = MaxHeap->Data[MaxHeap->Size--], Parent = 1, Child;
        //MaxHeap.Data[1] = OriLeaf;
        //No need to modify the root value, since the function uses OriLeaf as the perc value.
        for (; Parent * 2 <= MaxHeap->Size; Parent = Child) {
            Child = Parent * 2;
            if (MaxHeap->Data[Child] < MaxHeap->Data[Child + 1] && Child < MaxHeap->Size) {
                Child++;
            }
            if (OriLeaf >= MaxHeap->Data[Child]) {
                //The structure of the MaxHeap is larger than or equal to.
                //Use OriLeaf here but not MaxHeap.Data[Parent] to ensure
                //that the following function don't need to swap.
                break;
            }
            else {
                MaxHeap->Data[Parent] = MaxHeap->Data[Child];
                //No need to swap the value.
            }
        }
        MaxHeap->Data[Parent] = OriLeaf;
        return RootValue;
    }
}

void percDown (maxHeap * MaxHeap, int Position) {
    int OriRoot = MaxHeap->Data[Position], Parent = Position, Child;
    for (; Parent * 2 <= MaxHeap->Size; Parent = Child) {
        Child = Parent * 2;
        if (MaxHeap->Data[Child] < MaxHeap->Data[Child + 1] && Child + 1 <= MaxHeap->Size) {
            Child++;
        }
        if (OriRoot >= MaxHeap->Data[Child]) {
            break;
        }
        else {
            MaxHeap->Data[Parent] = MaxHeap->Data[Child];
        }
    }
    MaxHeap->Data[Parent] = OriRoot;
}

void adjust (maxHeap * MaxHeap) {
    for (int i = MaxHeap->Size / 2; i >= 1; i--) {
        percDown(MaxHeap, i);
    }
}

//void RecursionAdjust (maxHeap * MaxHeap, int Position) {
//    if (Position * 2 + 1 < MaxHeap->Size) {
//        RecursionAdjust(MaxHeap, Position + 1);
//        RecursionAdjust(MaxHeap, Position + 2);
//    }
//    else {
//        if (Position * 2 == MaxHeap->Size) {
//            int Parent = Position, Child = Position * 2;
//            if (MaxHeap->Data[Parent] < MaxHeap->Data[Child]) {
//                int Temp = MaxHeap->Data[Parent];
//                MaxHeap->Data[Parent] = MaxHeap->Data[Child];
//                MaxHeap->Data[Child] = Temp;
//            }
//        }
//        else if (Position * 2 + 1 == MaxHeap->Size) {
//            int Parent = Position, Child = Position * 2;
//            if (MaxHeap->Data[Child] < MaxHeap->Data[Child + 1]) {
//                Child++;
//            }
//            if (MaxHeap->Data[Parent] < MaxHeap->Data[Child]) {
//                int Temp = MaxHeap->Data[Parent];
//                MaxHeap->Data[Parent] = MaxHeap->Data[Child];
//                MaxHeap->Data[Child] = Temp;
//            }
//        }
//    }
//}

int main() {
    maxHeap * MaxHeap1 = createMaxHeap(10),
            * MaxHeap2 = createMaxHeap(10),
            * MaxHeap3 = createMaxHeap(10);
    for (int i = 0; i < 10; i++) {
        insert(MaxHeap1, i);
    }
    insert(MaxHeap1, 2);
    for (int i = 0; i <= 9; i++) {
        cout << MaxHeap1->Data[i] << " ";
    }
    adjust(MaxHeap1);
    for (int i = 0; i <= 9; i++) {
        cout << MaxHeap1->Data[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++) {
        cout << deleteMaxHeap(MaxHeap1);
    }
    for (int i = 0; i < 9; i++) {
        MaxHeap2->Data[i + 1] = i;
    }
    MaxHeap2->Size = 9;
    adjust(MaxHeap2);
    cout << endl;
    for (int i = 0; i <=9; i++) {
        cout << MaxHeap2->Data[i] << " ";
    }
//    for (int i = 0; i < 9; i++) {
//        MaxHeap3->Data[i + 1] = i;
//    }
//    MaxHeap3->Size = 9;
//    RecursionAdjust(MaxHeap3, 1);
//    cout << endl;
//    for (int i = 0; i <=9; i++) {
//        cout << MaxHeap3->Data[i] << " ";
//    }
    return 0;
}
