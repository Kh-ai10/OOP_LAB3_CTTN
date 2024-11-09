#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
using namespace std;

class Sophuc{
  private:
    double dThuc, dAo;

  public:
    Sophuc();
    Sophuc(double thuc, double ao);
    Sophuc operator+(const Sophuc &sp) const;
    Sophuc operator-(const Sophuc &sp) const;
    Sophuc operator*(const Sophuc &sp) const;
    Sophuc operator/(const Sophuc &sp) const;
    bool operator==(const Sophuc &sp) const;
    bool operator!=(const Sophuc &sp) const;

    friend istream& operator>>(istream& is, Sophuc &sp);
    friend ostream& operator<<(ostream& os, const Sophuc &sp);

};
#endif