#include <iostream>
#include <iomanip>
using namespace std;

bool isBalanced(int**, int, int);
int* columnSum(int**, int, int);
int* rowMax(int**, int, int);


int main() {
    

    cout << endl;
    system("pause");
    exit(0);
}

bool isBalanced(int** A, int x, int y) {
    int neg = 0, pos = 0;

    for (int i = 0; i < x; i++)
        for (int k = 0; k < y; k++)
            if (A[i][k] > 0) // Greater or less than 0, not 0 itself
                pos++;
            else
                neg++;

    if (neg == pos)
        return true;
    else
        return false;
}

int* columnSum(int** A, int x, int y) {
    int* temp;  //keep the sums of each column
    temp = new int[y] {0};

    for (int i = 0; i < x; i++)
        for (int k = 0; k < y; k++)
            temp[k] += A[i][k];

    for (int i = 0; i < y; i++)
        cout << setw(5) << temp[i];

    return temp;
}

int* rowMax(int** A, int x, int y) {
    int* temp;
    temp = new int[x] {0};

    for (int i = 0; i < x; i++) {
        int max = 0;
        for (int k = 0; k < y; k++) {
            if (A[i][k] > max) {
                max = A[i][k];
                temp[i] = max;
            }
        }
    }

    for (int i = 0; i < x; i++)
        cout << setw(5) << temp[i];

    return temp;
}
