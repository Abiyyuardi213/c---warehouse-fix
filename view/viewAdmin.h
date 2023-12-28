#include "D:\Program\c++ warehouse fix\model\modelMember.h"
#include<iostream>
#include<string>

using namespace std;

void vTambahAdmin() {
    string name;
    string user;
    string phone;
    string mail;
    string pass;

    cout<<"============================================ \n";
    cout<<"=====---------- TAMBAH ADMIN ----------====="<<endl;
    cout<<"============================================ \n";
    cin.ignore();
    cout<<"= Nama         : ";
    getline(cin, name);
    cout<<"= Username     : "; cin>>user;
    cout<<"= No. Telepon  : "; cin>>phone;
    cout<<"= Email        : "; cin>>mail;
    cout<<"= Password     : "; cin>>pass;
    system("cls");
    mTambahAdmin(name, user, phone, mail, pass);

    cout<<endl;
    cout<<"================================================ \n";
    cout<<"=====----- Admin berhasil ditambahkan -----====="<<endl;
    cout<<"================================================ \n";

    cout<<endl;
}

void vViewAdmin() {
    mLihatAdmin();

    cout<<endl;
    cout<<"=====--- Pilih opsi untuk edit admin ---====="<<endl;
    cout<<"= 1. Ubah password admin                    = \n";
    cout<<"= 2. Hapus admin                            = \n";
    cout<<"= 3. Kembali ke menu utama                  = \n";
    cout<<"============================================= \n";
}

void vCariAdmin() {
    string phone;

    cout<<"================================ \n";
    cout<<"=====----- CARI ADMIN -----====="<<endl;
    cout<<"================================ \n";
    cout<<endl;
    cout<<"Nomor telepon : "; cin>>phone;
    int index = mCariAdmin(phone);
    cout<<endl;

    if (index != -1) {
        cout<<"== Data admin ditemukan!"<<endl;
        cout<<endl;
        cout<<"=========================================----- DATA ADMIN -----========================================="<<endl;
        cout<<"========================================================================================================"<<endl;
        cout<<"Nama\t\tUsername\tNo. Telp\t\tEmail\t\t\tPassword"<<endl;
        cout<<"========================================================================================================"<<endl;
        cout<<namaAdmin[index]<<"\t"<<userName[index]<<"\t"<<phoneNumber[index]<<"\t\t"<<userEmail[index]<<"\t"<<password[index]<<endl;
        cout<<"========================================================================================================"<<endl;
    } else {
        cout<<"No. Telp tidak ditemukan"<<endl;
    }
}

void vUpdtPass() {
    string phone;
    string pass;

    cout<<"===================================== \n";
    cout<<"=====----- UPDATE PASSWORD -----====="<<endl;
    cout<<"===================================== \n";
    cout<<"No. Telepon  : "; cin>>phone;
    cout<<"New Password : "; cin>>pass;
    mUpdtAdmin(phone, pass);
}

void vLogin() {
    string userName;
    string password;

    cout<<"================================= \n";
    cout<<"=====----- LOGIN ADMIN -----====="<<endl;
    cout<<"================================= \n";
    cout<<"Username : "; cin>>userName;
    cout<<"Password : "; cin>>password;
    mLogin(userName, password);
}

void vDeleteAdmin() {
    string phone;

    cout<<"================================= \n";
    cout<<"=====----- HAPUS ADMIN -----====="<<endl;
    cout<<"================================= \n";
    cout<<endl;
    cout<<"= Nomor telepon : "; cin>>phone;
    cout<<endl;

    mDeleteAdmin(phone);
}