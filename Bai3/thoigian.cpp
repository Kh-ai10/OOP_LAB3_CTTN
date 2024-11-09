#include "thoigian.h"
#include <iostream>
using namespace std;

/* Constructor mặc định (khởi tạo Thoigian với giá trị mặc định)
   Đầu vào: Không có.
   Đầu ra: Khởi tạo đối tượng Thoigian với giờ, phút, giây là 0.
   Hoạt động: Khởi tạo một đối tượng Thoigian mới với giờ, phút, giây được 
   gán giá trị mặc định là 0. */
Thoigian::Thoigian() : iGio(0), iPhut(0), iGiay(0) {}

/* Constructor với tham số 
   Đầu vào: 3 tham số: Gio (giờ), Phut (phút), Giay (giây).
   Đầu ra: Khởi tạo đối tượng Thoigian với giờ, phút, giây theo giá trị nhập vào.
   Hoạt động: Khởi tạo một đối tượng Thoigian với các giá trị giờ, phút, giây được cung cấp, 
   sau đó tính toán lại giờ, phút, giây hợp lệ. */
Thoigian::Thoigian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    // Tính toán lại thời gian nếu giờ, phút, giây không hợp lệ
    TinhLaiGio(0);  // Sử dụng hàm tính lại giờ để điều chỉnh nếu cần
}

/* Hàm TinhGiay (Tính tổng số giây từ giờ, phút, giây)
   Đầu vào: Không có.
   Đầu ra: Trả về tổng số giây tính từ giờ, phút, giây của đối tượng Thoigian.
   Hoạt động: Tính toán tổng số giây từ các thành phần giờ, phút, giây của đối tượng 
   Thoigian và trả về kết quả. */
int Thoigian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

/* Hàm TinhLaiGio (Tính lại giờ, phút, giây sau khi cộng hoặc trừ số giây)
   Đầu vào: Số giây cần cộng hoặc trừ (Giay).
   Đầu ra: Trả về một đối tượng Thoigian mới với giờ, phút, giây đã được tính lại.
   Hoạt động: Tính tổng giây sau khi cộng hoặc trừ số giây vào thời gian hiện tại, 
   sau đó tính toán lại giờ, phút, giây và trả về đối tượng Thoigian mới đã được tính toán. */
Thoigian Thoigian::TinhLaiGio(int Giay) {
    int tong_giay = TinhGiay() + Giay;

    if (tong_giay < 0) {
        return Thoigian(0, 0, 0);  // Trả về thời gian 0 nếu kết quả âm
    }

    int gio = tong_giay / 3600;
    int phut = (tong_giay % 3600) / 60;
    int giay = tong_giay % 60;

    return Thoigian(gio, phut, giay);
}

    /* Toán tử + (cộng thời gian với số giây)
   Đầu vào: Số giây cần cộng (Giay).
   Đầu ra: Trả về một đối tượng Thoigian mới sau khi cộng số giây vào thời gian hiện tại.
   Hoạt động: Gọi hàm Tinhlaigio() để tính toán sau đó trả về thời gian mới đã tính toán. */
Thoigian Thoigian :: operator+(int Giay) {
    return TinhLaiGio(Giay);
}

/* Toán tử - (trừ thời gian với số giây)
   Đầu vào: Số giây cần trừ (Giay).
   Đầu ra: Trả về một đối tượng Thoigian mới sau khi trừ số giây từ thời gian hiện tại.
   Hoạt động: Gọi hàm Tinhlaigio() để tính toán sau đó trả về thời gian mới đã tính toán. */
Thoigian Thoigian :: operator-(int Giay) {
    return TinhLaiGio(-Giay);
}

/* Toán tử + (cộng hai đối tượng Thoigian)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về một đối tượng Thoigian mới là tổng của thời gian hai đối tượng.
   Hoạt động: Cộng giờ, phút và giây của hai đối tượng Thoigian và 
   trả về đối tượng Thoigian mới sau khi cộng. */
Thoigian Thoigian :: operator+(Thoigian &a) const {
    return Thoigian(iGio + a.iGio, iPhut + a.iPhut, iGiay + a.iGiay);
}

/* Toán tử - (trừ hai đối tượng Thoigian)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về một đối tượng Thoigian mới là hiệu của hai đối tượng.
   Hoạt động: Trừ giờ, phút và giây của hai đối tượng Thoigian và 
   trả về đối tượng Thoigian mới sau khi trừ. */
Thoigian Thoigian :: operator-(Thoigian &a) const {
    return Thoigian(abs(iGio - a.iGio), abs(iPhut - a.iPhut), abs(iGiay - a.iGiay));
}

/* Toán tử ++ (tăng giờ)
   Đầu vào: Không có.
   Đầu ra: Trả về đối tượng Thoigian sau khi tăng 1 giây.
   Hoạt động: Tăng 1 giây vào thời gian hiện tại và trả về đối tượng Thoigian mới. */
Thoigian Thoigian :: operator++() {
    return *this + 1;
}

/* Toán tử -- (giảm giờ)
   Đầu vào: Không có.
   Đầu ra: Trả về đối tượng Thoigian sau khi giảm 1 giây.
   Hoạt động: Giảm 1 giây vào thời gian hiện tại và trả về đối tượng Thoigian mới. */
Thoigian Thoigian :: operator--() {
    return *this - 1;
}

/* Toán tử == (so sánh hai đối tượng Thoigian)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu hai đối tượng Thoigian có cùng giờ, phút và giây, 
   ngược lại trả về false.
   Hoạt động: So sánh giờ, phút và giây của hai đối tượng Thoigian. */
bool Thoigian :: operator==(const Thoigian &a) const {
    return iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay;
}

/* Toán tử != (so sánh hai đối tượng Thoigian)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu hai đối tượng Thoigian khác nhau, ngược lại trả về false.
   Hoạt động: So sánh hai đối tượng Thoigian và trả về kết quả ngược lại với toán tử ==. */
bool Thoigian :: operator!=(const Thoigian &a) const {
    return !(*this == a);
}

/* Toán tử >= (so sánh lớn hơn hoặc bằng)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu thời gian của đối tượng Thoigian hiện tại lớn hơn hoặc bằng đối tượng a.
   Hoạt động: So sánh tổng giây của hai đối tượng và trả về kết quả tương ứng. */
bool Thoigian :: operator>=(const Thoigian &a) const {
    return TinhGiay() >= a.TinhGiay();
}

/* Toán tử <= (so sánh nhỏ hơn hoặc bằng)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu thời gian của đối tượng Thoigian hiện tại nhỏ hơn hoặc bằng đối tượng a.
   Hoạt động: So sánh tổng giây của hai đối tượng và trả về kết quả tương ứng. */
bool Thoigian :: operator<=(const Thoigian &a) const {
    return TinhGiay() <= a.TinhGiay();
}

/* Toán tử > (so sánh lớn hơn)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu thời gian của đối tượng Thoigian hiện tại lớn hơn đối tượng a.
   Hoạt động: So sánh tổng giây của hai đối tượng và trả về kết quả tương ứng. */
bool Thoigian :: operator>(const Thoigian &a) const {
    return TinhGiay() > a.TinhGiay();
}

/* Toán tử < (so sánh nhỏ hơn)
   Đầu vào: Đối tượng Thoigian a.
   Đầu ra: Trả về true nếu thời gian của đối tượng Thoigian hiện tại nhỏ hơn đối tượng a.
   Hoạt động: So sánh tổng giây của hai đối tượng và trả về kết quả tương ứng. */
bool Thoigian :: operator<(const Thoigian &a) const {
    return TinhGiay() < a.TinhGiay();
}

/* Toán tử >> (nhập dữ liệu thời gian)
   Đầu vào: Luồng nhập (is) và đối tượng Thoigian (a).
   Đầu ra: Nhập giờ, phút, giây hợp lệ và gán vào đối tượng Thoigian a.
   Hoạt động: Kiểm tra tính hợp lệ của giờ, phút, giây và yêu cầu người dùng 
   nhập lại nếu không hợp lệ. */
istream& operator>>(istream& is, Thoigian &a) {
    cout << "Nhap gio: ";
    is >> a.iGio;
    while (a.iGio < 0 || a.iGio > 23) {
        cout << "Khong hop le, nhap lai: ";
        is >> a.iGio;
    }

    cout << "Nhap phut: ";
    is >> a.iPhut;
    while (a.iPhut < 0 || a.iPhut > 59) {
        cout << "Khong hop le, nhap lai: ";
        is >> a.iPhut;
    }

    cout << "Nhap giay: ";
    is >> a.iGiay;
    while (a.iGiay < 0 || a.iGiay > 59) {
        cout << "Khong hop le, nhap lai: ";
        is >> a.iGiay;
    }

    return is;
}

/* Toán tử << (xuất thời gian)
   Đầu vào: Luồng xuất (os) và đối tượng Thoigian (a).
   Đầu ra: In giờ, phút và giây của đối tượng Thoigian a ra màn hình.
   Hoạt động: Tính toán tổng giây và xuất giờ, phút, giây của đối tượng Thoigian 
   theo định dạng phù hợp. */
ostream& operator<<(ostream& os, const Thoigian &a) {
    int tong_giay = a.TinhGiay();
    int gio = tong_giay / 3600;
    int phut = (tong_giay % 3600) / 60;
    int giay = tong_giay % 60;
    os << gio << "h " << phut << "' " << giay << "s";
    return os;
}
