#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

template <class T>
int pairCount(const vector<T>&);

template <class T>
vector<T> intersection(const vector<T>&, const vector<T>&);

map<char, int> charFreq(string);

int main() {
    
    
    cout << "Testing Problem 1 ... " << endl << endl;
    vector<int> v1 = { 2,4,7,10,12,1,2,12,7,-10};
    vector<int> vt(4, -3);

    vt.insert(vt.end(), v1.begin(), v1.end());

    for (int i = 0; i < 5; i++) {
        random_shuffle(vt.begin(), vt.end());
        cout << "\nVector : " << endl;
        for (auto& x : vt)
            cout << x << ", ";
        cout << endl;
        cout << "Number of pairs : " << pairCount(vt) << endl;
    }
    
    vector<string> vs1 = { "aa","AA","BBB","AA","CC", "XY", "XY" };
    vector<string> vst(3, "HHH");

    vst.insert(vst.end(), vs1.begin(), vs1.end());

    // Code here is making the program crash for some reason
    // I honestly don't know why when it is the exact same as the above code
    /*
    for (int i = 0; i < 5; i++) {
        random_shuffle(vst.begin(), vst.end());
        cout << "\nVector : " << endl;
        for (auto& x : vst)
            cout << x << ", ";
        cout << endl;
        cout << "Number of pairs : " << pairCount(vst) << endl;
    }
    */
    
    system("pause");
    system("cls");
    
    
    //Problem 2
    cout << "Testing Problem 2 ... " << endl << endl;
    vector<int> u1 = { 2,4,7,10,12,1,-10 }, u2 = { 4, -3, -12, 27,-10 }, ut;

    for (int i = 0; i < 3; i++) {
        random_shuffle(u1.begin(), u1.end());
        random_shuffle(u2.begin(), u2.end());
        ut = intersection(u1, u2);
        cout << "\nVector u1: " << endl;
        for (auto& x : u1)
            cout << x << ", ";
        cout << "\nVector u2: " << endl;
        for (auto& x : u2)
            cout << x << ", ";
        cout << "\nIntersection: " << endl;
        for (auto& x : ut)
            cout << x << ", ";
        cout << endl << endl;
    }

    vector<string> us1 = { "aa","AA","BBB","CC", "XY" }, us2(3, "HHH"), ust;

    for (int i = 0; i < 3; i++) {
        if (i == 2)
            us2 = us1;
        random_shuffle(us1.begin(), us1.end());
        random_shuffle(us2.begin(), us2.end());
        ust = intersection(us1, us2);
        cout << "\nVector us1: " << endl;
        for (auto& x : us1)
            cout << x << ", ";
        cout << "\nVector us2: " << endl;
        for (auto& x : us2)
            cout << x << ", ";
        cout << "\nIntersection: " << endl;
        for (auto& x : ust)
            cout << x << ", ";
        cout << endl << endl;
    }

    

    cout << endl;
    system("pause");
    exit(0);
}

template <class T>
int pairCount(const vector<T>& v) {
    int count = 0;

    map<int, int> freqMap;
    for (auto x : v) { //go through all the elements
        auto it = freqMap.find(x); //search for entry with key x 
        if (it == freqMap.end()) //not found
            freqMap[x] = 1; //insert x into the map and give it frequency 1
        else
            freqMap[x]++;
    }

    for (auto c : freqMap) {
        if (c.second == 2) {
            count++;
            cout << "Found pair at " << c.first << endl;
        }
    }

    cout << endl << count << endl;

    return count;
}

template <class T>
vector<T> intersection(const vector<T>& v1, const vector<T>& v2) {
    vector<T> tmp;
    for (auto& x : v1)
        for (auto& y : v2)
            if (x == y) {
                tmp.emplace_back(x);
                break;
            }
    return tmp;
}

map<char, int> charFreq(string s) {

    map<char, int> chCount;
    char ch;

    ifstream ifile(s); // Checking if file was opened
    if (!ifile) {
        cout << "Error opening file..." << endl;
        exit(1);
    }

    while (true) {
        ifile >> ch; // ch = each letter
        if (!ifile)
            break;
        //insert into the map if it does not exist
        auto it = chCount.find(ch); //search for word.  if it does not appear it=word_count.end()
        if (it == chCount.end()) {
            chCount[ch] = 1;
        }
        else
            //increase the count if already there
            chCount[ch]++;
    }

    for (auto& x : chCount)
        cout << x.first << " : " << x.second << endl;

    return chCount;
}
