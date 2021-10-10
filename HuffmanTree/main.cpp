#include <iostream>
using namespace std;

#define MinData (-1)

class minHeap {
public:
    int * Data;
    int Size;
    int MaxSize;
};

minHeap * createMinHeap (int MaxSize) {
    minHeap * MinHeap = new minHeap;
    MinHeap->Data = new int[MaxSize];
    MinHeap->Data[0] = MinData;
    MinHeap->Size = 0;
    MinHeap->MaxSize = MaxSize;
    return MinHeap;
}

bool isEmpty (minHeap MinHeap) {
    return (MinHeap.Size == 0);
}

bool isFull (minHeap MinHeap) {
    return (MinHeap.Size + 1 == MinHeap.MaxSize);
}

void insertMinHeap (minHeap * MinHeap, int NewData) {
    if (isFull(*MinHeap)) {
        cout << "The MinHeap is already full!" << endl;
        return;
    }
    else {
        if (NewData < MinData) {
            cout << "The NewData is smaller than the MinData!" << endl;
            return;
        }
        else {
            for (int i = ++MinHeap->Size; i >= 1; i /= 2) {
                if (NewData < MinHeap->Data[i / 2]) {
                    MinHeap->Data[i] = MinHeap->Data[i / 2];
                }
                else {
                    MinHeap->Data[i] = NewData;
                    break;//Not just use it to increase the efficiency.
                }
            }
        }
    }
}

int deleteMinHeap (minHeap * MinHeap) {
    if (isEmpty(*MinHeap)) {
        cout << "The MinHeap is already empty!" << endl;
        return -1;
    }
    else {
        int RootData = MinHeap->Data[1], OriLeaf = MinHeap->Data[MinHeap->Size--], Parent = 1, Child;
        for (;Parent * 2 <= MinHeap->Size; Parent = Child) {
            Child = Parent * 2;
            if (Child + 1 <= MinHeap->Size && MinHeap->Data[Child] > MinHeap->Data[Child + 1]) {
                Child++;
            }
            if (OriLeaf > MinHeap->Data[Child]) {
                MinHeap->Data[Parent] = MinHeap->Data[Child];
            }
            else {
                break;
            }
        }
        MinHeap->Data[Parent] = OriLeaf;
        return RootData;
    }
}

void showMinHeap (minHeap MinHeap) {
    for (int i = 0; i <= MinHeap.Size; i++) {
        cout << MinHeap.Data[i] << " ";
    }
}

class huffmanNode {
public:
    int Weight;
    huffmanNode * Left;
    huffmanNode * Right;
};
typedef huffmanNode * huffmanTree;

//Like using Stack and Queue to traversal, the element type must be tree.
class minTreeHeap {
public:
    huffmanTree * Data;
    int Size;
    int MaxSize;
};

minTreeHeap * createMinTreeHeap (int MaxSize) {
    minTreeHeap * MinHeap = new minTreeHeap;
    MinHeap->Data = new huffmanTree[MaxSize];
    huffmanTree HuffmanTree = new huffmanNode;
    HuffmanTree->Weight = MinData;
    HuffmanTree->Left = nullptr;
    HuffmanTree->Right = nullptr;
    MinHeap->Data[0] = HuffmanTree;
    MinHeap->Size = 0;
    MinHeap->MaxSize = MaxSize;
    return MinHeap;
}

bool isEmptyForTree (minTreeHeap MinHeap) {
    return (MinHeap.Size == 0);
}

bool isFullForTree (minTreeHeap MinHeap) {
    return (MinHeap.Size + 1 == MinHeap.MaxSize);
}

void insertMinTreeHeap (minTreeHeap * MinHeap, huffmanTree NewData) {
    if (isFullForTree(*MinHeap)) {
        cout << "The MinHeap is already full!" << endl;
        return;
    }
    else {
        if (NewData->Weight < MinData) {
            cout << "The NewData is smaller than the MinData!" << endl;
            return;
        }
        else {
            for (int i = ++MinHeap->Size; i >= 1; i /= 2) {
                if (NewData->Weight < MinHeap->Data[i / 2]->Weight) {
                    MinHeap->Data[i] = MinHeap->Data[i / 2];
                }
                else {
                    MinHeap->Data[i] = NewData;
                    break;//Not just use it to increase the efficiency.
                }
            }
        }
    }
}

huffmanTree deleteMinTreeHeap (minTreeHeap * MinHeap) {
    if (isEmptyForTree(*MinHeap)) {
        cout << "The MinHeap is already empty!" << endl;
        return nullptr;
    }
    else {
        huffmanTree RootData = MinHeap->Data[1], OriLeaf = MinHeap->Data[MinHeap->Size--];
        int Parent = 1, Child;
        for (;Parent * 2 <= MinHeap->Size; Parent = Child) {
            Child = Parent * 2;
            if (Child + 1 <= MinHeap->Size && MinHeap->Data[Child]->Weight > MinHeap->Data[Child + 1]->Weight) {
                Child++;
            }
            if (OriLeaf->Weight > MinHeap->Data[Child]->Weight) {
                MinHeap->Data[Parent] = MinHeap->Data[Child];
            }
            else {
                break;
            }
        }
        MinHeap->Data[Parent] = OriLeaf;
        return RootData;
    }
}

huffmanTree createHuffmanTree (minTreeHeap MinTreeHeap) {
    while (MinTreeHeap.Size > 1) {
        huffmanTree HuffmanTree = new huffmanNode;
        HuffmanTree->Left = deleteMinTreeHeap(&MinTreeHeap);
        HuffmanTree->Right = deleteMinTreeHeap(&MinTreeHeap);
        HuffmanTree->Weight = HuffmanTree->Left->Weight + HuffmanTree->Right->Weight;
        insertMinTreeHeap(&MinTreeHeap, HuffmanTree);
    }
    return deleteMinTreeHeap(&MinTreeHeap);
}

int main() {
    minTreeHeap * MinTreeHeap = createMinTreeHeap(10);
    for (int i = 10; i > 0; i--) {
        huffmanTree HuffmanTree = new huffmanNode;
        HuffmanTree->Weight = i;
        HuffmanTree->Left = HuffmanTree->Right = nullptr;
        insertMinTreeHeap(MinTreeHeap, HuffmanTree);
    }
    for (int i = 0; i <= 9; i++) {
        cout << MinTreeHeap->Data[i]->Weight << " ";
    }
    huffmanTree HuffmanTree = createHuffmanTree(*MinTreeHeap);
    return 0;
}
