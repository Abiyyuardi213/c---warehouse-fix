#include "D:\Program\c++ warehouse fix\model\modelMember.h"
#include<iostream>
#include<string>

using namespace std;

void vTambahAdmin() {
    string user;
    string phone;
    string mail;
    string pass;

    cout<<"Username     : "; cin>>user;
    cout<<"No. Telepon  : "; cin>>phone;
    cout<<"Email        : "; cin>>mail;
    cout<<"Password     : "; cin>>pass;
    mTambahAdmin(user, phone, mail, pass);
}

void vViewAdmin() {
    mLihatAdmin();
}

void vCariAdmin() {
    string phone;
    cout<<"Nomor telepon : "; cin>>phone;
    int index = mCariAdmin(phone);

    if (index != -1) {
        cout<<"DATA ADMIN"<<endl;
        cout<<"=========================================="<<endl;
        cout<<"Nama\t\tNo. Telp\t\tEmail\t\tPassword"<<endl;
        cout<<"=========================================="<<endl;
        cout<<userName[index]<<"\t\t"<<phoneNumber[index]<<"\t\t"<<userEmail[index]<<"\t\t"<<password[index]<<endl;
        cout<<"=========================================="<<endl;
    } else {
        cout<<"No. Telp tidak ditemukan"<<endl;
    }
}

void vUpdtPass() {
    string phone;
    string pass;
    cout<<"No. Telepon  : "; cin>>phone;
    cout<<"New Password : "; cin>>pass;
    mUpdtAdmin(phone, pass);
}

void vLogin() {
    string userName;
    string password;
    cout<<"=====--- Login admin ---====="<<endl;
    cout<<"Username : "; cin>>userName;
    cout<<"Password : "; cin>>password;
    mLogin(userName, password);
}