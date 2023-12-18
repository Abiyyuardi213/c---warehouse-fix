#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\view\viewAdmin.h"
#include "D:\Program\c++ warehouse fix\header\loginRegister.h"
#include "D:\Program\c++ warehouse fix\database\menuUtama.h"
#include "D:\Program\c++ warehouse fix\view\viewBarang.h"

using namespace std;

int main() {
    int pilih;

    mTambahAdmin("abiyyuardi", "089532321212", "abiyyu213@gmail.com", "1234");

    do {
        loginRegister();
        cout<<"Masukkan pilihan anda : "; cin>>pilih;
        system("cls");

        switch(pilih) {
            case 1 :
                //login
                vLogin();
                system("cls");
                do {
                    menuWarehouse();
                    cout<<"Masukkan pilihan anda : "; cin>>pilih;
                    system("cls");

                    switch(pilih) {
                        case 1 :
                            //tambah barang
                            vAddBarang();
                            break;

                        case 2 :
                            //informasi barang
                            vViewBarang();
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
                            break;

                        default :
                            cout<<"================================== \n";
                            cout<<"======= PILIHAN TIDAK VALID ======="<<endl;
                            cout<<"=======-- Pilih menu 1-5 ---======="<<endl;
                            cout<<"=================================== \n";
                    }
                } while (pilih != 6);
                break;

            case 2 :
                //tambah admin
                vTambahAdmin();
                cout<<"====--- Data admin berhasil ditambahkan ---===="<<endl;
                vViewAdmin();
                break;

            case 3 :
                //tampilkan data admin
                vViewAdmin();
                break;

            case 4 :
                //tidak memilih login maupun tambah admin
                cout<<"========================= \n";
                cout<<"====== TERIMA KASIH ====="<<endl;
                cout<<"==== PROGRAM SELESAI ===="<<endl;
                cout<<"========================= \n";
                break;

            default :
                cout<<"================================= \n";
                cout<<"====== PILIHAN TIDAK VALID ======"<<endl;
                cout<<"==== SILAHKAN PILIH MENU 1-3 ===="<<endl;
                cout<<"================================= \n";
        }
    } while (pilih != 3);
}