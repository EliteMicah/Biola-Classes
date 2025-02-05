#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

void binaryToUnsignedDec(string);
void encodeBinary(string);
void signedToUnsigned(string);
void unsignedToSigned(string);

int main() {

    cout << "Welcome to my program!" << endl << endl;
    cout << "Please enter any of the following to convert:" << endl;
    cout << "   1 - Binary to unsigned decimal" << endl;
    cout << "   2 - Encode a binary value to the word size in bits" << endl;
    cout << "   3 - Two's Complement Signed to Unsigned Conversion" << endl;
    cout << "   4 - Unsigned to Two's Complement Signed Conversion" << endl;
    cout << "   0 - Quit" << endl << endl;


p: // Waypoint

    cout << ">>> ";

    string s = "";
    string number = "";

    // Getting Input
    getline(cin, s);
    int stringsize = s.length();

    // Converting string to lowercase
    for (int i = 0; i < stringsize; i++) 
        s[i] = tolower(s[i]);

    //  QUIT
    if (s == "0" || s == "quit")
        exit(0);

    // Binary to unsigned decimal
    else if (s == "1") {
        cout << "Please enter a binary number: ";
        getline(cin, number);
        binaryToUnsignedDec(number);
    }

    // Encoding a binary value
    else if (s == "2") {
        cout << "Please enter a binary number: ";
        getline(cin, number);
        encodeBinary(number);
    }

    // Two’s Complement Signed to Unsigned Conversion
    else if (s == "3") {
        cout << "Please enter a signed(pos or neg) decimal integer number: ";
        getline(cin, number);
        signedToUnsigned(number);
    }

    // Unsigned to Two’s Complement Signed Conversion
    else if (s == "4") {
        cout << "Please enter an unsigned(positive) decimal integer: ";
        getline(cin, number);
        unsignedToSigned(number);
    }

    else
        cout << "\tInvalid Input" << endl;

    cout << endl;
    goto p;
}

void binaryToUnsignedDec(string val) { // pg207

    // Making unsigned int
    unsigned int result = 0;

    for (int i = 0; i < val.length(); i++) {
        if (val[i] == '1') {
            // Adds 2 to the power of val.length() - i - 1 to result
            result += pow(2, val.length() - i - 1);
        }
    }

    cout << "\t" << result;
}

void encodeBinary(const string val) { // pg210

    string dec = "";
    cout << "Please enter the word size: ";
    getline(cin, dec);
    int wordSize = stoi(dec);

    int result = 0;
    int counter = 0;

    for (int i = val.length() - 1; i > 0; i--) {

        // Converting char to int and multiplies 2 to the power of the counter
        result += ((val[i]) - '0') * pow(2, counter);
        counter++;
    }

    // Negating the value, converting char to int, multiplying by power of 2
    result += (-(val[0] - '0') * pow(2, val.length() - 1));

    // If it is default word size then print
    if (wordSize == 4)
        cout << "\t" << result;
    else {

        // Converting to the user's word size
        int temp = 0;
        temp += pow(2, wordSize);
        temp %= result;

        cout << "\t" << temp;
    }
}

void signedToUnsigned(string val) {

    string dec = "";
    cout << "Please enter the word size: ";
    getline(cin, dec);
    int wordSize = stoi(dec);

    int num = stoi(val);
    cout << "\t";

    // If num is Positive then print
    if (num >= 0)
        cout << num;

    // If num is negative, gives the unsigned number but with 32 bits
    else {
        
        // Creating temp that takes the num and adds 2 to the power of the word size
        // then prints
        int temp = (num + pow(2, wordSize));
        cout << temp;
    }
}

void unsignedToSigned(string val) {

    string dec = "";
    cout << "Please enter the word size: ";
    getline(cin, dec);
    int wordSize = stoi(dec);

    cout << "\t";

    // Getting the unsigned number
    unsigned int num = stoi(val);

    // Getting the max number
    int temp = 0, maxNum = pow(2, wordSize -1) - 1;

    // If num is less than (or equal to) its max then print
    if (num <= maxNum)
        cout << num;

    // If num is more than its max then decrease it
    else {
        temp = (num - pow(2, wordSize));
        cout << temp;
    }
}
