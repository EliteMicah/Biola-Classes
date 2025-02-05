#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "bst.h"
using namespace std;


int main() { 

    for (int j = 0; j < 3; j++) {

        BST<int> t;
        int n = rand() % 15 + 5;
        system("cls");
        cout << "A Binary Search Tree: \n\n";
        for (int i = 0; i < n; i++) {
            int x = rand() % 100;
            t.insert(x);
        }
        t.displayTree();
        cout << endl;
        //cout << "The largest element is : " << t.largestElement() << endl;
        //cout << "The number of leaves on the tree is : " << t.leaves() << endl;
        cout << "The sum of all the nodes is : " << t.sum() << endl;
        system("pause");
    }
    
    

    cout << endl;
    system("pause");
    return 0;
}
