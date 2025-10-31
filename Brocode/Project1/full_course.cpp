#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int choice;
	do {
		cout << "1. Hello world" << endl;
		cout << "2. What's your name" << endl;
		cout << "3. How old are you" << endl;
		cout << "0. Exit" << endl;
		cout << "This is you choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			string hello;
			cout << "Hello ";
			cin >> hello;
			break;
		}
		case 2: {
			string name;
			cout << "My name is ";
			cin >> name;
			break;
		}
		case 3: {
			string years_old;
			cout << "I am ";
			cin >> years_old;
			cout << years_old << " years old" << endl;
			break;
		}
		case 0:
			cout << "Exit program!";
			break;
		default:
			cout << "Invalid program @@@" << endl << "Let's start over" << endl;
		}
	} while (choice != 0);
	
	return 0;
}