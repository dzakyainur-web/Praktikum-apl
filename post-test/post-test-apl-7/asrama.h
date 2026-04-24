#ifndef ASRAMA_H
#define ASRAMA_H

#include <string>
using namespace std;

struct Universitas {
    string namaUniversitas;
    string fakultas;
    string prodi;
};

struct Warga {
    string namaWarga;
    string passwordWarga;
    string tanggalLahir;
    string tempatTinggal;
    string asalSMA;
    int angkatanMasuk;
    int nomorKamar;
    Universitas kampus;
    string nomorTelepon;
    string nomorOrangTua;
};

#endif