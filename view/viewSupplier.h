#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\model\modelSupplier.h"

using namespace std;

void vAddSupplier() {
    string name;
    string addres;
    string kontak;
    string email;
    
    cout<<"===================================== \n";
    cout<<"=====----- TAMBAH SUPPLIER -----====="<<endl;
    cout<<"===================================== \n";
    cout<<"= Nama Supplier : "; cin>>name;
    cout<<"= Alamat        : "; cin>>addres;
    cout<<"= Kontak        : "; cin>>kontak;
    cout<<"= Email         : "; cin>>email;
    cout<<"===================================== \n";

    mAddSupplier(name, addres, kontak, email);
    cout<<"=================================================== \n";
    cout<<"=====----- Supplier berhasil ditambahkan -----====="<<endl;
    cout<<"=================================================== \n";
}