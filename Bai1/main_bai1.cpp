#include "Phanso.h"
#include <iostream>
using namespace std;

bool Kiemtra(Phanso& ps1, Phanso& ps2){
    if (ps1 == ps2){
        cout << "Hai phan so bang nhau\n";
    } if (ps1 > ps2){
        cout << "Phan so 1 lon hon phan so 2\n";
    } if (ps1 < ps2){
        cout <<"Phan so 1 be hon phan so 2\n";
    } if (ps1 >= ps2){
        cout << "Phan so 1 lon hon hoac bang phan so 2\n";
    } if (ps1 <= ps2){
        cout << "Phan so 1 be hon hoac bang phan so 2\n";
    } if (ps1 != ps2){
        cout << "Phan so 1 khac phan so 2\n";
    }
}

int main(){
    Phanso ps1, ps2;
    cout <<"Constructor voi tham so: " << Phanso(3,4) << "\n";
    cout <<"Nhap 2 phan so (tu mau):";
    cin >> ps1 >> ps2;

    cout <<"2 phan so vua nhap la: " << ps1 <<" " << ps2 << "\n";
    cout << "Tong: " << ps1 + ps2 << "\n";
    cout << "Hieu: " << ps1 - ps2 <<"\n";
    cout << "Tich: " << ps1*ps2 << "\n";
    cout << "Thuong: " << ps1/ps2 <<"\n";

    Kiemtra(ps1, ps2);  
    
    // Cộng số thực với phân số
    Phanso ps3;
    cout << "Nhap phan so de tinh toan voi so thuc: ";
    cin >> ps3;
    double sothuc_n;
    cout << "Nhap 1 so thuc de tinh toan voi phan so: ";
    cin >> sothuc_n;
   
    cout << "Phan so " << ps3 << " cong voi so thuc " << sothuc_n << " la: " << ps3 + sothuc_n << "\n";

    // Trừ số thực với phân số
    cout << "Phan so " << ps3 << " tru so thuc " << sothuc_n << " la: " << ps3 - sothuc_n << "\n";

    // Nhân số thực với phân số
    cout << "Phan so " << ps3 << " nhan so thuc " << sothuc_n << " la: " << ps3 * sothuc_n << "\n";

    // Chia số thực với phân số
    cout << "Phan so " << ps3 << " chia cho so thuc " << sothuc_n << " la: " << ps3 / sothuc_n << "\n";
       
}