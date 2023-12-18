#include <iostream>
#include <string>

using namespace std;

const int MAX_BARANG = 100;

struct Barang {
    string nama;
    int jumlah;
};

class Pergudangan {
private:
    Barang daftarBarang[MAX_BARANG];
    int jumlahBarang;

public:
    Pergudangan() : jumlahBarang(0) {}

    void tambahBarang(const string& namaBarang, int jumlahBarang) {
        if (this->jumlahBarang < MAX_BARANG) {
            daftarBarang[this->jumlahBarang].nama = namaBarang;
            daftarBarang[this->jumlahBarang].jumlah = jumlahBarang;
            this->jumlahBarang++;
            cout << "Barang berhasil ditambahkan.\n";
        } else {
            cout << "Gudang penuh, tidak dapat menambahkan barang.\n";
        }
    }

    void tampilkanBarang() {
        if (jumlahBarang > 0) {
            cout << "Daftar Barang:\n";
            for (int i = 0; i < jumlahBarang; ++i) {
                cout << i + 1 << ". " << daftarBarang[i].nama << " - " << daftarBarang[i].jumlah << " buah\n";
            }
        } else {
            cout << "Gudang kosong.\n";
        }
    }

    void hapusBarang(int index, int jumlahHapus) {
        if (index >= 0 && index < jumlahBarang) {
            if (jumlahHapus > 0 && jumlahHapus <= daftarBarang[index].jumlah) {
                daftarBarang[index].jumlah -= jumlahHapus;
                cout << "Stok barang berhasil dikurangi.\n";
                if (daftarBarang[index].jumlah == 0) {
                    // Jika stok habis, hapus barang dari gudang
                    for (int i = index; i < jumlahBarang - 1; ++i) {
                        daftarBarang[i] = daftarBarang[i + 1];
                    }
                    jumlahBarang--;
                    cout << "Barang berhasil dihapus karena stok habis.\n";
                }
            } else {
                cout << "Jumlah barang yang akan dihapus tidak valid.\n";
            }
        } else {
            cout << "Indeks barang tidak valid.\n";
        }
    }
};

int main() {
    Pergudangan gudang;

    gudang.tambahBarang("Pensil", 50);
    gudang.tambahBarang("Buku", 20);
    gudang.tambahBarang("Gunting", 10);

    gudang.tampilkanBarang();

    int indeksHapus, jumlahHapus;
    cout << "Masukkan indeks barang yang akan dihapus: ";
    cin >> indeksHapus;
    cout << "Masukkan jumlah barang yang akan dihapus: ";
    cin >> jumlahHapus;

    gudang.hapusBarang(indeksHapus - 1, jumlahHapus);

    gudang.tampilkanBarang();

    return 0;
}
