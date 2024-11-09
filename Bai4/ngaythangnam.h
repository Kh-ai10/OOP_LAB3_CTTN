#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

   

public:
  
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);

   
    bool Namnhuan(int nam);
    int Ngaytrongthang(int thang, int nam);
    void TinhNgay();

    
    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(NgayThangNam a);
    NgayThangNam& operator++();
    NgayThangNam& operator--();
    bool operator==(const NgayThangNam& khac) const;
    bool operator!=(const NgayThangNam& khac) const;
    bool operator>=(const NgayThangNam& khac) const;
    bool operator<=(const NgayThangNam& khac) const;
    bool operator>(const NgayThangNam& khac) const;
    bool operator<(const NgayThangNam& khac) const;

    
    friend std::istream& operator>>(std::istream& is, NgayThangNam& ngay);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& ngay);
};

#endif
