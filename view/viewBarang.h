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
        string storageArea;

        cout<<"============================================= \n";
        cout<<"==========----- TAMBAH BARANG -----=========="<<endl;
        cout<<"============================================= \n";
        cin.ignore();
        cout<<"Nama barang  : ";
        getline(cin, name);
        cout<<"Stok barang  : ";
        getline(cin, stock);
        cout<<"Kode barang  : ";
        getline(cin, seNumber);
        cout<<"Kategori     : ";
        getline(cin, category);
        cout<<"Storage area : ";
        getline(cin, storageArea);
        mAddBarang(name, stock, seNumber, category, storageArea);
        cout<<endl;

        cout<<"============================================= \n";
        cout<<"=====--- Barang berhasil ditambahkan ---====="<<endl;
        cout<<"============================================= \n";
        cout<<endl;
        mLihatBarang();

        cout<<endl;
        cout<<"Apakah anda ingin menambah barang lagi? (y/n): ";
        cin>>addMore;
        system("cls");
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
        cout<<"========================================================================================================"<<endl;
        cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori\tArea Penyimpanan"<<endl;
        cout<<"======================================================================================================== \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t\t"<<sNumber[index]<<"\t\t\t"<<kategori[index]<<"\t"<<storageArea[index]<<endl;
        cout<<"======================================================================================================== \n";
    } else {
        cout<<"===== Barang tidak ditemukan ====="<<endl;
    }
}

void vUpdateBarang() {
    string newStock;
    string seNumber;

    cout<<"=================================== \n";
    cout<<"=====----- UPDATE BARANG -----====="<<endl;
    cout<<"=================================== \n";
    cout<<endl;
    cout<<"Kode barang : "; cin>>seNumber;

    //cek barang
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"Data barang sebelumnya"<<endl;
        cout<<"================================================================================ \n";
        cout<<"Nama Barang\t\tJumlah Barang\t\tKode Barang\t\tKategori"<<endl;
        cout<<"================================================================================ \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"================================================================================ \n";
        cout<<endl;

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

    cout<<"================================== \n";
    cout<<"=====----- KIRIM BARANG -----====="<<endl;
    cout<<"================================== \n";
    cout<<endl;
    cout<<"Kode barang : "; cin>>seNumber;

    //cek barang ditemukan
    int index = mSearchBarang(seNumber);

    if (index != -1) {
        cout<<"Data barang"<<endl;
        cout<<"================================================================================ \n";
        cout<<"Nama Barang\tJumlah Stok\tKode Barang\tKategori"<<endl;
        cout<<"================================================================================ \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"================================================================================ \n";

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