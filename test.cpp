#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// const cost
const double GRABBIKE_FIRST2KM = 12000;
const double GRABBIKE_AFTER2KM = 9000;

const double GRABCAR4_FIRST2KM = 15000;
const double GRABCAR4_AFTER2KM = 11000;

const double GRABCAR7_FIRST2KM = 17000;
const double GRABCAR7_AFTER2KM = 13000;

const double PHU_PHI_CAO_DIEM = 0.10; // 10%

int main() {
    int chon;
    double km, gio, tongTien, giaCoBan;
    string loaiXe;

    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. GrabBike" << endl;
        cout << "2. GrabCar (4 cho)" << endl;
        cout << "3. GrabCar (7 cho)" << endl;
        cout << "4. Thoat" << endl;
        cout << "===========================" << endl;
        cout << "Lua chon cua ban: ";
        cin >> chon;

        if (chon == 4) {
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;
        }
        else if (chon < 1 || chon > 4) {
            cout << "Gia tri khong hop le! Vui long nhap lai." << endl;
            continue;
        }

        cout << "Nhap so km di chuyen: ";
        cin >> km;
        cout << "Nhap gio khoi hanh (vd: 8 hoac 17): ";
        cin >> gio;

        if (chon == 1) {
            loaiXe = "GrabBike";
            if (km <= 2)
                giaCoBan = km * GRABBIKE_FIRST2KM;
            else
                giaCoBan = 2 * GRABBIKE_FIRST2KM + (km - 2) * GRABBIKE_AFTER2KM;
        }
        else if (chon == 2) {
            loaiXe = "GrabCar (4 cho)";
            if (km <= 2)
                giaCoBan = km * GRABCAR4_FIRST2KM;
            else
                giaCoBan = 2 * GRABCAR4_FIRST2KM + (km - 2) * GRABCAR4_AFTER2KM;
        }
        else if (chon == 3) {
            loaiXe = "GrabCar (7 cho)";
            if (km <= 2)
                giaCoBan = km * GRABCAR7_FIRST2KM;
            else
                giaCoBan = 2 * GRABCAR7_FIRST2KM + (km - 2) * GRABCAR7_AFTER2KM;
        }

        // check peak time
        double phuPhi = 0;
        if ((gio >= 7 && gio <= 9) || (gio >= 17 && gio <= 19)) {
            phuPhi = giaCoBan * PHU_PHI_CAO_DIEM;
        }

        tongTien = giaCoBan + phuPhi;

        cout << fixed << setprecision(0);
        cout << "----- HOA DON -----" << endl;
        cout << "Loai phuong tien: " << loaiXe << endl;
        cout << "So km di chuyen: " << km << " km" << endl;
        cout << "Gio khoi hanh: " << gio << "h" << endl;
        cout << "Gia cuoc co ban: " << giaCoBan << " VND" << endl;
        if (phuPhi > 0)
            cout << "Phu phi gio cao diem: " << phuPhi << " VND" << endl;
        cout << "Tong tien: " << tongTien << " VND" << endl;
        cout << "-------------------" << endl;

    } while (chon != 4);

    return 0;
}