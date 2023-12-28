#include<iostream>
#include<string>

using namespace std;

//data admin warehouse
string namaAdmin[100];
string userName[100];
string phoneNumber[100];
string userEmail[100];
string password[100];
int dataAdmin; //untuk melihat informasi data admin

//data gudang
string namaBarang[100];
string stokBarang[100];
string sNumber[100];
string kotaTujuan[100];
string kategori[100];
string penyalur[100];
int DATA_BARANG;

void mTambahAdmin(string name, string user, string phone, string mail, string pass) {
    namaAdmin[dataAdmin] = name;
    userName[dataAdmin] = user;
    phoneNumber[dataAdmin] = phone;
    userEmail[dataAdmin] = mail;
    password[dataAdmin] = pass;
    dataAdmin++;
}

void mLihatAdmin() {
    cout<<"=====--- DATA ADMIN ---====="<<endl;
    cout<<"Jumlah admin : "<<dataAdmin<<endl;
    cout<<"========================================================================================================"<<endl;
    cout<<"Nama Admin\t\tUsername\t\tNo. Telp\t\tEmail\t\t\tPassword"<<endl;
    cout<<"========================================================================================================"<<endl;
    for (int i = 0; i < dataAdmin; i++) {
        cout<<namaAdmin[i]<<"\t\t"<<userName[i]<<"\t\t"<<phoneNumber[i]<<"\t\t"<<userEmail[i]<<"\t"<<password[i]<<endl;
    }
    cout<<"========================================================================================================"<<endl;
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


void mDeleteAdmin(string phone) {
    int index = mCariAdmin(phone);

    if (index != -1) {
        //menghapus admin dari array
        for (int i = 0; i < dataAdmin - 1; i++) {
            userName[i] = userName[i + 1];
            phoneNumber[i] = phoneNumber[i + 1];
            userEmail[i] = userEmail[i + 1];
            password[i] = password[i + 1];
        }
        dataAdmin--;

        cout<<"Admin berhasil dihapus."<<endl;;
    } else {
        cout<<"Admin tidak ditemukan."<<endl;
    }
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
    cout<<"========================================================= \n";
    cout<<"Nama Barang\tJumlah Stok\tKode Barang\tKategori"<<endl;
    cout<<"========================================================= \n";
    for (int i = 0; i < DATA_BARANG; i++) {
        cout<<namaBarang[i]<<"\t\t"<<stokBarang[i]<<"\t\t"<<sNumber[i]<<"\t\t"<<kategori[i]<<endl;
    }
    cout<<"========================================================= \n";
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

void vTambahAdmin() {
    string name;
    string user;
    string phone;
    string mail;
    string pass;

    cout<<"================================== \n";
    cout<<"=====----- TAMBAH ADMIN -----====="<<endl;
    cout<<"================================== \n";
    cout<<"= Nama         : "; cin>>name;
    cout<<"= Username     : "; cin>>user;
    cout<<"= No. Telepon  : "; cin>>phone;
    cout<<"= Email        : "; cin>>mail;
    cout<<"= Password     : "; cin>>pass;
    system("cls");
    mTambahAdmin(name, user, phone, mail, pass);

    cout<<endl;
    cout<<"================================================ \n";
    cout<<"=====----- Admin berhasil ditambahkan -----====="<<endl;
    cout<<"================================================ \n";
}

void vViewAdmin() {
    mLihatAdmin();

    cout<<endl;
    cout<<"=====--- Pilih opsi untuk edit admin ---====="<<endl;
    cout<<"= 1. Ubah password admin                    = \n";
    cout<<"= 2. Hapus admin                            = \n";
    cout<<"= 3. Kembali ke menu utama                  = \n";
    cout<<"============================================= \n";
}

void vCariAdmin() {
    string phone;

    cout<<"================================ \n";
    cout<<"=====----- CARI ADMIN -----====="<<endl;
    cout<<"=============================== \n";
    cout<<"Nomor telepon : "; cin>>phone;
    int index = mCariAdmin(phone);
    cout<<endl;

    if (index != -1) {
        cout<<"============================== DATA ADMIN ============================="<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"Nama\t\tUsername\tNo. Telp\t\tEmail\t\t\tPassword"<<endl;
        cout<<"=========================================="<<endl;
        cout<<namaAdmin[index]<<"\t"<<userName[index]<<"\t"<<phoneNumber[index]<<"\t\t"<<userEmail[index]<<"\t"<<password[index]<<endl;
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

void vDeleteAdmin() {
    string phone;

    cout<<"================================= \n";
    cout<<"=====----- HAPUS ADMIN -----====="<<endl;
    cout<<"================================= \n";
    cout<<endl;
    cout<<"= Nomor telepon : "; cin>>phone;
    cout<<endl;

    mDeleteAdmin(phone);
}

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
        cout<<endl;

        cout<<"============================================= \n";
        cout<<"=====--- Barang berhasil ditambahkan ---====="<<endl;
        cout<<"============================================= \n";
        cout<<endl;
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
        cout<<"========================================================= \n";
        cout<<"Nama Barang\tJumlah Stok\tKode Barang\tKategori"<<endl;
        cout<<"========================================================= \n";
        cout<<namaBarang[index]<<"\t\t"<<stokBarang[index]<<"\t\t"<<seNumber[index]<<"\t\t"<<kategori[index]<<endl;
        cout<<"========================================================= \n";

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

void menuWarehouse() {
    cout<<"===-- Selamat datang kembali admin --==="<<endl;
    cout<<endl;

    cout<<"======================================== \n";
    cout<<"===--- MENU INFORMASI PERGUDANGAN ---==="<<endl;
    cout<<"======================================== \n";
    cout<<"= 1. Tambah barang                     = \n";
    cout<<"= 2. Informasi barang                  = \n";
    cout<<"= 3. Hapus stok barang                 = \n";
    cout<<"= 4. Kirim barang                      = \n";
    cout<<"= 5. Update barang                     = \n";
    cout<<"= 6. Keluar                            = \n";
    cout<<"======================================== \n";
}

void loginRegister() {
    cout<<"========================================== \n";
    cout<<"===--- SISTEM INFORMASI PERGUDANGAN ---==="<<endl;
    cout<<"===-------- PT. OJONS PROPERTI --------==="<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl;
    cout<<"===------- Silahkan pilih menu --------==="<<endl;
    cout<<"= 1. Login admin                         = \n";
    cout<<"= 2. Tambah admin                        = \n";
    cout<<"= 3. Lihat data admin                    = \n";
    cout<<"= 4. Cari admin                          = \n";
    cout<<"= 5. Keluar                              = \n";
    cout<<"===------------------------------------=== \n";
}

int main() {
    int pilih;

    mTambahAdmin("Abiyyu Ardilian", "abiyyuardi", "089532321212", "abiyyu213@gmail.com", "1234");
    mTambahAdmin("Ahmad Indra", "indraisman", "081193932222", "indrawibu@gmail.com", "2222");
    mTambahAdmin("Riski alvan", "riskialvan", "081112123434", "riskialvan@gmail.com", "3434");

    mAddBarang("gelas", "200", "001", "Kaca");

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
                break;

            default :
                cout<<"================================= \n";
                cout<<"====== PILIHAN TIDAK VALID ======"<<endl;
                cout<<"==== SILAHKAN PILIH MENU 1-3 ===="<<endl;
                cout<<"================================= \n";
        }
    } while (pilih != 3);
}