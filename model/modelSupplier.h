#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\database\dataSupplier.h"

using namespace std;

//fungsi untuk inisialisasi supplier
void mAddSupplier(string name, string addres, string kontak, string email) {
    namaSupplier[dataSupplier] = name;
    alamatSupplier[dataSupplier] = addres;
    kontakSupplier[dataSupplier] = kontak;
    emailSupplier[dataSupplier] = email;

    dataSupplier++;
}

//fungsi untuk melihat data supplier
void mLihatSupplier() {
    cout<<"============================================= \n";
    cout<<"==========----- DATA SUPPLIER -----=========="<<endl;
    cout<<"============================================= \n";
    cout<<"No.\tNama Supplier\tAlamat\t\tKontak\tEmail"<<endl;
    cout<<"============================================= \n";

    for (int i = 0; i < dataSupplier; i++) {
        cout<<i + 1<<"\t"<<namaSupplier[i]<<"\t"<<alamatSupplier[i]<<"\t\t"<<kontakSupplier[i]<<"\t"<<emailSupplier[i]<<endl;
    }
    cout<<"============================================= \n";
}