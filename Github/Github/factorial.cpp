// use func tgamma in cmath, n! = T(n+1)
#include <iostream>
#include <cmath>
using namespace std;

double combination(int n, int k) {
    if (k < 0 || k > n) {
        cout << "Khong hop le: k phai nam trong [0, n]" << endl;
        return 0;
    }
    return tgamma(n + 1) / (tgamma(k + 1) * tgamma(n - k + 1));
}

double permutation(int n, int k) {
    if (k < 0 || k > n) {
        cout << "Khong hop le: k phai nam trong [0, n]" << endl;
        return 0;
    }
    return tgamma(n + 1) / tgamma(n - k + 1);
}

int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;

    double C = combination(n, k);
    double P = permutation(n, k);

    cout << "C(" << n << ", " << k << ") = " << C << endl;
    cout << "P(" << n << ", " << k << ") = " << P << endl;
    return 0;
}
