#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

template <class T>
void print(vector<T>);

template <class T>
void print(queue<T>);

double power(double base, int exponent);

template <class T>
bool find(const vector<T>& v, T value, int n);

template <class T>
void reversePrint(queue<T>);

int main() {

    cout << "Testing problem 1 ...\n\n";
    for (int i = 0; i < 5; i++) {
        double b = (rand() % 101 - 50) / 10.0;
        int a = rand() % 20;
        cout << b << "^" << a << " = " << power(b, a) << endl;
    }

    system("pause");
    system("cls");

    cout << "Testing problem 2 ...\n\n";
    vector<int> v(20);

    for (auto& x : v)
        x = rand() % 201 - 100;

    cout << " v = "; print(v); cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Enter a value to search for : ";
        int x;
        cin >> x;

        if (find(v, x, v.size()))
            cout << x << " is found.\n";
        else
            cout << x << " is not found.\n";
    }

    vector<char> vc(20);
    for (auto& x : vc)
        x = rand() % 26 + 96;

    cout << "\n\nvc = "; print(vc); cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Enter a char value to search for : ";
        char x;
        cin >> x;
        if (find(vc, x, vc.size()))
            cout << x << " is found.\n";
        else
            cout << x << " is not found.\n";
    }

    system("pause");
    system("cls");

    cout << "Testing problem 3 ...\n\n";
    queue<int> q;

    for (int i = 0; i < 10; i++) {
        int x = rand() % 201 - 100;
        q.push(x);
    }

    cout << " q = "; print(q); cout << endl;
    cout << "reverse q ="; reversePrint(q); cout << endl;
    queue<char> qc;

    for (int i = 0; i < 15; i++) {
        int x = rand() % 26 + 96;
        qc.push(x);
    }

    cout << " qc = "; print(qc); cout << endl;
    cout << "reverse qc ="; reversePrint(qc); cout << endl << endl;
    

    cout << endl;
    system("pause");
    exit(0);
}

double power(double base, int exponent) {

    if (exponent == 0)
        return 1;  //base case

    return base * power(base, exponent - 1); // Returning base * the function of expo - 1, cont)
}

template <class T>
bool find(const vector<T>& v, T value, int n) {

    if (n <= 0) // Base case and if n is neg then return false
        return false;

    if (v[n - 1] == value) // If found then return true
        return true;

    n--; // Reduce n by 1
    find(v, value, n); // Recursion
}

template <class T>
void reversePrint(queue<T> q) {

    if (q.empty()) // Checking for empty queue
        return;

    auto x = q.front();
    q.pop(); // Remove top num
    reversePrint(q); // Recursion
    cout << x << ", "; // Print

}

template <class T>
void print(vector<T> v) {
    for (auto x : v)
        cout << setw(5) << x;
}

template <class T>
void print(queue<T> q) {
    while (!q.empty()) {
        cout << setw(5) << q.front();
        q.pop();
    }
}
