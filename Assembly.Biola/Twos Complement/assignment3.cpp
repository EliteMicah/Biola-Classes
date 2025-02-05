#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

void addition(string, string);
void negationn(string);
void multiplication(string, string);
void divisionByPowerofTwo(string, string);

int main() {

    cout << "Welcome to my program!" << endl << endl;
    cout << "Please enter any of the following to convert:" << endl;
    cout << "   1 - Two's Complement Addition" << endl;
    cout << "   2 - Two's Complement Negation" << endl;
    cout << "   3 - Two's Complement Multiplication" << endl;
    cout << "   4 - Two's Complement Division by Power of Two" << endl;
    cout << "   0 - Quit" << endl << endl;


p: // Waypoint

    cout << ">>> ";

    string s = "";
    string num1 = "";
    string num2 = "";


    // Getting Input
    getline(cin, s);
    int stringsize = s.length();

    // Converting string to lowercase
    for (int i = 0; i < stringsize; i++) 
        s[i] = tolower(s[i]);

    //  QUIT
    if (s == "0" || s == "quit")
        exit(0);

    // ADDITION
    else if (s == "1") {
        cout << "Please enter the first decimal integer: ";
        getline(cin, num1);
        cout << "Please enter the second decimal integer: ";
        getline(cin, num2);
        addition(num1, num2);
    }

    // NEGATION
    else if (s == "2") {
        cout << "Please enter a decimal integer: ";
        getline(cin, num1);
        negationn(num1);
    }

    // MULTIPLICATION
    else if (s == "3") {
        cout << "Please enter the first decimal integer: ";
        getline(cin, num1);
        cout << "Please enter the second decimal integer: ";
        getline(cin, num2);
        multiplication(num1, num2);
    }

    // Two’s Complement Division by Power of Two
    else if (s == "4") {
        cout << "Please enter a decimal integer: ";
        getline(cin, num1);
        cout << "Please enter a number in the power of 2 to divide by: ";
        getline(cin, num2);
        divisionByPowerofTwo(num1, num2);
    }

    else
        cout << "\tInvalid Input" << endl;

    cout << endl;
    goto p;
}

void addition(string X, string Y) { // pg268

    string ws = "";
    cout << "Please enter a word size: ";
    getline(cin, ws);

    int varX = stoi(X);
    int varY = stoi(Y);
    int wordSize = stoi(ws);
    int result = 0;

    // Getting the TMin & TMax
    double min = -pow(2, wordSize - 1);
    double mid = pow(2, wordSize - 1);
    double max = pow(2, wordSize - 1) - 1;

    // Checking if varX and varY is within boundaries
    if (varX < min || varY < min || varX > max || varY > max) {
        cout << "Variables not within boundaries" << endl;
        exit(0);
    }

    // Positive overflow x+y-2w, 2w-1 <= x+y
    if (mid <= (varX + varY))
        result = varX + varY - pow(2, wordSize);

    // Normal overflow x+y, -2w-1 <= x+y < 2w-1
    else if (min <= (varX + varY) && (varX + varY) < mid)
        result = varX + varY;

    // Negative overflow x+y+2w, x+y < -2w-1
    else if ((varX + varY) < min)
        result = varX + varY + pow(2, wordSize);

    cout << "\t" << result;
}

void negationn(string X) { // pg279

    string ws = "";
    cout << "Please enter a word size: ";
    getline(cin, ws);

    int varX = stoi(X);
    int wordSize = stoi(ws);
    int result = 0;

    // Getting the TMin & TMax
    double min = -pow(2, wordSize - 1);
    double max = pow(2, wordSize - 1) - 1;

    // Checking if varX and varY is within boundaries
    if (varX < min || varX > max) {
        cout << "Variable not within boundaries" << endl;
        exit(0);
    }

    // First Case TMinw, x = TMinw
    if (varX == min)
        result = min;

    // Second Case -x, x > TMinw
    else if (varX > min)
        result = -varX;

    cout << "\t" << result;
}

void multiplication(string X, string Y) { // pg 231 & pg284

    string ws = "";
    cout << "Please enter a word size: ";
    getline(cin, ws);

    int varX = stoi(X);
    int varY = stoi(Y);
    int wordSize = stoi(ws);
    int result = 0;
    int unSign = 0;

    // Getting the TMin & TMax
    double min = -pow(2, wordSize - 1);
    int mid = pow(2, wordSize);
    double max = pow(2, wordSize - 1) - 1;

    // Checking if varX and varY is within boundaries for unsigned
    if (varX < min || varY < min || varX > max || varY > max) {
        cout << "Variables not within boundaries" << endl;
        exit(0);
    }

    // Unsigned (x*y) mod 2w
    unSign = (varX * varY) % mid;

    cout << "\t" << unSign;

    // Book doesn't really say what "u" is, and the instructions are 
    // very unclear on how we're supposed to implement it in our equation
    // Here is my best try...

    // Checking if varX and varY is within boundaries for two's multiplication
    /*
    if (varX < min || varY < min || varX > max || varY > max) {
        cout << "Variables not within boundaries x2" << endl;
        exit(0);
    }
    // U2Tw = {u, u >= TMaxw u - 2w, u > TMaxw (u being varX or varY)
    if (varX >= ((max * varX) - mid) || varX > max)
        trun1 = varX;
    if (varY >= ((max * varY) - mid) || varY > max)
        trun2 = varY;

    // x * wty = U2Tw((x*y) mod 2w)
    result = (unSign) * ((varX * varY) % mid);

    cout << "\tresult - " << result; 
    */
}

void divisionByPowerofTwo(string X, string Y) { // pg300

    int varX = stoi(X);
    int varK = stoi(Y);
    int result = 0;

    // My attempt at doing the rounding up and rounding down calculations
    // but then I found the calculation on pg307 so idk
    // 
    // If varK >= 0 then do rounding up calculation
    /*
    if (varK >= 0) {
        result = (varX + (1 << varK) - 1) >> varK;
    }
    else {
        // Rounding down
        result = varX >> varK;
    }
    */

    // pg307 calculation
    result = (varX < 0 ? varX + (1 << varK) - 1 : varX) >> varK;

    cout << "\t" << result;
}
