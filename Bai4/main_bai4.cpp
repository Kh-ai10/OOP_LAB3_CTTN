#include <iostream>
#include "ngaythangnam.h"

using namespace std;

bool Kiemtra(NgayThangNam& td1, NgayThangNam& td2){
    if (td1 == td2){
        cout << "Hai thoi diem bang nhau\n";
    } if (td1 > td2){
        cout << "Thoi diem 1 lon hon Thoi diem 2\n";
    } if (td1 < td2){
        cout <<"Thoi diem 1 be hon Thoi diem 2\n";
    } if (td1 >= td2){
        cout << "Thoi diem 1 lon hon hoac bang Thoi diem 2\n";
    } if (td1 <= td2){
        cout << "Thoi diem 1 be hon hoac bang Thoi diem 2\n";
    } if (td1 != td2){
        cout << "Thoi diem 1 khac Thoi diem 2\n";
    }
}

int main() {
    NgayThangNam nt1, nt2;
    cout << "Constructor voi tham so: " << NgayThangNam(2024, 11, 5) << "\n";
    cout << "Nhap 2 ngay thang nam (nam thang ngay): \n";
    cin >> nt1 >> nt2;
    cout << "2 ngay thang nam vua nhap la: \n";
    cout << "NT1: " << nt1 << "\n" << "NT2: " << nt2 << "\n";
    Kiemtra(nt1, nt2);

    cout << "Hieu giua hai thoi diem: " << nt1 - nt2 << " ngay\n"; 

    int ngay1, ngay2;
    cout << "Nhap so ngay muon cong tru: ";
    cin >> ngay1 >> ngay2;
    cout << "NT1 sau khi cong " << ngay1 << " ngay: " << nt1 + ngay1 << "\n";
    cout << "NT2 sau khi tru " << ngay2 << " ngay: " << nt2 - ngay2 << "\n";


    cout << "NT1 sau khi tang 1 ngay: " << ++nt1 << "\n";
    cout << "NT2 sau khi giam 1 ngay: " << --nt2 << "\n";

    
    

    

    

    return 0;
}
