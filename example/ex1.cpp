#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\view\viewAdmin.h"
#include "D:\Program\c++ warehouse fix\header\loginRegister.h"
#include "D:\Program\c++ warehouse fix\database\menuUtama.h"
#include "D:\Program\c++ warehouse fix\view\viewBarang.h"

using namespace std;

int main() {
    int pilih;
    int pilih2;

    mTambahAdmin("Abiyyu Ardilian", "abiyyuardi", "089532321212", "abiyyu213@gmail.com", "1234");
    mTambahAdmin("Ahmad Indra", "indraisman", "081193932222", "indrawibu@gmail.com", "2222");
    mTambahAdmin("Riski alvan", "riskialvan", "081112123434", "riskialvan@gmail.com", "3434");

    mAddBarang("gelas", "200", "001", "Kaca");

    bool keluarMenuGudang = false;

    do {
        loginRegister();
        cout<<"Masukkan pilihan anda : "; cin>>pilih;
        system("cls");#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\view\viewAdmin.h"
#include "D:\Program\c++ warehouse fix\header\loginRegister.h"
#include "D:\Program\c++ warehouse fix\database\menuUtama.h"
#include "D:\Program\c++ warehouse fix\view\viewBarang.h"

using namespace std;

int main() {
    int pilih;
    int pilih2;
    int pilih3;
    int pilih4;

    mTambahAdmin("Abiyyu Ardilian", "abiyyuardi", "089532321212", "abiyyu213@gmail.com", "1234");
    mTambahAdmin("Ahmad Indra", "indraisman", "081193932222", "indrawibu@gmail.com", "2222");
    mTambahAdmin("Riski alvan", "riskialvan", "081112123434", "riskialvan@gmail.com", "3434");

    mAddBarang("gelas", "200", "001", "Kaca");
    mAddBarang("piring", "150", "012", "kaca");
    mAddBarang("guci", "10", "009", "kaca");

    loginRegister();
    cout<<"Masukkan pilihan anda : "; cin>>pilih;
    system("cls");

    if (pilih == 1) {
        //tampilkan menu login
        vLogin();
        system("cls");

        //tampilkan menu gudang
        menuWarehouse();
        cout<<"Masukkan pilihan anda : "; cin>>pilih2;
        system("cls");

        if (pilih2 == 1) {
            //tampilkan menu tambah barang
            vAddBarang();
            
        } else if (pilih2 == 2) {
            //tampilkan menu informasi barang
            vViewBarang();

        } else if (pilih2 == 3) {
            //tampilkan menu cari barang
            vCariBarang();

        } else if (pilih2 == 4) {
            //tampilkan menu hapus barang
            vDeleteBarang();

        } else if (pilih2 == 5) {
            //tampilkan menu kirim barang
            vSendBarang();

        } else if (pilih2 == 6) {
            //tampilkan menu update barang
            vUpdateBarang();

        } else if (pilih2 == 7) {
            //kembali ke menu warehouse
            cout<<"===================================== \n";
            cout<<"=====----- PROGRAM SELESAI -----====="<<endl;
            cout<<"=====------- TERIMA KASIH ------====="<<endl;
            cout<<"===================================== \n";
        } else if (pilih2 > 6) {
            cout<<"========================================= \n";
            cout<<"=====----- PILIHAN TIDAK VALID -----====="<<endl;
            cout<<"=====------- PILIH MENU 1-5 --------====="<<endl;
            cout<<"========================================= \n";
        }

    } else if (pilih == 2) {
        //tampilkan menu tambah admin
        vTambahAdmin();
        mLihatAdmin();
        cout<<"1. Login?"<<endl;
        cout<<"2. Kembali ke menu admin"<<endl;
        cout<<endl;
        cout<<"Masukkan pilihan anda "; cin>>pilih4;
        system("cls");

        if (pilih4 == 1) {
            vLogin();
        } else if (pilih4 == 2) {
            loginRegister();
        }

    } else if (pilih == 3) {
        //tampilkan data admin
        vViewAdmin();
        cout<<"Masukkan pilihan anda : "; cin>>pilih3;
        system("cls");

        if (pilih3 == 1) {
            //update password admin
            vUpdtPass();

        } else if (pilih3 == 2) {
            //delete admin
            vDeleteAdmin();

        } else if (pilih3 == 3) {
            //kembali ke menu login register
            loginRegister();

        } else if (pilih3 > 3) {
            //ketika memilih diatas 3
            cout<<"=====----- Pilihan tidak valid -----====="<<endl;
        }
        
    } else if (pilih2 == 4) {
        //cari admin
        vCariAdmin();

    } else if (pilih2 == 5) {
        //pilih keluar
        cout<<"================================== \n";
        cout<<"=====----- TERIMA KASIH -----====="<<endl;
        cout<<"=====--- PROGRAM SELESAI ----====="<<endl;
        cout<<"================================== \n";

    } else if (pilih2 > 5) {
        cout<<"========================================= \n";
        cout<<"=====----- PILIHAN TIDAK VALID -----====="<<endl;
        cout<<"=====--- SILAHKAN PILIH MENU 1-3 ---====="<<endl;
        cout<<"========================================= \n";
    }

    return 0;
}

        switch(pilih) {
            case 1 :
                //login
                vLogin();
                system("cls");
                do {
                    menuWarehouse();
                    cout<<"Masukkan pilihan anda : "; cin>>pilih2;
                    system("cls");

                    switch(pilih2) {
                        case 1 :
                            //tambah barang
                            vAddBarang();
                            break;

                        case 2 :
                            //informasi barang
                            vViewBarang();
                            keluarMenuGudang = false;
                            break;

                        case 3 :
                            //hapus stok barang
                            vDeleteBarang();
                            break;

                        case 4 :
                            //kirim barang
                            vSendBarang();
                            break;

                        case 5 :
                            //update barang
                            vUpdateBarang();
                            break;

                        case 6 :
                            cout<<"================================= \n";
                            cout<<"=====--- PROGRAM SELESAI ---====="<<endl;
                            cout<<"=====---- TERIMA KASIH -----====="<<endl;
                            cout<<"================================= \n";

                            keluarMenuGudang = true; //set variabel keluar menu menjadi true
                            break;

                        default :
                            cout<<"================================== \n";
                            cout<<"======= PILIHAN TIDAK VALID ======="<<endl;
                            cout<<"=======-- Pilih menu 1-5 ---======="<<endl;
                            cout<<"=================================== \n";

                            break;
                    }
                } while (pilih2 < 1 || pilih2 > 6 || pilih2 != 6); //ubah kondisi loop
                break;

            case 2 :
                //tambah admin
                vTambahAdmin();
                mLihatAdmin();
                break;

            case 3 :
                //tampilkan data admin
                vViewAdmin();
                cout<<"Masukkan pilihan anda : "; cin>>pilih;

                switch(pilih) {
                    case 1 :
                        //update password admin
                        vUpdtPass();
                        break;

                    case 2 :
                        //delete admin
                        vDeleteAdmin();
                        break;

                    case 3 :
                        //kembali ke menu login register
                        loginRegister();
                        break;

                    default :
                        cout<<"===== Pilihan tidak valid ====="<<endl;
                }
                break;

            case 4 :
                //cari admin
                vCariAdmin();
                break;

            case 5 :
                //tidak memilih login maupun tambah admin
                cout<<"========================= \n";
                cout<<"====== TERIMA KASIH ====="<<endl;
                cout<<"==== PROGRAM SELESAI ===="<<endl;
                cout<<"========================= \n";

                keluarMenuGudang = true; //set variabel keluar menu menjadi true
                break;

            default :
                cout<<"================================= \n";
                cout<<"====== PILIHAN TIDAK VALID ======"<<endl;
                cout<<"==== SILAHKAN PILIH MENU 1-3 ===="<<endl;
                cout<<"================================= \n";
        }
    } while (pilih != 3 && !keluarMenuGudang); //kondisi menjadi loop

    return 0;
}