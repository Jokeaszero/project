#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string tenSinhVien;
    double diemThi;
    int soSinhVienDat = 0;
    int soSinhVienKhongDat = 0;

    cout << "--- CHUONG TRINH QUAN LY DIEM THI ---" << endl;

    while (true) {
        cout << "Nhap ten sinh vien (hoac nhap 'X' de ket thuc): ";

        getline(cin, tenSinhVien);

        if (tenSinhVien == "X" || tenSinhVien == "x") {
            break;
        }

        while (true) {
            cout << "Nhap diem thi cho sinh vien " << tenSinhVien << ": ";

            if (!(cin >> diemThi)) {
                cout << "Loi: Diem phai la mot con so. Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (diemThi < 0.0 || diemThi > 10.0) {
                cout << "Loi: Diem khong hop le. Vui long nhap lai (tu 0 den 10).\n";
            }
            else {
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (diemThi >= 5.0) {
            soSinhVienDat++;
        }
        else {
            soSinhVienKhongDat++;
        }
    }

    cout << "\n--- KET QUA TONG KET ---" << endl;

    cout << "Bang phan loai diem:" << endl;
    cout << "- Dat yeu cau: Diem thi tu 5.0 tro len." << endl;
    cout << "- Khong dat yeu cau: Diem thi duoi 5.0." << endl;
    cout << "---------------------------------------" << endl;

    cout << "Tong so sinh vien dat yeu cau: " << soSinhVienDat << endl;
    cout << "Tong so sinh vien khong dat yeu cau: " << soSinhVienKhongDat << endl;

    return 0;
}




















/*int main() {
    // 1. Tạo một vector để lưu trữ các chuỗi
    std::vector<std::string> danhSachChuoi;
    std::string chuoiNhapVao;

    std::cout << "Nhap vao cac chuoi (nhan Enter de ket thuc):" << std::endl;

    // 2. Bắt đầu vòng lặp để nhận đầu vào
    // std::getline dùng để đọc cả dòng (bao gồm cả khoảng trắng)
    while (std::getline(std::cin, chuoiNhapVao)) {

        // 3. Kiểm tra điều kiện dừng (nếu chuỗi nhập vào là rỗng)
        if (chuoiNhapVao.empty()) {
            break; // Thoát khỏi vòng lặp while
        }

        // 4. Lưu trữ chuỗi vào vector
        danhSachChuoi.push_back(chuoiNhapVao);
    }

    // 5. In ra các chuỗi đã lưu trữ
    std::cout << "\n--- Ban da luu tru cac chuoi sau: ---" << std::endl;

    // Kiểm tra xem vector có rỗng không
    if (danhSachChuoi.empty()) {
        std::cout << "(Khong co chuoi nao duoc luu)" << std::endl;
    }
    else {
        // Dùng vòng lặp for-each để duyệt qua vector
        for (const std::string& s : danhSachChuoi) {
            std::cout << s << std::endl;
        }
    }

    return 0;
} */