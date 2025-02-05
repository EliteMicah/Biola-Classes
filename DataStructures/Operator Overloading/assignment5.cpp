#include <iostream>
#include "coord2d.h"
using namespace std;

int main() {
    
    coord2d C;
    coord2d C2;
    C.set(3, 5);
    C2.set(4, 6);
    cout << C.operator*(C) << endl;
    cout << C.operator+(C) << endl;
    cout << C.operator[](1) << endl;


    cout << endl;
    system("pause");
    exit(0);
}
