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

//fungsi untuk menambah riwayat supplier
void mAddRiwayat(string type, string detail) {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    char timebuf[80];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %X", now);

    tipeTransaksi[jumHistory] = type;
    timeStamp[jumHistory] = timebuf;
    detilTransaki[jumHistory] = detail;

    jumHistory++;
}

//fungsi untuk melihat riwayat supplier
void mSeeRiwayat() {
    cout<<"================================================ \n";
    cout<<"==========----- RIWAYAT SUPPLIER -----=========="<<endl;
    cout<<"================================================ \n";

    for (int i = 0; i < jumHistory; i++) {
        cout<<"Jenis Transaksi  : "<<tipeTransaksi[i]<<endl;
        cout<<"Timestamp        : "<<timeStamp[i]<<endl;
        cout<<"Detail Transaksi : "<<detilTransaki[i]<<endl;
    }
    cout<<"================================================ \n";
}