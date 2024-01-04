#include <iostream>
#include <string>
#include <ctime> // Untuk mengakses fungsi waktu

using namespace std;

// ... (kode yang sudah ada)

string jenisTransaksi[100];
string timestamp[100];
string detailTransaksi[100];
int jumlahRiwayat = 0;

// ... (kode yang sudah ada)

void tambahRiwayat(string jenisTrans, string detailTrans) {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    char timebuf[80];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %X", now);

    jenisTransaksi[jumlahRiwayat] = jenisTrans;
    timestamp[jumlahRiwayat] = timebuf;
    detailTransaksi[jumlahRiwayat] = detailTrans;

    jumlahRiwayat++;
}

// ... (kode yang sudah ada)

void mAddSupplier(string name, string addres, string kontak, string email) {
    namaSupplier[dataSupplier] = name;
    alamatSupplier[dataSupplier] = addres;
    kontakSupplier[dataSupplier] = kontak;
    emailSupplier[dataSupplier] = email;

    dataSupplier++;

    // Menambahkan riwayat transaksi
    string detailTransaksi = "Nama Supplier: " + name + ", Alamat: " + addres + ", Kontak: " + kontak + ", Email: " + email;
    tambahRiwayat("Tambah Supplier", detailTransaksi);
}

// ... (kode yang sudah ada)

void mLihatRiwayat() {
    cout << "====================================== \n";
    cout << "=====----- RIWAYAT TRANSAKSI -----=====\n";
    cout << "====================================== \n";
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << "Jenis Transaksi: " << jenisTransaksi[i] << "\n";
        cout << "Timestamp: " << timestamp[i] << "\n";
        cout << "Detail Transaksi: " << detailTransaksi[i] << "\n";
        cout << "-------------------------------------- \n";
    }
    cout << "====================================== \n";
}

// ... (kode yang sudah ada)

int main() {
    // ... (kode yang sudah ada)

    } else if (pilih2 == 9) {
        //tampilkan menu lihat riwayat transaksi
        mLihatRiwayat();
        cout << endl;
    } 

    // ... (kode yang sudah ada)

    return 0;
}
