#include "Phanso.h"
#include <iostream>
#include <algorithm>
using namespace std;

/* Constructor mặc định
   Đầu vào: Không có đầu vào.
   Đầu ra: Khởi tạo một đối tượng Phanso với tử số = 0 và mẫu số = 1.
   Hoạt động: Thiết lập giá trị mặc định cho phân số. */
Phanso::Phanso() : iTu(0), iMau(1) {}

/* Constructor với tham số 
   Đầu vào: Tử số (Tu) và mẫu số (Mau).
   Đầu ra: Khởi tạo đối tượng Phanso với các giá trị đầu vào, rút gọn phân số.
   Hoạt động: Gán tử và mẫu, sau đó gọi phương thức rút gọn. */
Phanso::Phanso(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    Rutgon(iTu, iMau);
}

/* Toán tử + (cộng phân số)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Kết quả phép cộng hai phân số, đã rút gọn.
   Hoạt động: Tính tử và mẫu mới, rút gọn kết quả, và trả về phân số mới. */
Phanso Phanso::operator+(const Phanso &ps) const {
    Phanso kq(iTu * ps.iMau + iMau * ps.iTu, iMau * ps.iMau);
    kq.Rutgon(kq.iTu, kq.iMau);
    return kq;
}

/* Toán tử - (trừ phân số)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Kết quả phép trừ hai phân số, đã rút gọn.
   Hoạt động: Tính tử và mẫu mới, rút gọn kết quả, và trả về phân số mới. */
Phanso Phanso::operator-(const Phanso &ps) const {
    Phanso kq(iTu * ps.iMau - iMau * ps.iTu, iMau * ps.iMau);
    kq.Rutgon(kq.iTu, kq.iMau);
    return kq;
}

/* Toán tử * (nhân phân số)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Kết quả phép nhân hai phân số, đã rút gọn.
   Hoạt động: Tính tử và mẫu mới, rút gọn kết quả, và trả về phân số mới. */
Phanso Phanso::operator*(const Phanso &ps) const {
    Phanso kq(iTu * ps.iTu, iMau * ps.iMau);
    kq.Rutgon(kq.iTu, kq.iMau);
    return kq;
}

/* Toán tử / (chia phân số)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Kết quả phép chia hai phân số, đã rút gọn; ném ngoại lệ nếu chia cho 0.
   Hoạt động: Tính tử và mẫu mới, kiểm tra chia cho 0, rút gọn kết quả, và trả về phân số mới. */
Phanso Phanso::operator/(const Phanso &ps) const {
    if (ps.iTu == 0) {
        throw std::invalid_argument("Khong the chia cho 0");
    }
    Phanso kq(iTu * ps.iMau, iMau * ps.iTu);
    kq.Rutgon(kq.iTu, kq.iMau);
    return kq;
}

/* Toán tử == (so sánh bằng)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu hai phân số bằng nhau, ngược lại false.
   Hoạt động: So sánh tử số và mẫu số của hai phân số. */
bool Phanso::operator==(const Phanso &ps) const {
    return iTu == ps.iTu && iMau == ps.iMau;
}

/* Toán tử != (so sánh khác)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu hai phân số khác nhau, ngược lại false.
   Hoạt động: Gọi toán tử == và đảo ngược kết quả. */
bool Phanso::operator!=(const Phanso &ps) const {
    return !(*this == ps);
}

/* Toán tử >= (so sánh lớn hơn hoặc bằng)
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu phân số hiện tại lớn hơn hoặc bằng phân số khác, ngược lại false.
   Hoạt động: So sánh hai phân số bằng cách nhân chéo. */
bool Phanso::operator>=(const Phanso &ps) const {
    return (iTu * ps.iMau >= iMau * ps.iTu);
}

/* Toán tử <= (so sánh nhỏ hơn hoặc bằng).
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu phân số hiện tại nhỏ hơn hoặc bằng phân số khác, ngược lại false.
   Hoạt động: So sánh hai phân số bằng cách nhân chéo. */
bool Phanso::operator<=(const Phanso &ps) const {
    return (iTu * ps.iMau <= iMau * ps.iTu);
}

/* Toán tử > (so sánh lớn hơn).
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu phân số hiện tại lớn hơn phân số khác, ngược lại false.
   Hoạt động: So sánh hai phân số bằng cách nhân chéo. */
bool Phanso::operator>(const Phanso &ps) const {
    return (iTu * ps.iMau > iMau * ps.iTu);
}

/* Toán tử < (so sánh nhỏ hơn).
   Đầu vào: Một đối tượng Phanso khác.
   Đầu ra: Trả về true nếu phân số hiện tại nhỏ hơn phân số khác, ngược lại false.
   Hoạt động: So sánh hai phân số bằng cách nhân chéo. */
bool Phanso::operator<(const Phanso &ps) const {
    return (iTu * ps.iMau < iMau * ps.iTu);
}

/* Phương thức rút gọn phân số
   Đầu vào: Tử số (Tu) và mẫu số (Mau).
   Đầu ra: Phân số được rút gọn (thay đổi trực tiếp trên Tu và Mau).
   Hoạt động: Tìm ước chung lớn nhất (GCD) của Tu và Mau, 
   sau đó chia cả hai cho GCD, trả về định dạng dấu phù hợp. */
void Phanso::Rutgon(int &Tu, int &Mau) {
    int gcd = __gcd(Tu, Mau);
    Tu /= gcd;
    Mau /= gcd;

    if (Mau < 0) {
        Tu = -Tu;
        Mau = -Mau;
    }
}

/* Toán tử << (xuất phân số)
   Đầu vào: Luồng xuất (os) và đối tượng Phanso (ps).
   Đầu ra: Phân số được in ra theo định dạng phù hợp.
   Hoạt động: Rút gọn phân số, sau đó kiểm tra để in tử số/mẫu số 
   hoặc số thực nếu mẫu rất lớn.     */
ostream &operator<<(ostream &os, const Phanso &ps) {
    Phanso rutgon = ps;
    rutgon.Rutgon(rutgon.iTu, rutgon.iMau);

    if (rutgon.iMau >= 1e4) {
        os << (float)rutgon.iTu / rutgon.iMau;
        return os;
    }
    if (rutgon.iMau == 1 || rutgon.iTu == 0) {
        os << rutgon.iTu;
    } else {
        os << rutgon.iTu << "/" << rutgon.iMau;
    }
    return os;
}

/* Toán tử >> (nhập phân số)
   Đầu vào: Luồng nhập (is) và đối tượng Phanso (ps).
   Đầu ra: Nhập giá trị cho tử số và mẫu số, rút gọn phân số.
   Hoạt động: Nhắc người dùng nhập tử số và mẫu số, kiểm tra để đảm bảo mẫu khác 0, 
   sau đó rút gọn */
istream &operator>>(istream &is, Phanso &ps) {
    cout << "\nNhap tu so: ";
    is >> ps.iTu;
    cout << "Nhap mau so: ";
    is >> ps.iMau;

    while (ps.iMau == 0) {
        cout << "Mau so phai khac 0. Nhap lai mau so: ";
        is >> ps.iMau;
    }

    ps.Rutgon(ps.iTu, ps.iMau);
    return is;
}

/* Phương thức Sothuc (chuyển số thực thành phân số)
   Đầu vào: Giá trị số thực (giatri).
   Đầu ra: Phân số tương ứng với số thực (được lưu trữ trong iTu và iMau).
   Hoạt động: Chuyển số thực thành phân số với độ chính xác mặc định là 1000000; 
              nếu độ chính xác vượt giới hạn thì giữ nguyên. */
void Phanso::Sothuc(double giatri) {
    int precision = 1000000;
    if (precision <= 1000000) {
        iMau = precision;
        iTu = static_cast<int>(giatri * precision);
    } else {
        iMau = 1;
        iTu = static_cast<int>(giatri);
    }
}

/* Toán tử + (cộng số thực với phân số)
   Đầu vào: Giá trị số thực (giatri).
   Đầu ra: Kết quả phép cộng phân số và số thực, đã rút gọn.
   Hoạt động: Chuyển số thực thành phân số, sau đó cộng với phân số hiện tại. */
Phanso Phanso::operator+(double giatri) const {
    Phanso psgiatri;
    psgiatri.Sothuc(giatri);
    return *this + psgiatri;
}

/* Toán tử - (trừ số thực với phân số)
   Đầu vào: Giá trị số thực (giatri).
   Đầu ra: Kết quả phép trừ phân số và số thực, đã rút gọn.
   Hoạt động: Chuyển số thực thành phân số, sau đó trừ từ phân số hiện tại. */
Phanso Phanso::operator-(double giatri) const {
    Phanso psgiatri;
    psgiatri.Sothuc(giatri);
    return *this - psgiatri;
}

/* Toán tử * (nhân số thực với phân số)
   Đầu vào: Giá trị số thực (giatri).
   Đầu ra: Kết quả phép nhân phân số và số thực, đã rút gọn.
   Hoạt động: Chuyển số thực thành phân số, sau đó nhân với phân số hiện tại. */
Phanso Phanso::operator*(double giatri) const {
    Phanso psgiatri;
    psgiatri.Sothuc(giatri);
    return *this * psgiatri;
}

/* Toán tử / (chia số thực với phân số)
   Đầu vào: Giá trị số thực (giatri).
   Đầu ra: Kết quả phép chia phân số cho số thực, đã rút gọn; ném ngoại lệ nếu chia cho 0.
   Hoạt động: Chuyển số thực thành phân số, kiểm tra chia cho 0, sau đó chia phân số hiện tại. */
Phanso Phanso::operator/(double giatri) const {
    if (giatri == 0) {
        throw std::invalid_argument("Khong the chia cho 0");
    }

    Phanso psgiatri;
    psgiatri.Sothuc(giatri);
    return *this / psgiatri;
}
