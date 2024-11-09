#include <iostream>
using namespace std;
#include "sophuc.h"

bool Kiemtra(Sophuc& sp1, Sophuc& sp2){
    if (sp1 == sp2){
        cout << "Hai so phuc bang nhau\n";
    } 
    else{
        cout << "So phuc 1 khac So phuc 2\n";
    }
}


int main(){
    Sophuc sp1, sp2;
    cout << "Constructor voi tham so: ";
    cout << Sophuc(10, 11) <<"\n";
    cout << "Nhap 2 so phuc (phan thuc phan ao):\n";
    cin >> sp1 >> sp2;
    cout << "Hai so phuc vua nhap la: \n";
    cout << "So phuc 1: " << sp1 << "\n" ;
    cout << "So phuc 2: " << sp2 <<"\n";

    cout <<"Tong: " << sp1 + sp2 << "\n";
    cout << "Hieu: " << sp1 - sp2 << "\n";
    cout << "Tich: " << sp1*sp2 << "\n";
    cout << "Thuong: " << sp1/sp2 << "\n";

    Kiemtra(sp1, sp2);
    




}