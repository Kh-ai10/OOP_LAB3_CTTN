#include "sophuc.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/* Khởi tạo mặc định
   Đầu vào: Không có.
   Đầu ra: Số phức với phần thực và phần ảo bằng 0.
   Hoạt động: Thiết lập giá trị mặc định cho số phức. */
Sophuc::Sophuc() : dThuc(0), dAo(0) {}

/* Khởi tạo số phức với tham số
   Đầu vào: Phần thực (thuc) và phần ảo (ao).
   Đầu ra: Số phức được khởi tạo với giá trị phần thực và phần ảo tương ứng.
   Hoạt động: Gán giá trị phần thực và phần ảo theo tham số đầu vào. */
Sophuc::Sophuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

/* Toán tử + (cộng hai số phức)
   Đầu vào: Số phức cần cộng (sp).
   Đầu ra: Kết quả phép cộng của hai số phức.
   Hoạt động: Cộng từng phần thực và phần ảo, tạo số phức mới. */
Sophuc Sophuc::operator+(const Sophuc &sp) const {
    return Sophuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

/* Toán tử - (trừ hai số phức)
   Đầu vào: Số phức cần trừ (sp).
   Đầu ra: Kết quả phép trừ của hai số phức.
   Hoạt động: Trừ từng phần thực và phần ảo, tạo số phức mới. */
Sophuc Sophuc::operator-(const Sophuc &sp) const {
    return Sophuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

/* Toán tử * (nhân hai số phức)
   Đầu vào: Số phức cần nhân (sp).
   Đầu ra: Kết quả phép nhân của hai số phức.
   Hoạt động: Áp dụng công thức nhân số phức, tạo số phức mới. */
Sophuc Sophuc::operator*(const Sophuc &sp) const {
    return Sophuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

/* Toán tử / (chia hai số phức)
   Đầu vào: Số phức cần chia (sp).
   Đầu ra: Kết quả phép chia của hai số phức; nếu chia cho 0, gọi terminated.
   Hoạt động: Kiểm tra chia cho 0, áp dụng công thức chia số phức, tạo số phức mới. */
Sophuc Sophuc::operator/(const Sophuc &sp) const {
    if (sp.dThuc == 0 && sp.dAo == 0) {
        throw std::invalid_argument("Khong the chia cho 0");
    }
    
    return Sophuc(
        (dThuc * sp.dThuc + dAo * sp.dAo) / (sp.dThuc * sp.dThuc + sp.dAo * sp.dAo),
        (dAo * sp.dThuc - dThuc * sp.dAo) / (sp.dThuc * sp.dThuc + sp.dAo * sp.dAo)
    );
}

/* Toán tử == (so sánh bằng)
   Đầu vào: Số phức cần so sánh (sp).
   Đầu ra: Trả về true nếu hai số phức bằng nhau, ngược lại false.
   Hoạt động: So sánh phần thực và phần ảo của hai số phức. */
bool Sophuc::operator==(const Sophuc &sp) const {
    return dThuc == sp.dThuc && dAo == sp.dAo;
}

/* Toán tử != (so sánh khác)
   Đầu vào: Số phức cần so sánh (sp).
   Đầu ra: Trả về true nếu hai số phức khác nhau, ngược lại false.
   Hoạt động: Gọi toán tử == và đảo ngược kết quả. */
bool Sophuc::operator!=(const Sophuc &sp) const {
    return !(*this == sp);
}

/* Toán tử >> (nhập số phức)
   Đầu vào: Luồng nhập (is) và số phức (sp).
   Đầu ra: Nhập giá trị phần thực và phần ảo cho số phức.
   Hoạt động: Nhắc người dùng nhập phần thực và phần ảo từ bàn phím. */
istream& operator>>(istream& is, Sophuc &sp) {
    cout << "Nhap phan thuc va phan ao: ";
    is >> sp.dThuc >> sp.dAo;
    return is;
}

/* Toán tử << (xuất số phức)
   Đầu vào: Luồng xuất (os) và số phức (sp).
   Đầu ra: In số phức theo định dạng phù hợp.
   Hoạt động: Kiểm tra phần thực và phần ảo, định dạng kết quả in ra. */
ostream& operator<<(ostream& os, const Sophuc &sp) {
    if (sp.dAo == 0) {
        os << sp.dThuc; // Nếu phần ảo là 0, chỉ in phần thực
    } else if (sp.dThuc == 0) {
        if (sp.dAo == 1) 
            os << "i"; // In "i" khi phần ảo là 1
        else if (sp.dAo == -1) 
            os << "-i"; // In "-i" khi phần ảo là -1
        else 
            os << sp.dAo << "i"; // In phần ảo khác
    } else {
        os << sp.dThuc;
        if (sp.dAo == 1) 
            os << " + i"; // In " + i" khi phần ảo là 1
        else if (sp.dAo == -1) 
            os << " - i"; // In " - i" khi phần ảo là -1
        else if (sp.dAo < 0) 
            os << " - " << -sp.dAo << "i"; // In " - phần ảo"
        else 
            os << " + " << sp.dAo << "i"; // In " + phần ảo"
    }
    return os;
}
