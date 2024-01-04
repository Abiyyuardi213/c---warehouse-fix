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
    cout<<endl;

    mAddSupplier(name, addres, kontak, email);
    cout<<"=================================================== \n";
    cout<<"=====----- Supplier berhasil ditambahkan -----====="<<endl;
    cout<<"=================================================== \n";

    //menambahkan riwayat transaksi
    string detilTransaki = "Nama : " + name + ", Alamat : " + addres + ", Kontak : " + kontak + ", Email : " + email;
    mAddRiwayat("Tambah Supplier", detilTransaki);
}

//fungsi untuk menampilkan history supplier
void vSeeRiwayat() {
    mSeeRiwayat();
}