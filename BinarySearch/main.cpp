#include <iostream>
using namespace std;


int binarySearch (int * ArrayPtr, int SearchElement, int length) {
    int left = 0, right = length - 1, mid;
    while (left <= right) {
        mid = (left + right)/2;
        if (SearchElement < *(ArrayPtr + mid)) {
            right = mid - 1;
        }
        else if (SearchElement > *(ArrayPtr + mid)) {
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

//Need to generate one more parameter!!!
int binaryRecursionSearch (int * ArrayPtr, int SearchElement, int left, int right) {
    if (right < left) {return -1;}
    int mid = (left + right) / 2;
    if (SearchElement < * (ArrayPtr + mid)) {
        return binaryRecursionSearch (ArrayPtr, SearchElement, left, mid - 1);
        //Need to add return
    }
    else if (SearchElement > * (ArrayPtr + mid)) {
        return binaryRecursionSearch (ArrayPtr, SearchElement, mid + 1, right);
    }
    else {
        return mid;
    }
}

int main() {
    int Array1[10], Array2[9];
    for (int i = 0; i < 9; i++) {
        Array1[i] = Array2[i] = i;
    }
    Array1[9] = 9;

    cout << "Array1: ";
    for (int i = 0; i < 10; i++) {
        cout << Array1[i];
    }
    cout << endl;
    cout << "binarySearch 0 : " << binarySearch (Array1, 0, 10) << endl;
    cout << "binarySearch 3 : " << binarySearch (Array1, 3, 10) << endl;
    cout << "binarySearch 9 : " << binarySearch (Array1, 9, 10) << endl;
    cout << "binarySearch 10 : " << binarySearch (Array1, 10, 10) << endl;
    cout << "binarySearch -10 : " << binarySearch (Array1, -10, 10) << endl;
    cout << "binaryRecursionSearch 0 : " << binaryRecursionSearch (Array1, 0, 0, 9) << endl;
    cout << "binaryRecursionSearch 3 : " << binaryRecursionSearch (Array1, 3, 0, 9) << endl;
    cout << "binaryRecursionSearch 9 : " << binaryRecursionSearch (Array1, 9, 0, 9) << endl;
    cout << "binaryRecursionSearch 10 : " << binaryRecursionSearch (Array1, 10, 0, 9) << endl;
    cout << "binaryRecursionSearch -10 : " << binaryRecursionSearch (Array1, -10, 0, 9) << endl;

    cout << "Array2: ";
    for (int i = 0; i < 9; i++) {
        cout << Array2[i];
    }
    cout << endl;
    cout << "binarySearch 0 : " << binarySearch (Array2, 0, 9) << endl;
    cout << "binarySearch 3 : " << binarySearch (Array2, 3, 9) << endl;
    cout << "binarySearch 8 : " << binarySearch (Array2, 8, 9) << endl;
    cout << "binarySearch 10 : " << binarySearch (Array2, 10, 9) << endl;
    cout << "binarySearch -10 : " << binarySearch (Array2, -10, 9) << endl;
    cout << "binaryRecursionSearch 0 : " << binaryRecursionSearch (Array2, 0, 0, 8) << endl;
    cout << "binaryRecursionSearch 3 : " << binaryRecursionSearch (Array2, 3, 0, 8) << endl;
    cout << "binaryRecursionSearch 8 : " << binaryRecursionSearch (Array2, 8, 0, 8) << endl;
    cout << "binaryRecursionSearch 10 : " << binaryRecursionSearch (Array2, 10, 0, 8) << endl;
    cout << "binaryRecursionSearch -10 : " << binaryRecursionSearch (Array2, -10, 0, 8) << endl;
    return 0;
}
