#include<iostream>
#include<string>
#include "D:\Program\c++ warehouse fix\header\loginRegister.h"
#include "D:\Program\c++ warehouse fix\database\menuUtama.h"
#include "D:\Program\c++ warehouse fix\view\viewAdmin.h"
#include "D:\Program\c++ warehouse fix\view\viewBarang.h"
#include "D:\Program\c++ warehouse fix\view\viewSupplier.h"
#include "D:\Program\c++ warehouse fix\model\modelHistory.h"


using namespace std;

int main() {
    int pilih;
    int pilih2;
    int pilih3;

    //data statis user
    mTambahAdmin("Ahmad indra", "imismaindra", "089532321212", "indrawibu@gmail.com", "1234");
    mTambahAdmin("Habib jafar", "habibjawir", "081193932222", "habibjawir@gmail.com", "2222");
    mTambahAdmin("Riski maul", "riskimaul", "081112123434", "riskimaul@gmail.com", "3434");

    //data statis informasi barang
    mAddBarang("pipa allloy", "200 pcs", "M/RY001", "Mountbike", "Area A 3/14");
    mAddBarang("dropbar FSA", "150 pcs", "R/EZ012", "roadbike", "Area D 2/09");
    mAddBarang("carbon fork", "500 pcs", "R/UV009", "roadbike", "Area G 5/112");
    mAddBarang("Frame S2 56", "300 pcs", "R/S2149", "roadbike", "Area F 7/208");
    mAddBarang("Frame S3 55", "150 pcs", "R/S3008", "roadbike", "Area C 2/120");
    
    do {
        loginRegister();
        cout<<"Masukkan pilihan anda : "; cin>>pilih;
        system("cls");

        if (pilih == 1) {
            //tampilkan menu login
            vLogin();
            system("cls");

            do {
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
                    cout<<endl;

                } else if (pilih2 == 3) {
                    //tampilkan menu cari barang
                    vCariBarang();
                    cout<<endl;

                } else if (pilih2 == 4) {
                    //tampilkan menu hapus barang
                    vDeleteBarang();
                    cout<<endl;

                } else if (pilih2 == 5) {
                    //tampilkan menu kirim barang
                    vSendBarang();
                    cout<<endl;

                } else if (pilih2 == 6) {
                    //tampilkan menu update barang
                    vUpdateBarang();
                    cout<<endl;

                } else if (pilih2 == 7) {
                    //tampilkan menu pindah barang
                    vMoveBarang();
                    cout<<endl;

                } else if (pilih2 == 8) {
                    //tampilkan menu tambah supplier
                    vAddSupplier();
                    cout<<endl;

                } else if (pilih2 == 9) {
                    //tampilkan menu lihat riwayat transaksi
                    mSeeHistory();
                    cout<<endl;

                } else if (pilih2 == 10) {
                    //menampilkan history supplier
                    vSeeRiwayat();
                    cout<<endl;

                } else if (pilih2 == 11) {
                    //program selesai
                    cout<<"===================================== \n";
                    cout<<"=====----- PROGRAM SELESAI -----====="<<endl;
                    cout<<"=====------- TERIMA KASIH ------====="<<endl;
                    cout<<"===================================== \n";
                    cout<<endl;
                
                } else if (pilih2 > 10) {
                    cout<<"========================================= \n";
                    cout<<"=====----- PILIHAN TIDAK VALID -----====="<<endl;
                    cout<<"=====------- PILIH MENU 1 - 7 ------====="<<endl;
                    cout<<"========================================= \n";
                    cout<<endl;

                }
            } while (pilih2 != 10);

        } else if (pilih == 2) {
            //tampilkan menu tambah admin
            vTambahAdmin();

            //setelah menambah dan berhasil, tampilkan daftar admin
            mLihatAdmin();
            cout<<endl;

        } else if (pilih == 3) {
            //tampilkan data admin
            vViewAdmin();
            cout<<"Masukkan pilihan anda : "; cin>>pilih3;
            system("cls");

            if (pilih3 == 1) {
                //update password admin
                vUpdtPass();
                cout<<endl;

            } else if (pilih3 == 2) {
                //delete admin
                vDeleteAdmin();
                cout<<endl;

            } else if (pilih3 == 3) {
                //ketika pilihan diataS 3 menu
                cout<<"========================================= \n";
                cout<<"=====----- Pilihan tidak valid -----====="<<endl;
                cout<<"========================================= \n";
                cout<<endl;
            }

        } else if (pilih == 4) {
            //cari admin
            vCariAdmin();
            cout<<endl;

        } else if (pilih == 5) {
            //pilih keluar
            cout<<"================================== \n";
            cout<<"=====----- TERIMA KASIH -----====="<<endl;
            cout<<"=====--- PROGRAM SELESAI ----====="<<endl;
            cout<<"================================== \n";
            cout<<endl;

        } else if (pilih > 5) {
            //ketika pilihan tidak ada
            cout<<"========================================= \n";
            cout<<"=====----- PILIHAN TIDAK VALID -----====="<<endl;
            cout<<"=====--- SILAHKAN PILIH MENU 1-4 ---====="<<endl;
            cout<<"========================================= \n";
            cout<<endl;

        }

    } while (pilih != 5);

    return 0;
}