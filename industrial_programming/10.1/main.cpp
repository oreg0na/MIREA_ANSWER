#include <iostream>

using namespace std;

int main() {
    double** p = nullptr;
    p = new double*;
    *p = new double;
    cin >> **p;
    cout << **p;
    delete *p;
    delete p;
}
