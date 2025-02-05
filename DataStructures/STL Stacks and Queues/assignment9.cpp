#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void removeNonAlphaNum(stack<char>&);

template <class T>
void reverse(queue<T>&);

bool balancedDelimiters(string);

int main() {
    

    cout << endl;
    system("pause");
    exit(0);
}


void removeNonAlphaNum(stack<char>& s) {

    stack<char> temp;

    while (!s.empty()) { // Loop of s
        auto x = s.top();
        temp.push(x); // Transfer to temp
        s.pop(); // Then remove top
    }

    while (!temp.empty()) { // Loop of temp
        auto x = temp.top();
        if (isalpha(x) || isdigit(x)) { // Check for alpha / digit
            s.push(x); // Push if true
        }
        temp.pop(); // Pop if false
    }
}

template <class T>
void reverse(queue<T>& q) {

    stack<T> temp; // Temp Stack

    while (!q.empty()) { // Loop of q
        auto x = q.front();
        temp.push(x); // Push top of q into temp
        q.pop(); // Then remove top
    }

    while (!temp.empty()) { // Loop of temp
        auto x = temp.top();
        q.push(x); // Push top of temp into q
        temp.pop(); // Then remove top
    }

}

bool balancedDelimiters(string s) {

    stack<char> s1; // Cycle through each chars

    for (auto x : s) { // Loop
        if (x == '(') // Check for intro
            s1.push(x); // Insert into stack
        else if (x == '[')
            s1.push(x);
        else if (x == '{')
            s1.push(x);

        if (x == ')') { // Check for outro's
            if (s1.empty() || s1.top() != '(') // Check if top matches intro
                return false; // Return false if does not match
            s1.pop(); // Remove once passed
        }
        else if (x == ']') {
            if (s1.empty() || s1.top() != '[')
                return false;
            s1.pop();
        }
        else if (x == '}') {
            if (s1.empty() || s1.top() != '{')
                return false;
            s1.pop();
        }
    }

    if (s1.empty()) // True if all match
        return true;
    else
        return false;

    return false;
}
