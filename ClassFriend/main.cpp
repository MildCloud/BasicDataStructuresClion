#include <iostream>
#include <string>
using namespace std;

class car {
    private:
        string brand;
        int enginePower;
    public:
        static int totalCarNumber;
    public: 
        car () {
            brand = "Unknown";
            enginePower = 0;
        }

        car (string str, int epower) {
            brand = str; 
            enginePower = epower;
        }

        void setCarBrand (string str) {
            brand = str;
        }

        void show ();

        friend int staticCarNumber (car car);
        friend int staticCarPointer (car * carPointer);
};

int car :: totalCarNumber = 0;

void car :: show () {
    cout << "This is a car" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Engine power: " << enginePower <<  endl;
}

int staticCarNumber (car car) {
    car.setCarBrand ("Statical Normal Brand");
    return ++car.totalCarNumber;
}

int staticCarPointer (car * carPointer) {
    carPointer->setCarBrand("Static Pointer Brand");
    return ++carPointer->totalCarNumber;
}

int main () {
    car car1, car2 ("AE-86", 100), * normalCar;
    int normalCarNumber;
    car1.totalCarNumber++;
    car2.totalCarNumber++;
    cout << "Enter the normal car number: ";
    cin >> normalCarNumber;
    normalCar = new car[normalCarNumber];
    normalCar -> totalCarNumber += normalCarNumber; 
    cout << "The total normal car number is " << normalCarNumber << "." << endl;
    for (int i=0; i < normalCarNumber; i++) {
        (* (normalCar + i)).show();
        (normalCar + i) -> setCarBrand ( "Normal Brand" );
        cout << "<<<<<<Update the car brand>>>>>>" << endl;
        (normalCar + i) -> show();
    }
    cout << "The total car number is " << normalCar->totalCarNumber << "." << endl;
    cout << "Confirm that the static member is independent of the class variables" << endl;
    cout << car1.totalCarNumber << ", " << car2.totalCarNumber << ", " << normalCar->totalCarNumber << endl;
    cout << "<<<<<<Test whether formal parameter can change static member>>>>>>" <<  endl;
    cout << "Use staticCarNumber to show the total car number: " << staticCarNumber(car1) << endl;
    car1.show();
    cout << "The total car number is " << car1.totalCarNumber << "." << endl;
    cout << "Use staticCarPointer to show the total car number: " << staticCarPointer(&car1) << endl;
    car1.show();
    cout << "The total car number is " << car1.totalCarNumber << "." << endl;
    cout << "The result shows that the static member can be changed by formal parameter, but other member can't be chenged in this way as expected." << endl;
    delete [] normalCar;
    return 0;
}
