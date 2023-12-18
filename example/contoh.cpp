#include<iostream>
#include<string>

using namespace std;

string userName[100];
string phoneNumber[100];
string userEmail[100];
string password[100];
int dataAdmin; //untuk melihat informasi data admin

string namaBarang[100];
string stokBarang[100];
string sNumber[100];
string kotaTujuan[100];
string kategori[100];
string penyalur[100];
int DATA_BARANG;

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

void mAddBarang(string name, string stock, string seNumber, string category) {
    namaBarang[DATA_BARANG] = name;
    stokBarang[DATA_BARANG] = stock;
    sNumber[DATA_BARANG] = seNumber;
    kategori[DATA_BARANG] = category;
    DATA_BARANG++;
}

void mLihatBarang() {
    cout<<"=====--- DATA BARANG ---====="<<endl;
    cout<<"Jumlah barang : "<<DATA_BARANG<<endl;
    cout<<"==================================================================== \n";
    cout<<"Nama Barang\t\tJumlah Stok\t\tKode Barang\t\tKategori"<<endl;
    cout<<"==================================================================== \n";
    for (int i = 0; i < DATA_BARANG; i++) {
        cout<<namaBarang[i]<<"\t\t"<<stokBarang[i]<<"\t\t"<<sNumber[i]<<"\t\t"<<kategori[i]<<endl;
    }
    cout<<"==================================================================== \n";
}

int mSearchBarang(string seNumber) {
    for (int i = 0; i < DATA_BARANG; i++) {
        if (sNumber[i] == seNumber) {
            return i;
        }
    }
    return -1;
}

void mUpdateBarang(string seNumber, string stock) {
    //cek barang
    int index = mSearchBarang(seNumber);
    if (index != 1) {
        stokBarang[index] = stock;
        cout<<"=====--- Jumlah barang berhasil di update ---====="<<endl;
    } else {
        cout<<"=====--- Barang tidak ditemukan ---====="<<endl;
    }
}

void vAddBarang() {
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
    string name;
    string seNumber;

    cout<<"=====----- UPDATE BARANG -----====="<<endl;
    cout<<"Nama barang : "; cin>>name;
    cout<<"Kode barang : "; cin>>seNumber;
    //mUpdateBarang(name);
}

void loginRegister() {
    cout<<"========================================== \n";
    cout<<"===--- SISTEM INFORMASI PERGUDANGAN ---==="<<endl;
    cout<<"===-------- PT. OJONS PROPERTI --------==="<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl;
    cout<<"===------- Silahkan pilih menu --------==="<<endl;
    cout<<"1. Login admin \n";
    cout<<"2. Tambah admin \n";
    cout<<"3. Lihat data admin \n";
    cout<<"4. Keluar \n";
    cout<<"===------------------------------------=== \n";
}

void menuWarehouse() {
    cout<<"===--- Selamat datang kembali "<<userName<<" ---==="<<endl;
    cout<<endl;

    cout<<"======================================== \n";
    cout<<"===--- MENU INFORMASI PERGUDANGAN ---==="<<endl;
    cout<<"======================================== \n";
    cout<<"1. Tambah barang \n";
    cout<<"2. Informasi barang \n";
    cout<<"3. Hapus stok barang \n";
    cout<<"4. Kirim barang \n";
    cout<<"5. Keluar \n";
    cout<<"======================================== \n";
}

int main() {
    int pilih;
    char restart;

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
                            system("cls");
                            cout<<"=====--- Barang berhasil ditambahkan ---====="<<endl;
                            vViewBarang();

                            cout<<"Apakah anda ingin menambah barang lagi? (y/n)";
                            cin>>restart;
                            if (restart == 'y' || restart == 'Y') {
                                system("cls");
                                vAddBarang();
                            } else {
                                system("cls");
                                menuWarehouse();
                            }
                            break;

                        case 2 :
                            //informasi barang
                            vViewBarang();
                            break;

                        case 3 :
                            //hapus stok barang
                            break;

                        case 4 :
                            //kirim barang
                            break;

                        case 5 :
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
                } while (pilih != 5);
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