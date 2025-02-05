#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string decrypt(string, string, int);

int main() {

    string cipherText = "hpGsl7pG46nnp44q6ww0G5lvpyGnzy53zwGzqG5spGpypx0G4611w0GwtypKGcptyqz3npxpy54Gl3pGpyG3z65pG5zGz63G1z4t5tzyKGZ63G4nz654Gsl7pG3p1z35poGspl70Gpypx0Gln5t7t50Gl5G5spGyz35sKGhpGyppoG5zGmpG13p1l3poGqz3GlyGl55lnvGl5Gol8yK";
    string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?,.";
    int symLength = symbols.length();

    ofstream file("assignment1_1_Micah_Woodring.txt");

    for (int i = 1; i <= symLength; i++) {
        string decryptedText = decrypt(cipherText, symbols, i);

        // Output to the console and file
        cout << "Key " << i << ": " << decryptedText << endl << endl;
        file << "Key " << i << ": " << decryptedText << endl << endl;
    }

    file.close();

    cout << endl;
    system("pause");
    return 0;
}


string decrypt(string cipherText, string symbols, int key) {
    string result = "";
    int symLength = symbols.length();

    for (char ch : cipherText) {
        if (isalpha(ch) || isdigit(ch) || ch == ' ' || ch == '!' || ch == '?' || ch == ',' || ch == '.') {

            // If char found, = index
            int index = symbols.find(ch);

            // Subtract key from the current index
            // Add symLength to make sure its not negative
            // Modulus % by symLength to make sure the result is in right range
            index = (index - key + symLength) % symLength;

            // Add index to the result string
            result += symbols[index];
        }
        else {
            result += ch;
        }
    }

    return result;
}
