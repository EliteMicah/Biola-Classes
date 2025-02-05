#include <iostream>
#include "LinkedList.h"
using namespace std;


int main() {

    LinkedList<int> L;
    cout << "Testing insert_at ....\n\n";
    cout << "L : "; L.print(); cout << endl;
    for (int i = 0; i < 5; i++) {
        int k, x;
        k = rand() % (i + 2);
        x = rand() % 101;
        L.insert_at(k, x);
        cout << "\ninsert_at(" << k << ", " << x << ")\n";
        cout << "L : "; L.print(); cout << endl;
    }

    system("pause");
    system("cls");

    cout << "Testing remove_at ....\n\n";
    cout << "L : "; L.print(); cout << endl;

    for (int i = 0; i < 5; i++) {
        int k;
        cout << "Enter the location to remove from the list : \n";
        cin >> k;
        L.remove_at(k);
        cout << "L : "; L.print(); cout << endl;
    }

    system("pause");
    system("cls");
    cout << "Testing isSorted ....\n\n";

    LinkedList<int> L2;
    cout << "L2 : "; L2.print(); cout << endl;

    if (L2.isSorted())
        cout << "L2 is sorted\n";
    else
        cout << "L2 is not sorted\n";

    for (int i = 0; i < 5; i++) {
        L2.insert_at(0, rand() % 21);
        cout << "L2 : "; L2.print(); cout << endl;
        if (L2.isSorted())
            cout << "L2 is sorted\n";
        else
            cout << "L2 is not sorted\n";
    }

    LinkedList<int> L3;
    cout << "L3 : "; L3.print(); cout << endl;
    for (int i = 0; i < 5; i++) {
        L3.insert_at(-1, i * i);
        cout << "L3 : "; L3.print(); cout << endl;
        if (L3.isSorted())
            cout << "L3 is sorted\n";
        else
            cout << "L3 is not sorted\n";
    }
    
    cout << endl;
    system("pause");
    exit(0);
}
