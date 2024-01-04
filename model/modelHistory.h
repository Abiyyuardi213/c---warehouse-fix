#ifndef MODELHISTORY_H
#define MODELHISTORY_H
#include<iostream>
#include<string>
#include<ctime>
#include "D:\Program\c++ warehouse fix\database\dataHistory.h"

using namespace std;

//fungsi untuk menambah riwayat
void mRiwayatTransaksi(string type, string detail) {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    tanggalTransaksi[jumlahTransaksi] = buffer;

    strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
    waktuTransaksi[jumlahTransaksi] = buffer;

    jenisTransaksi[jumlahTransaksi] = type;
    detailTransaksi[jumlahTransaksi] = detail;

    jumlahTransaksi++;
}

//fungsi untuk menampilkan riwayat
void mSeeHistory() {
    cout<<"================================================================================ \n";
    cout<<"==========-------------- RIWAYAT TRANSAKSI PERGUDANGAN ---------------=========="<<endl;
    cout<<"================================================================================ \n";
    cout<<"No.\tTanggal\t\tWaktu\t\tJenis Transaksi\t\tDetail Transaksi"<<endl;
    cout<<"================================================================================ \n";

    for (int i = 0; i < jumlahTransaksi; i++) {
        cout<<i + 1<<"\t"<<tanggalTransaksi[i]<<"\t"<<waktuTransaksi[i]<<"\t"<<jenisTransaksi[i]<<"\t\t"<<detailTransaksi[i]<<endl;
    }

    cout<<"================================================================================ \n";
}

#endif