#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class Phanso{
    private:
    int iTu, iMau;

    public:
    Phanso();
    Phanso(int Tu, int Mau);

    void Rutgon(int& Tu, int& Mau);
    
    // Chuyển từ số thực sang phân số
    void Sothuc(double giatri);

    Phanso operator+(const Phanso &ps) const;
    Phanso operator-(const Phanso &ps) const;
    Phanso operator*(const Phanso &ps) const;
    Phanso operator/(const Phanso &ps) const;

    bool operator==(const Phanso &ps) const;
    bool operator!=(const Phanso &ps) const;
    bool operator>=(const Phanso &ps) const;
    bool operator<=(const Phanso &ps) const;
    bool operator>(const Phanso &ps) const;
    bool operator<(const Phanso &ps) const;

    friend ostream& operator<<(ostream& os, const Phanso &ps);
    friend istream& operator>>(istream& is, Phanso &ps);

    // Cộng số thực với phân số
    Phanso operator+(double giatri) const;

    // Trừ số thực với phân số
    Phanso operator-(double giatri) const;

    // Nhân số thực với phân số
    Phanso operator*(double giatri) const;

    // Chia số thực với phân số
    Phanso operator/(double giatri) const;

};

#endif