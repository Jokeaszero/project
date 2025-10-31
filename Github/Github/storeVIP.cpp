#include <iostream>
#include <iomanip>
#include <string>
#include <limits> 
#include <sstream> 

using namespace std;

int main() {
	const double DISCOUNT_THRESHOLD1 = 1000;
	const double DISCOUNT_RATE1 = 0.05;
	const double DISCOUNT_THRESHOLD2 = 2000;
	const double DISCOUNT_RATE2 = 0.07;
	const double DISCOUNT_THRESHOLD3 = 3000;
	const double DISCOUNT_RATE3 = 0.10;
	
	string item;
	double costs;
	int quantity;
	double sum = 0;
	char lua_chon;

	
	stringstream chi_tiet_hoa_don_ss;

	chi_tiet_hoa_don_ss << "--- CHI TIET MUA HANG ---\n";
	chi_tiet_hoa_don_ss << left << setw(20) << "Ten Hang"
		<< right << setw(10) << "Don Gia"
		<< setw(5) << " SL"
		<< setw(12) << "Thanh Tien" << endl;
	chi_tiet_hoa_don_ss << "-----------------------------------------------\n";


	cout << "--- CHUONG TRINH TINH TIEN BAN LE ---" << endl;

	do {
		cout << "Vui long nhap ten hang hoa ban muon mua: ";
		getline(cin, item);

		cout << "Nhap don gia (don vi: nghin dong): ";
		while (!(cin >> costs) || costs < 0) {
			cout << "Gia tri khong hop le. Vui long nhap lai (so >= 0): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "Nhap so luong: ";
		while (!(cin >> quantity) || quantity < 0) {
			cout << "So luong khong hop le. Vui long nhap lai (so >= 0): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		double thanh_tien_mon_hang = costs * quantity;
		sum += thanh_tien_mon_hang;

		chi_tiet_hoa_don_ss << fixed << setprecision(0);
		chi_tiet_hoa_don_ss << left << setw(20) << item.substr(0, 19)
			<< right << setw(10) << costs * 1000
			<< setw(5) << quantity
			<< setw(12) << thanh_tien_mon_hang * 1000 << endl;


		cout << "Ban co muon nhap tiep mon hang khac? (y/n): ";
		cin >> lua_chon;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (lua_chon == 'y' || lua_chon == 'Y');

	// (Phần tính toán chiết khấu giữ nguyên)
	double discount = 0.0;
	if (sum >= DISCOUNT_THRESHOLD3) {
		discount = DISCOUNT_RATE3;
	}
	else if (sum >= DISCOUNT_THRESHOLD2) {
		discount = DISCOUNT_RATE2;
	}
	else if (sum >= DISCOUNT_THRESHOLD1) {
		discount = DISCOUNT_RATE1;
	}
	double so_tien_giam = sum * discount;
	double tong_thanh_toan = sum - so_tien_giam;

	cout << chi_tiet_hoa_don_ss.str();

	cout << "\n--- TONG KET HOA DON ---" << endl;
	cout << fixed << setprecision(0);
	cout << left << setw(25) << "Tong gia tri hoa don:"
		<< right << setw(12) << sum * 1000 << " VND" << endl;

	if (so_tien_giam > 0) {
		string chiet_khau_str = "Chiet khau (" + to_string((int)(discount * 100)) + "%):";
		cout << left << setw(25) << chiet_khau_str
			<< right << setw(12) << -so_tien_giam * 1000 << " VND" << endl;
	}
	else {
		cout << left << setw(25) << "Chiet khau:"
			<< right << setw(12) << "0 VND" << endl;
	}

	cout << "---------------------------------------" << endl;
	cout << left << setw(25) << "TONG THANH TOAN:"
		<< right << setw(12) << tong_thanh_toan * 1000 << " VND" << endl;

	return 0;
}