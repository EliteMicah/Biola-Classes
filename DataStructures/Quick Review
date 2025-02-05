#include <iostream>
#include <vector>
using namespace std;

bool allLowerCase(string);
int largerThanAverage(double[], int);
vector<double> merge(vector<double>, vector<double>);


int main() {

    cout << endl;
    system("pause");
    exit(0);
}


bool allLowerCase(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i]))
            return false;
    }

    return true;
}

int largerThanAverage(double A[], int k) {
    double average = 0;
    int count = 0;

    for (int i = 0; i < k; i++) {
        average += A[i];
    }

    average = average / k;

    for (int i = 0; i < k; i++) {
        if (A[i] > average)
            count++;
    }

    return count;
}

vector<double> merge(vector<double> v1, vector<double> v2) {

    for (int i = 0; i < v2.size(); i++)
        v1.push_back(v2[i]);

    for (int i = 0; i < v1.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < v1.size(); j++)
            if (v1[j] < v1[min_index])
                min_index = j;
        swap(v1[i], v1[min_index]);
    }

    return v1;
}
