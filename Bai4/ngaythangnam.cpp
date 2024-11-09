#include <iostream>
#include "NgayThangNam.h"
using namespace std;

/*
Constructor mặc định
Đầu vào: Không có.
Đầu ra: Khởi tạo đối tượng NgayThangNam với giá trị ngày, tháng, năm là 0.
Hoạt động: Thiết lập các thành phần iNgay, iThang, iNam thành 0.
*/
NgayThangNam::NgayThangNam() : iNam(0), iThang(0), iNgay(0) {}

/*
Constructor có tham số
Đầu vào: Nam, Thang, Ngay (các giá trị ngày, tháng, năm cần khởi tạo).
Đầu ra: Khởi tạo đối tượng NgayThangNam với các giá trị đã cho.
Hoạt động: Gán các giá trị đầu vào cho các thành phần và 
gọi TinhNgay() để điều chỉnh ngày hợp lệ.
*/
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay)
    : iNam(Nam), iThang(Thang), iNgay(Ngay) {
    TinhNgay();
}

/**
Kiểm tra năm nhuận
Đầu vào: Nam (số nguyên biểu thị năm cần kiểm tra).
Đầu ra: Trả về true nếu năm là năm nhuận, ngược lại trả về false.
Hoạt động: Kiểm tra năm theo quy tắc năm nhuận.
*/
bool NgayThangNam::Namnhuan(int Nam) {
    return (Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0);
}

/**
Trả về số ngày trong tháng
Đầu vào: Thang, Nam (số nguyên biểu thị tháng và năm cần kiểm tra).
Đầu ra: Số ngày của tháng đó trong năm đó.
Hoạt động: Xác định số ngày dựa trên tháng và kiểm tra năm nhuận cho tháng 2.
*/
int NgayThangNam::Ngaytrongthang(int Thang, int Nam) {
    switch (Thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return Namnhuan(Nam) ? 29 : 28;
        default:
            return 31;
    }
}

/**
Hàm Tính ngày
Đầu vào: Không có.
Đầu ra: Điều chỉnh ngày, tháng, năm sao cho hợp lệ.
Hoạt động: Nếu ngày vượt quá số ngày của tháng, tháng sẽ tăng và 
ngày được giảm. Nếu tháng vượt quá 12, năm sẽ tăng.
*/
void NgayThangNam::TinhNgay() {
    while (iNgay > Ngaytrongthang(iThang, iNam)) {
        iNgay -= Ngaytrongthang(iThang, iNam);
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    while (iNgay < 1) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        iNgay += Ngaytrongthang(iThang, iNam);
    }
}

/**
Toán tử cộng ngày
Đầu vào: ngay (số nguyên là số ngày cần cộng).
Đầu ra: Trả về đối tượng NgayThangNam mới với ngày đã được cộng thêm.
Hoạt động: Nếu cộng thêm 0 ngày, trả về đối tượng hiện tại. 
Nếu không, cộng số ngày vào iNgay và điều chỉnh lại ngày.
*/
NgayThangNam NgayThangNam::operator+(int ngay) {
    if (ngay != 0){
        NgayThangNam newngay(iNam, iThang, iNgay + ngay);
        newngay.TinhNgay();
        return newngay;
    }
    else return *this;
}

/**
Toán tử trừ ngày
Đầu vào: ngay (số nguyên là số ngày cần trừ).
Đầu ra: Trả về đối tượng NgayThangNam mới với ngày đã được trừ bớt.
Hoạt động: Nếu trừ đi 0 ngày, trả về đối tượng hiện tại. 
Nếu không, trừ số ngày vào iNgay và điều chỉnh lại ngày.
*/
NgayThangNam NgayThangNam::operator-(int ngay) {
    if(ngay != 0){
        NgayThangNam newngay(iNam, iThang, iNgay - ngay);
        newngay.TinhNgay();
        return newngay;
    }
    else return *this;
}

/**
Toán tử trừ giữa hai ngày
Đầu vào: a (đối tượng NgayThangNam cần so sánh).
Đầu ra: Trả về số ngày giữa đối tượng hiện tại và đối tượng a.
Hoạt động: Tính tổng số ngày từ năm 0 đến ngày của cả hai đối tượng 
và trả về hiệu giữa chúng (ở đây xem là độ chênh lệch giữa 2 thời điểm nên có abs()).
*/
int NgayThangNam::operator-(NgayThangNam a) {
    int tong_ngay1 = iNgay, tong_ngay2 = a.iNgay;
    
    for (int i = 1; i < iThang; i++) {
        tong_ngay1 += Ngaytrongthang(i, iNam);
    }
    for (int i = 1; i < a.iThang; i++) {
        tong_ngay2 += Ngaytrongthang(i, a.iNam);
    }
    
    for (int i = 1; i < iNam; i++) {
        tong_ngay1 += Namnhuan(i) ? 366 : 365;
    }
    for (int i = 1; i < a.iNam; i++) {
        tong_ngay2 += Namnhuan(i) ? 366 : 365;
    }

    return abs(tong_ngay1 - tong_ngay2);
}

/**
Toán tử ++
Đầu vào: Không có.
Đầu ra: Trả về đối tượng NgayThangNam sau khi ngày đã được cộng 1.
Hoạt động: Tăng 1 ngày vào iNgay và điều chỉnh lại ngày cho hợp lệ.
*/
NgayThangNam& NgayThangNam::operator++() {
    iNgay++;
    TinhNgay();
    return *this;
}

/**
Toán tử --
Đầu vào: Không có.
Đầu ra: Trả về đối tượng NgayThangNam sau khi ngày đã được trừ 1.
Hoạt động: Giảm 1 ngày vào iNgay và điều chỉnh lại ngày cho hợp lệ.
*/
NgayThangNam& NgayThangNam::operator--() {
    iNgay--;
    TinhNgay();
    return *this;
}

/**
Toán tử so sánh bằng
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu ngày, tháng, năm của hai đối tượng là giống nhau, 
ngược lại trả về false.
Hoạt động: So sánh các thành phần ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator==(const NgayThangNam& khac) const {
    return iNgay == khac.iNgay && iThang == khac.iThang && iNam == khac.iNam;
}

/**
Toán tử so sánh khác
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu ngày, tháng, năm của hai đối tượng khác nhau, 
ngược lại trả về false.
Hoạt động: So sánh các thành phần ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator!=(const NgayThangNam& khac) const {
    return !(*this == khac);
}

/**
Toán tử so sánh lớn hơn hoặc bằng
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu đối tượng hiện tại lớn hơn hoặc bằng đối tượng khac, 
ngược lại trả về false.
Hoạt động: So sánh ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator>=(const NgayThangNam& khac) const {
    return iNgay >= khac.iNgay && iThang >= khac.iThang && iNam >= khac.iNam;
}

/**
Toán tử so sánh nhỏ hơn hoặc bằng
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu đối tượng hiện tại nhỏ hơn hoặc bằng đối tượng khac, 
ngược lại trả về false.
Hoạt động: So sánh ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator<=(const NgayThangNam& khac) const {
    return iNgay <= khac.iNgay && iThang <= khac.iThang && iNam <= khac.iNam;
}

/**
Toán tử so sánh lớn hơn
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu đối tượng hiện tại lớn hơn đối tượng khac, 
ngược lại trả về false.
Hoạt động: So sánh ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator>(const NgayThangNam& khac) const {
    return iNgay > khac.iNgay && iThang > khac.iThang && iNam > khac.iNam;
}

/**
Toán tử so sánh nhỏ hơn
Đầu vào: khac (đối tượng NgayThangNam để so sánh).
Đầu ra: Trả về true nếu đối tượng hiện tại nhỏ hơn đối tượng khac, 
ngược lại trả về false.
Hoạt động: So sánh ngày, tháng, năm của hai đối tượng.
*/
bool NgayThangNam::operator<(const NgayThangNam& khac) const {
    return iNgay < khac.iNgay && iThang < khac.iThang && iNam < khac.iNam;
}

/**
Hàm nhập đối tượng NgayThangNam từ bàn phím
Đầu vào: luồng nhập is và đối tượng ngay.
Đầu ra: Trả về đối tượng NgayThangNam đã được nhập.
Hoạt động: Nhập ngày, tháng, năm từ người dùng và kiểm tra tính hợp lệ của chúng.
*/
std::istream& operator>>(std::istream& is, NgayThangNam& ngay) {
    cout << "Nhap ngay: ";
    is >> ngay.iNgay;

    while (ngay.iNgay < 1 || ngay.iNgay > 31){
        cout << "Khong ton tai, nhap lai ngay: ";
        is >> ngay.iNgay;
    }

    cout << "Nhap thang: ";
    is >> ngay.iThang;

    while (ngay.iThang < 1 || ngay.iThang > 12){
        cout << "Khong ton tai, nhap lai thang: ";
        is >> ngay.iThang;
    }

    while (ngay.iNgay > ngay.Ngaytrongthang(ngay.iThang, ngay.iNam)){
        cout << "Khong hop le, nhap lai thang: ";
        is >> ngay.iThang;
    }

    cout << "Nhap nam: ";
    is >> ngay.iNam;
    while (ngay.iNam < 0) {
        cout << "Nam khong hop le, nhap lai nam: ";
        is >> ngay.iNam;
    }

    while (ngay.iNgay > ngay.Ngaytrongthang(ngay.iThang, ngay.iNam)){
        cout << "Khong hop le, nhap lai nam: ";
        is >> ngay.iNam;
    }

    return is;
}

/**
Hàm xuất đối tượng NgayThangNam ra màn hình
Đầu vào: luồng xuất os và đối tượng ngay.
Đầu ra: Trả về stream sau khi đã xuất ngày, tháng, năm.
Hoạt động: Xuất thông tin ngày, tháng, năm ra màn hình.
*/
std::ostream& operator<<(std::ostream& os, const NgayThangNam& ngay) {
    os << ngay.iNgay << "/" << ngay.iThang << "/" << ngay.iNam;
    return os;
}
