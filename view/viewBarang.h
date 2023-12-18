#include "D:\Program\c++ warehouse fix\model\modelBarang.h"
#include<iostream>
#include<string>

using namespace std;

void vAddBarang() {
    char addMore;

    do {
        string name;
        string stock;
        string seNumber;
        string category;

        cout<<"=================================== \n";
        cout<<"=====----- TAMBAH BARANG -----====="<<endl;
        cout<<"=================================== \n";
        cout<<"Nama barang : "; cin>>name;
        cout<<"Stok barang : "; cin>>stock;
        cout<<"Kode barang : "; cin>>seNumber;
        cout<<"Kategori    : "; cin>>category;
        mAddBarang(name, stock, seNumber, category);

        cout<<"=====--- Barang berhasil ditambahkan ---====="<<endl;
        mLihatBarang();

        cout<<"Apakah anda ingin menambah barang lagi? (y/n): ";
        cin>>addMore;
    } while (addMore == 'y' || addMore == 'Y');
}

void vViewBarang() {
    mLihatBarang();
}

void vCariBarang() {
    string seNumber;

    cout<<"================================= \n";
    cout<<"=====----- CARI BARANG -----====="<<endl;
    cout<<"================================= \n";
    cout<<endl;
    cout<<"Serial number : "; cin>>seNumber;
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"DATA BARANG"<<endl;
        cout<<"====================================================="<<endl;
        cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori"<<endl;
        cout<<"====================================================="<<endl;
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<sNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"====================================================="<<endl;
    } else {
        cout<<"===== Barang tidak ditemukan ====="<<endl;
    }
}

void vUpdateBarang() {
    string newStock;
    string seNumber;

    cout<<"=====----- UPDATE BARANG -----====="<<endl;
    cout<<"Kode barang : "; cin>>seNumber;

    //cek barang
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"Data barang sebelumnya"<<endl;
        cout<<"===================================================== \n";
        cout<<"Nama Barang\t\tJumlah Barang\t\tKode Barang\t\tKategori"<<endl;
        cout<<"===================================================== \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"===================================================== \n";

        //update informasi barang
        cout<<"Jumlah stok baru : "; cin>>newStock;

        //cek apakah stok valid
        if (stoi(newStock) >= 0) {
            //menambahkan stok baru
            mUpdateBarang(seNumber, newStock);
            vViewBarang();
        } else {
            cout<<"=====--- Jumlah stok tidak valid ---====="<<endl;
        }
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}

void vDeleteBarang() {
    string seNumber;

    cout<<"======================================= \n";
    cout<<"=====----- HAPUS STOK BARANG -----====="<<endl;
    cout<<"======================================= \n";
    cout<<endl;
    cout<<"Serial number : "; cin>>seNumber;
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"DATA BARANG"<<endl;
        cout<<"======================================================== \n";
        cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori"<<endl;
        cout<<"======================================================== \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"======================================================== \n";

        //konfirmasi penghapusan
        char yes;
        cout<<"Apakah anda yakin ingin menghapus stok barang ini? (y/n):";
        cin>>yes;

        if (yes == 'y' || yes == 'Y') {
            mDeleteBarang(seNumber);
            vViewBarang();
        } else {
            cout<<"=====--- Penghapusan dibatalkan ---====="<<endl;
        }
    }
}

void vSendBarang() {
    string seNumber;
    string jumlah;

    cout<<"=====----- KIRIM BARANG -----====="<<endl;
    cout<<"Kode barang : "; cin>>seNumber;

    //cek barang ditemukan
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"Data barang"<<endl;
        cout<<"================================================================= \n";
        cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori"<<endl;
        cout<<"================================================================= \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"================================================================= \n";

        //memasukan data pengiriman
        cout<<"Masukkan jumlah barang yang akan dikirim : "; cin>>jumlah;

        //cek apakah jumlah pengiriman valid
        if (stoi(jumlah) >= 0) {
            //mengurangi stok dan update barang
            mSendBarang(seNumber, jumlah);
            vViewBarang();
        } else {
            cout<<"=====--- Jumlah pengiriman tidak valid ---====="<<endl;
        }
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}