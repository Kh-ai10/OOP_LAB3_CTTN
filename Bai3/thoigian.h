#ifndef THOIGIAN_H
#define THOIGIAN_H
#include <iostream>
using namespace std;

class Thoigian{
    private:
        int iGio, iPhut, iGiay;

    public:
    Thoigian(); 
    Thoigian (int Gio, int Phut, int Giay); 

    int TinhGiay() const; 
    Thoigian TinhLaiGio(int Giay);

    Thoigian operator+(int Giay); 
    Thoigian operator-(int Giay);

    Thoigian operator+(Thoigian &a) const;
    Thoigian operator-(Thoigian &a) const;

    Thoigian operator++(); 
    Thoigian operator--();

    bool operator==(const Thoigian &a) const;
    bool operator!=(const Thoigian &a) const;
    bool operator>=(const Thoigian &a) const;
    bool operator<=(const Thoigian &a) const;
    bool operator>(const Thoigian &a) const;
    bool operator<(const Thoigian &a) const;

    friend istream& operator>>(istream& is, Thoigian &a); 
    friend ostream& operator<<(ostream&os, const Thoigian &a);



};
#endif