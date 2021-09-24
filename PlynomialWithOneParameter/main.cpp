#include <iostream>
using namespace std;

class polyNode {
public:
    int Coefficient;
    int Index;
    polyNode * Next;
};
typedef polyNode* polynomial;

polynomial creatPolynomial () {
    polynomial Polynomial = new polyNode;
    Polynomial->Next = nullptr;
    return Polynomial;
}

int findLength (polynomial Polynomial) {
    if (Polynomial->Next == nullptr) {
        return 0;
    }
    else {
        return findLength (Polynomial->Next) + 1;
    }
}

polynomial insertPolynomial (polynomial Polynomial, int Position, int NewCoefficient, int NewIndex) {
    polynomial OriPolynomial = Polynomial;
    if (Position >= 0 && Position <= findLength(Polynomial)) {
        for (int i = 0; i < Position; i++) {
            Polynomial = Polynomial->Next;
        }
        polynomial NewPolyNode = new polyNode;
        NewPolyNode->Coefficient = NewCoefficient;
        NewPolyNode->Index = NewIndex;
        NewPolyNode->Next = Polynomial->Next;
        Polynomial->Next = NewPolyNode;
        return OriPolynomial;
    }
    else {
        cout << "Insert Error!" << endl;
        return OriPolynomial;
    }
}

void showPoly (polynomial Polynomial) {
    if (Polynomial->Next) {
        while (Polynomial->Next->Next != nullptr) {
            Polynomial = Polynomial->Next;
            cout << Polynomial->Coefficient << " " << Polynomial->Index << " ";
        }
        Polynomial = Polynomial->Next;
        cout << Polynomial->Coefficient << " " << Polynomial->Index;
    }
}

polynomial addPoly (polynomial Polynomial1, polynomial Polynomial2) {
    polynomial AddPoly = new polyNode;
    int i = 0;
    Polynomial1 = Polynomial1->Next;
    Polynomial2 = Polynomial2->Next;
    while (Polynomial1 || Polynomial2) {
        if (!Polynomial1) {
            while (Polynomial2) {
                if (Polynomial2->Coefficient != 0) {AddPoly = insertPolynomial(AddPoly, i++, Polynomial2->Coefficient, Polynomial2->Index);}
                Polynomial2 = Polynomial2->Next;
            }
        }
        else if (!Polynomial2) {
            while (Polynomial1) {
                if (Polynomial1->Coefficient != 0) {AddPoly = insertPolynomial(AddPoly, i++, Polynomial1->Coefficient, Polynomial1->Index);}
                Polynomial1 = Polynomial1->Next;
            }
        }
        else {
            if (Polynomial1->Index > Polynomial2->Index) {
                AddPoly = insertPolynomial(AddPoly, i++, Polynomial1->Coefficient, Polynomial1->Index);
                Polynomial1 = Polynomial1->Next;
            }
            else if (Polynomial1->Index < Polynomial2->Index) {
                AddPoly = insertPolynomial(AddPoly, i++, Polynomial2->Coefficient, Polynomial2->Index);
                Polynomial2 = Polynomial2->Next;
            }
            else {
                if (Polynomial1->Coefficient + Polynomial2->Coefficient != 0) {
                    AddPoly = insertPolynomial(AddPoly, i++, Polynomial1->Coefficient + Polynomial2->Coefficient, Polynomial1->Index);
                    Polynomial1 = Polynomial1->Next;
                    Polynomial2 = Polynomial2->Next;
                }
                else {
                    Polynomial1 = Polynomial1->Next;
                    Polynomial2 = Polynomial2->Next;
                }
            }
        }
    }
    return AddPoly;
}

polynomial multiPoly (polynomial Polynomial1, polynomial Polynomial2) {
    polynomial MultiPoly = creatPolynomial();
    MultiPoly = insertPolynomial(MultiPoly, 0, 0, 0);
    Polynomial1 = Polynomial1->Next;
    Polynomial2 = Polynomial2->Next;
    if (Polynomial1->Coefficient * Polynomial2->Coefficient) {
        polynomial OriPoly2 = Polynomial2;
        while (Polynomial1) {
            int i = 0;
            polynomial AddPoly = creatPolynomial();
            while (Polynomial2) {
                AddPoly = insertPolynomial(AddPoly, i++, Polynomial2->Coefficient * Polynomial1->Coefficient, Polynomial2->Index + Polynomial1->Index);
                Polynomial2 = Polynomial2->Next;
            }
            Polynomial2 = OriPoly2;
            //Since the value of Polynomial2 is modified in the while loop, it needs to be restored.
            MultiPoly = addPoly(MultiPoly, AddPoly);
            Polynomial1 = Polynomial1->Next;
        }
    }
    return MultiPoly;
}

int main() {
    int length1, length2;
    polynomial Poly1 = creatPolynomial(), Poly2 = creatPolynomial(), Add, Multi;
    cin >> length1;
    if (length1 == 0) {
        Poly1 = insertPolynomial(Poly1, 0, 0, 0);
    }
    else {
        int * In1 = new int[2 * length1];
        for (int i = 0; i < 2 * length1; i++) {
            cin >> In1[i];
        }
        for (int i = 0; i < 2 * length1 - 1; i = i + 2) {
            Poly1 = insertPolynomial(Poly1, i/2, In1[i], In1[i+1]);
        }
    }
    cin >> length2;
    if (length2 == 0) {
        Poly2 = insertPolynomial(Poly2, 0, 0, 0);
    }
    else {
        int * In2 = new int[2 * length2];
        for (int i = 0; i < 2 * length2; i++) {
            cin >> In2[i];
        }
        for (int i = 0; i < 2 * length2 - 1; i = i+2) {
            Poly2 = insertPolynomial(Poly2, i/2, In2[i], In2[i+1]);
        }
    }
    Multi = multiPoly(Poly1, Poly2);
    Add = addPoly(Poly1, Poly2);
    showPoly(Multi);
    cout << endl;
    showPoly(Add);
    return 0;
}
