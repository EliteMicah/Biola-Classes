#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string decrypt(string, string);

int main() {

    string cipherText = "Mom zgldmpx aspjl, lpw tedspbxk uywgsk, xjv kewrepvy deszgj tvp usmfl, ls tvxkxc h zijmgra wh tskl, ql'k nzox e vltwalisp tlhsv fhlw ty xjv akrb vn i fjmgeh.";
    string key = "thisisasecretkey";

    ofstream file("assignment1_2_Micah_Woodring.txt");

    string decryptedText = decrypt(cipherText, key);

    // Output to the console and file
    cout << decryptedText << endl;
    file << decryptedText << endl;

    file.close();

    cout << endl;
    system("pause");
    return 0;
}

string decrypt(string cipherText, string key) {
    string result = "";
    int cipherLength = cipherText.length();
    int keyLength = key.length();

    for (int i = 0; i < cipherLength; ++i) {
        if (isalpha(cipherText[i])) {

            // (cipherText[i] - 'a') converts text to numeric value
            // (key[i % keyLength] - 'a') converts key to numeric value
            // subtract key value from text value
            // + 26) make sure result isn't negative
            // % 26 + 'a' to convert back to alpha character
            char decryptedChar = ((cipherText[i] - 'a') - (key[i % keyLength] - 'a') + 26) % 26 + 'a';

            // add to result
            result.push_back(decryptedChar);
        }
        else {
            result.push_back(cipherText[i]);
        }
    }

    return result;
}
