#include <iostream>
using namespace std;

template <class T>
int binarySearch(T, T[], int);

template <class T>
T median(T[], int);

template <class eType>
eType* reshape(eType**, int, int);

int main() {


    cout << endl;
    system("pause");
    exit(0);
}


template <class T>
int binarySearch(T value, T myArray[], int size) {
    int first = 0, last = size - 1, middle, position = -1;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2; // Calculate mid point
        if (myArray[middle] == value) { // If value found at mid
            found = true;
            position = middle;
        }
        else if (myArray[middle] > value) // Value found in lower half
            last = middle - 1;
        else                    // Value found in upper half
            first = middle + 1;
    }
    return position;
}

template <class T>
T median(T v[], int s) {

    T median;
    int gMid = (s / 2); // Greater mid
    int lMid = (s / 2) - 1; // Lesser mid
    bool even = false; //

    if (s % 2 == 0) // If array is even - true
        even = true;
    else
        even = false; // If array is odd - false

    if (even)
        median = (v[gMid] + v[lMid]) / 2; // Median is between greater and lesser mid
    else
        median = v[lMid]; // Median is very middle

    return median;
}

template <class eType>
eType* reshape(eType** E, int row, int col) {

    eType* temp = new int[row * col]; // Creating temp of size row * col
    int k;

    for (int i = 0; i < row; i++) { // Cycling through the elements
        for (int j = 0; j < col; j++) {
            k = col * i + j; // Reinitialize k to new element
            temp[k] = E[i][j]; // Adding elements to temp
        }
    }
    return temp;
}
