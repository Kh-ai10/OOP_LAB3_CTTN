#include <iostream>
#include "thoigian.h"

using namespace std;

bool Kiemtra(Thoigian& tg1, Thoigian& tg2){
    if (tg1 == tg2){
        cout << "Hai thoi gian bang nhau\n";
    } if (tg1 > tg2){
        cout << "Thoi gian 1 lon hon Thoi gian 2\n";
    } if (tg1 < tg2){
        cout <<"Thoi gian 1 be hon Thoi gian 2\n";
    } if (tg1 >= tg2){
        cout << "Thoi gian 1 lon hon hoac bang Thoi gian 2\n";
    } if (tg1 <= tg2){
        cout << "Thoi gian 1 be hon hoac bang Thoi gian 2\n";
    } if (tg1 != tg2){
        cout << "Thoi gian 1 khac Thoi gian 2\n";
    }
}

int main(){
    Thoigian tg1, tg2;
    cout << "Constructor voi tham so: " << Thoigian(10, 11, 05) <<"\n";
    cout << "Nhap 2 khoang Thoi gian (gio phut giay): \n";
    cin >> tg1 >> tg2;
    cout << "2 khoang Thoi gian vua nhap la: \n";
    cout << "TG1: " << tg1 << "\n" << "TG2: " << tg2 <<"\n";

    cout << "TG1 sau khi tang 1 giay: " << ++tg1 <<"\n";
    cout << "TG2 sau khi giam 1 giay: " << --tg2<<"\n";

    cout << "Tong: " << tg1 + tg2 << "\n";
    cout << "Hieu: " << tg1 - tg2 << "\n";

    int giay1, giay2;
    cout<< "Nhap so giay muon cong tru: ";
    cin >> giay1 >> giay2;
    cout << "TG1 sau khi cong " << giay1 << " giay: " << tg1 + giay1 <<"\n";
    cout << "TG2 sau khi tru " << giay2 << " giay: " << tg2 - giay2 << "\n";

    Kiemtra(tg1, tg2);
 




}
