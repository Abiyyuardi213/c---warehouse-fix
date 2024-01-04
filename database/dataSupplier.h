#include<iostream>
#include<string>
#include<ctime>

using namespace std;

//database untuk menyimpan informasi supplier
string namaSupplier[100];
string alamatSupplier[100];
string kontakSupplier[100];
string emailSupplier[100];
int dataSupplier; //untuk menyimpan informasi supplier

//database untuk menyimpan informasi histori supplier
string tipeTransaksi[100];
string timeStamp[100];
string detilTransaki[100];
int jumHistory = 0; //untuk menyimpan seluruh informasi transaksi supplier

