#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\database\dataGudang.h"
#include "D:\Program\c++ warehouse fix\database\dataPindah.h"

using namespace std;

void mAddBarang(string name, string stock, string seNumber, string category, string area) {
    namaBarang[DATA_BARANG] = name;
    stokBarang[DATA_BARANG] = stock;
    sNumber[DATA_BARANG] = seNumber;
    kategori[DATA_BARANG] = category;
    storageArea[DATA_BARANG] = area;
    DATA_BARANG++;
}

void mLihatBarang() {
    cout<<"===================================---------- DATA BARANG ----------===================================="<<endl;
    cout<<"Jumlah barang : "<<DATA_BARANG<<endl;
    cout<<"======================================================================================================== \n";
    cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori\tArea Penyimpanan"<<endl;
    cout<<"======================================================================================================== \n";
    for (int i = 0; i < DATA_BARANG; i++) {
        cout<<namaBarang[i]<<"\t\t"<<stokBarang[i]<<"\t\t\t"<<sNumber[i]<<"\t\t\t"<<kategori[i]<<"\t"<<storageArea[i]<<endl;
    }
    cout<<"======================================================================================================== \n";
}

int mSearchBarang(string seNumber) {
    for (int i = 0; i < DATA_BARANG; i++) {
        if (sNumber[i] == seNumber) {
            return i;
        }
    }
    return -1;
}

void mUpdateBarang(string seNumber, string newStock) {
    //cek barang
    int index = mSearchBarang(seNumber);
    if (index != 1) {
        stokBarang[index] = to_string(stoi(stokBarang[index]) + stoi(newStock));
        cout<<"=====--- Jumlah barang berhasil di update ---====="<<endl;
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}

void mDeleteBarang(string seNumber) {
    //cek barang
    int index = mSearchBarang(seNumber);
    if (index != -1) {
        //hapus stok barang
        stokBarang[index] = "0";
        cout<<"=====--- Stok barang berhasil dihapus ---====="<<endl;
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}

void mSendBarang(string seNumber, string jumlah) {
    //cek barang
    int index = mSearchBarang(seNumber);
    if (index != -1) {
        //kurangi stok barang sesuai jumlah yang dikirim
        int jumlahStok = stoi(stokBarang[index]);
        int jumlahKirim = stoi(jumlah);

        if (jumlahKirim <= jumlahStok) {
            stokBarang[index] = to_string(jumlahStok - jumlahKirim);
            cout<<"=====--- Barang berhasil dikirim ---====="<<endl;
        } else {
            cout<<"=====--- Jumlah stok tidak mencukupi ---====="<<endl;
        }
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}

void mMoveBarang(string seNumber, string moveArea, string quantity, string shifter) {
    //cek barang
    int index = mSearchBarang(seNumber);
    if (index != 1) {
        //konversi jumlah ke tipe data integer
        int jumlahPindah = stoi(quantity);

        //validasi jumlah stok yang akan dipindah
        if (jumlahPindah > 0 && jumlahPindah <= stoi(stokBarang[index])) {
            //simpan informasi barang yang akan dipindahkan
            namaBarangPindah[DATA_BARANG_PINDAH] = namaBarang[index];
            stokBarangPindah[DATA_BARANG_PINDAH] = to_string(jumlahPindah);
            sNumberPindah[DATA_BARANG_PINDAH] = sNumber[index];
            kategoriPindah[DATA_BARANG_PINDAH] = kategori[index];
            stokBarangPindah[DATA_BARANG_PINDAH] = moveArea[index];
            penyalurPindah[DATA_BARANG_PINDAH] = shifter[index];

            DATA_BARANG_PINDAH++;

            //kurangi stok barang dari area asal
            stokBarang[index] = to_string(stoi(stokBarang[index]) - jumlahPindah);

            cout<<"================================================= \n";
            cout<<"=====----- Barang berhasil dipindahkan -----====="<<endl;
            cout<<"================================================= \n";

        } else {
            cout<<"================================================== \n";
            cout<<"=====----- Jumlah stok tidak valid atau -----====="<<endl;
            cout<<"=====----- melebihi dari kapasitas stok -----====="<<endl;
            cout<<"================================================== \n";
        }

    } else {
        cout<<"============================================ \n";
        cout<<"=====----- Barang tidak ditemukan -----====="<<endl;
        cout<<"============================================ \n";
    }
}