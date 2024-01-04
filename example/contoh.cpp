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
string storageArea[100];
string moveArea[100];
string penyalur[100];
int DATA_BARANG; //informasi data gudang

//database barang yang akan dipindahkan
string namaBarangPindah[100];
string stokBarangPindah[100];
string sNumberPindah[100];
string kategoriPindah[100];
string storageAreaPindah[100];
string penyalurPindah[100];

int DATA_BARANG_PINDAH; //menyimpan informasi barang yang dipindahkan

//database untuk menyimpan informasi supplier
string namaSupplier[100];
string alamatSupplier[100];
string kontakSupplier[100];
string emailSupplier[100];
int dataSupplier; //untuk menyimpan informasi supplier

void loginRegister() {
    cout<<"======================================================== \n";
    cout<<"=====-------- SISTEM INFORMASI PERGUDANGAN --------====="<<endl;
    cout<<"=====---------- PT. OJONS BIKE INDONESIA ----------====="<<endl;
    cout<<"======================================================== \n";
    cout<<endl;
    cout<<"=====------------ Silahkan pilih menu -------------====="<<endl;
    cout<<"= 1. Login admin                                       = \n";
    cout<<"= 2. Tambah admin                                      = \n";
    cout<<"= 3. Lihat data admin                                  = \n";
    cout<<"= 4. Cari admin                                        = \n";
    cout<<"= 5. Keluar                                            = \n";
    cout<<"======================================================== \n";
}

void menuWarehouse() {
    cout<<"=====---- Selamat datang kembali admin ----====="<<endl;
    cout<<endl;

    cout<<"================================================ \n";
    cout<<"=====----- MENU INFORMASI PERGUDANGAN -----====="<<endl;
    cout<<"================================================ \n";
    cout<<"= 1. Tambah barang                             = \n";
    cout<<"= 2. Informasi barang                          = \n";
    cout<<"= 3. Cari barang                               = \n";
    cout<<"= 4. Hapus stok barang                         = \n";
    cout<<"= 5. Kirim barang                              = \n";
    cout<<"= 6. Update barang                             = \n";
    cout<<"= 7. Pindahkan barang ke divisi produksi       = \n";
    cout<<"= 8. Tambah supplier                           = \n";
    cout<<"= 9. Lihat riwayat transaksi                   = \n";
    cout<<"= 10. Keluar                                   = \n";
    cout<<"================================================ \n";
}

void mTambahAdmin(string name, string user, string phone, string mail, string pass) {
    namaAdmin[dataAdmin] = name;
    userName[dataAdmin] = user;
    phoneNumber[dataAdmin] = phone;
    userEmail[dataAdmin] = mail;
    password[dataAdmin] = pass;
    dataAdmin++;
}
void mLihatAdmin() {
    cout<<"=========================================----- DATA ADMIN -----========================================="<<endl;
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

void vTambahAdmin() {
    string name;
    string user;
    string phone;
    string mail;
    string pass;

    cout<<"============================================ \n";
    cout<<"=====---------- TAMBAH ADMIN ----------====="<<endl;
    cout<<"============================================ \n";
    cin.ignore();
    cout<<"= Nama         : ";
    getline(cin, name);
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

    cout<<endl;
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
    cout<<"================================ \n";
    cout<<endl;
    cout<<"Nomor telepon : "; cin>>phone;
    int index = mCariAdmin(phone);
    cout<<endl;

    if (index != -1) {
        cout<<"== Data admin ditemukan!"<<endl;
        cout<<endl;
        cout<<"=========================================----- DATA ADMIN -----========================================="<<endl;
        cout<<"========================================================================================================"<<endl;
        cout<<"Nama\t\tUsername\tNo. Telp\t\tEmail\t\t\tPassword"<<endl;
        cout<<"========================================================================================================"<<endl;
        cout<<namaAdmin[index]<<"\t"<<userName[index]<<"\t"<<phoneNumber[index]<<"\t\t"<<userEmail[index]<<"\t"<<password[index]<<endl;
        cout<<"========================================================================================================"<<endl;
    } else {
        cout<<"No. Telp tidak ditemukan"<<endl;
    }
}

void vUpdtPass() {
    string phone;
    string pass;

    cout<<"===================================== \n";
    cout<<"=====----- UPDATE PASSWORD -----====="<<endl;
    cout<<"===================================== \n";
    cout<<"No. Telepon  : "; cin>>phone;
    cout<<"New Password : "; cin>>pass;
    mUpdtAdmin(phone, pass);
}

void vLogin() {
    string userName;
    string password;

    cout<<"================================= \n";
    cout<<"=====----- LOGIN ADMIN -----====="<<endl;
    cout<<"================================= \n";
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

void vMoveBarang() {
    string sNumber;
    string moveArea;
    string stokBarang;
    string shifter;

    cout<<"====================================================== \n";
    cout<<"=====----- PINDAH BARANG KE DIVISI PRODUKSI -----====="<<endl;
    cout<<"====================================================== \n";
    cout<<endl;
    cout<<"====================================================== \n";
    cout<<"= Serial number    : "; cin>>sNumber;
    cout<<"= Divisi tujuan    : "; cin>>moveArea;
    cout<<"= Jumlah stok      : "; cin>>stokBarang;
    cout<<"= Penanggung jawab : "; cin>>shifter;
    cout<<"====================================================== \n";
    cout<<endl;

    //pindahkan barang
    mMoveBarang(sNumber, moveArea, stokBarang, shifter);
    cout<<endl;

    vViewBarang(); 
}

void vAddSupplier() {
    string name;
    string addres;
    string kontak;
    string email;
    
    cout<<"===================================== \n";
    cout<<"=====----- TAMBAH SUPPLIER -----====="<<endl;
    cout<<"===================================== \n";
    cout<<"= Nama Supplier : "; cin>>name;
    cout<<"= Alamat        : "; cin>>addres;
    cout<<"= Kontak        : "; cin>>kontak;
    cout<<"= Email         : "; cin>>email;
    cout<<"===================================== \n";

    mAddSupplier(name, addres, kontak, email);
    cout<<"=================================================== \n";
    cout<<"=====----- Supplier berhasil ditambahkan -----====="<<endl;
    cout<<"=================================================== \n";
}

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
                    //vLihatRiwayat();
                    cout<<endl;

                } else if (pilih2 == 10) {
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
            } while (pilih2 != 7);

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