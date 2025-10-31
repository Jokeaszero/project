#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	const double DISCOUNT_THRESHOLD1 = 1000;
	const double DISCOUNT_RATE1 = 0.05;

	const double DISCOUNT_THRESHOLD2 = 2000;
	const double DISCOUNT_RATE2 = 0.07;

	const double DISCOUNT_THRESHOLD3 = 3000;
	const double DISCOUNT_RATE3 = 0.10;

	double costs;
	int quantity;
	double sum = 0;
	char lua_chon;

	cout << "--- CHUONG TRINH TINH TIEN BAN LE ---" << endl;


	do {
		
		cout << "Nhap don gia (don vi: nghin dong): ";
		cin >> costs;

		while (costs < 0) {
			cout << "Don gia khong hop le. Vui long nhap lai (>= 0): ";
			cin >> costs;
		}

		cout << "Nhap so luong: ";
		cin >> quantity;

		while (quantity < 0) {
			cout << "So luong khong hop le. Vui long nhap lai (>= 0): ";
			cin >> quantity;
		}

		sum += (costs * quantity);

		cout << "Ban co muon nhap tiep mon hang khac? (y/n): ";
		cin >> lua_chon;

	} while (lua_chon == 'y' || lua_chon == 'Y');

	double discount = 0.0;

	if (sum >= DISCOUNT_THRESHOLD3) { // Từ 3 triệu (3000 nghìn)
		discount = DISCOUNT_RATE3;
	}
	else if (sum >= DISCOUNT_THRESHOLD2) { // Từ 2 triệu (2000 nghìn)
		discount = DISCOUNT_RATE2;
	}
	else if (sum >= DISCOUNT_THRESHOLD1) { // Từ 1 triệu (1000 nghìn)
		discount = DISCOUNT_RATE1;
	}

	double so_tien_giam = sum * discount;
	double tong_thanh_toan = sum - so_tien_giam;

	cout << "--- HOA DON CUA BAN ---" << endl;
	cout << "Tong gia tri hoa don: " << fixed << setprecision(0) << sum * 1000 << " VND" << endl;

	if (so_tien_giam > 0) {
		cout << "Chiet khau (" << discount * 100 << "%):    -" << so_tien_giam * 1000 << " VND" << endl;
	}
	else {
		cout << "Chiet khau:             0 VND" << endl;
	}

	cout << "--------------------------" << endl;
	cout << "TONG THANH TOAN:        " << tong_thanh_toan * 1000 << " VND" << endl;

	return 0;
}