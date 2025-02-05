#include <iostream>
using namespace std;

int getMode(int*, int);
int* reverseArray(int*, int);
int* rightShift(int*, int);


int main() {


    cout << endl;
    system("pause");
    exit(0);
}


int getMode(int* x, int size) {

    int max = 0, numA, numB, count = 0, result = 0;

    //Getting the Mode
    for (int i = 0; i < size; i++) {
        numA = x[i];
        for (int j = 0; j < size; j++) {
            numB = x[j];
            if (numA == numB) {
                count++;
            }
        }
        if (count >= max) {
            max = count;
            result = numA;
        }
        count = 0;
    }

    cout << "The mode is: ";

    //Returning the Mode
    if (max >= 2)
        return result;
    else
        return -1;
}

int* reverseArray(int* x, int size) {

    //New pointer copy
    int* copy;
    copy = new int[size] {0};
    int num = 0;

    //Making a loop that goes from size to 0
    for (int i = size - 1; i >= 0; i--) {
        copy[num] = x[i];
        num++;
    }

    return copy;
}

int* rightShift(int* x, int size) {

    //Copy of size + 1
    int* copy;
    copy = new int[size + 1] { 0 };

    for (int i = 0; i < size; i++) {
        copy[i + 1] = x[i];
    }

    return copy;
}
