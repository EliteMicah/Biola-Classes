#include <iostream>
#include "Coord.h"
using namespace std;

int main() {

    coord C;
    C.set(3, -4);
    C.display();
    cout << C.distance() << endl;
    C.scale(3);
    C.display();
    
    cout << endl;
    system("pause");
    exit(0);
}
