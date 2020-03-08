#include "Phanso.h"

Phanso::Phanso()
{
      tu = 0;
      mau = 1;
      //ctor
}

Phanso::~Phanso()
{
      //dtor
}

Phanso::Phanso(int a , int b){
      this->tu = a ;
      this->mau = b ;
}
Phanso::Phanso(const Phanso &ps){
      tu = ps.tu ;
      mau = ps.mau ;
}

void Phanso::Nhap_ps(){
      std::cout << "Nhap Tu: " ; std::cin >> tu ;
      std::cout << "Nhap Mau: " ; std::cin >> mau ;
}


void Phanso::Hien_thi_ps(){
      std::cout << tu <<"/"<<mau << std::endl;
}

Phanso Phanso::Tinh_tong(Phanso a){

      this->tu = tu*a.mau + mau*a.tu ;
      this->mau = mau*a.mau ;

      return  *this ;
}

Phanso Phanso::operator + (Phanso d){

//      this->tu = tu*d.mau + mau*d.tu ;
//      this->mau = mau * d.mau;

      return this->Tinh_tong(d);
}

Phanso Phanso::operator+(int d){
      this->tu = tu + d*mau;
      this->mau = mau;

      return *this;
}

Phanso operator + (int a , Phanso b){

//      Phanso B ;
//      B.tu = b.tu + a*b.mau ;
//      B.mau = b.mau ;

    return b + a;

}

Phanso Phanso::operator += (Phanso ps){

      return this->Tinh_tong(ps);
}

std::istream& operator>>(std::istream&is , Phanso&ps){

    is >> ps.tu >>ps.mau;
    return is;
}

std::ostream& operator<<(std::ostream& os , Phanso ps){

      os << ps.tu <<"/" <<ps.mau ;

      return os;

}






