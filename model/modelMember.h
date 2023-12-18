#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\database\dataMember.h"

using namespace std;

void mTambahAdmin(string user, string phone, string mail, string pass) {
    userName[dataAdmin] = user;
    phoneNumber[dataAdmin] = phone;
    userEmail[dataAdmin] = mail;
    password[dataAdmin] = pass;
    dataAdmin++;
}

void mLihatAdmin() {
    cout<<"=====--- DATA ADMIN ---====="<<endl;
    cout<<"Jumlah admin : "<<dataAdmin<<endl;
    cout<<"================================================================================="<<endl;
    cout<<"Username\t\tNo. Telp\t\tEmail\t\t\tPassword"<<endl;
    cout<<"================================================================================="<<endl;
    for (int i = 0; i < dataAdmin; i++) {
        cout<<userName[i]<<"\t\t\t"<<phoneNumber[i]<<"\t\t"<<userEmail[i]<<"\t"<<password[i]<<endl;
    }
    cout<<"================================================================================="<<endl;
}

int mCariAdmin(string phone) {
    for (int i = 0; i < dataAdmin; i++) {
        if (phoneNumber[i] == phone) {
            return i;
        }
    }
    return -1;
}

void mUpdtAdmin(string phone, string pass) {
    //cek nomor telepon
    int index = mCariAdmin(phone);
    if (index != 1) {
        password[index] = pass;
        cout<<"=====--- Password berhasil diubah ---====="<<endl;
    } else {
        cout<<"=====--- No. Telp tidak ditemukan ---====="<<endl;
    }
}

bool mLogin(string user, string pass) {
    for (int i = 0; i < dataAdmin; i++) {
        if (userName[i] == user && password[i] == pass) {
            cout<<"=====--- Login berhasil ---====="<<endl;
            return true;
        }
    }
    cout<<"====================================== \n";
    cout<<"===== LOGIN GAGAL, NAMA PENGGUNA ====="<<endl;
    cout<<"======= ATAU KATA SANDI SALAH ========"<<endl;
    cout<<"====================================== \n";
    return false;
}