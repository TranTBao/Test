#include <iostream>
#include<string>
#include<string.h>

using namespace std;


class Student{
private:

      string name;
      string id;
      string Lop;
public:

      void Nhap_sv();
      void Hien_thi_sv();
      string get_name();
};

void Student::Nhap_sv(){

      cout << "Input Name: "; getline(cin , this->name) ;
      cout << "Input ID: " ; getline(cin , this->id);
      cout << "Input Grade: " ; getline(cin , this->Lop);
}

void Student::Hien_thi_sv(){


      cout << "Name: " << this->name << endl;
      cout << "ID: " << this->id <<endl;
      cout << "Class: " << this->Lop << endl;
}




class List_student{
private:

      Student *List; // sô học sinh
      int n;
      int *m; // con trỏ chứ vị trí chữ cái đầu tiên của tên
public:

      void Nhap_ds();

      void Hien_thi_ds();

      void Sap_xep();

};



void List_student::Nhap_ds(){

      cout << "Nhap vao so luong sinh vien: "; cin >> this->n ;

      List = new Student[n];
      cin.ignore();

      for(size_t i = 0 ; i < n ; i++){
            cout << "\nNhap vao sinh vien thu: " << i+1 << endl;
            List[i].Nhap_sv();
      }
}



void List_student::Hien_thi_ds(){
            cout << "\n\t\t\t\tSTUDEN INFORMATION";
      for(size_t i = 0 ; i < n ; i++){
            cout<< "\nStudent: "<< i+1<<endl;
            List[i].Hien_thi_sv();
      }

}




string Student::get_name(){  // lấy tên ra khỏi class.

      string a = this->name ;
      return a;
}


void List_student::Sap_xep(){
                              // sắp xếp tên theo thứ tự
      m = new int[n];
      for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < List[i].get_name().size() ; j++){
            if(List[i].get_name()[j] == ' ') m[i] = j + 1;
         }

      }

      Student swa;
      int sw;

      for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i+1 ; j < n ; j++){
            if(List[i].get_name()[m[i]] >  List[j].get_name()[m[j]]){

                  swa = List[i] ;
                  List[i] = List[j];
                  List[j] = swa ;

                  sw = m[i] ;
                  m[i] = m[j];
                  m[j] = sw ;
            }

            }

      }


}




int main()
{
   List_student x;

   x.Nhap_ds();
   x.Sap_xep();
   x.Hien_thi_ds();

    return 0;
}
