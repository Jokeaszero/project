#include <iostream>
#include <cmath>
using namespace std;

int ucln1(int a, int b){              // thuat toan eculid

		while (b != 0) {
			int tmp = a % b;
			a = b;
			b = tmp;
		}
		return a;
}
int ucln2(int a, int b) {             // recursive (de quy)
 	if (b == 0) {
		return a;
	}
	return ucln2(b, a % b);
}
int bcnn(int a, int b) {
	return a / ucln1(a, b) * b;
}
int main(){
	int a, b;
	cout << "nhap a: ";
	cin >> a;
	cout << "nhap b: ";
	cin >> b;

	cout << ucln1(a, b) << endl;
	cout << bcnn(a, b) << endl;

	return 0;
}