#include<iostream>
#include<string>
#include <stdexcept>
#include "asrama.h"
using namespace std;

#define MAX_WARGA 54

bool login(Warga Daftarwarga[], int jumlahWarga) {
    string nama, password;
    cout << "=====================================\n";
    cout << "         SISTEM DATA ANAK ASRAMA      \n";
    cout << "=====================================\n";
    cout << "Login Terlebih Dahulu\n";
    cout << "Nama     : ";
    getline(cin, nama);
    cout << "Password : ";
    cin >> password;
    cin.ignore();
    
    for (int i = 0; i < jumlahWarga; i++) {
        if (nama == Daftarwarga[i].namaWarga && password == Daftarwarga[i].passwordWarga) {
            cout << "\nLogin Berhasil! Selamat datang, " << nama << endl;
            return true;
        }
    }
    
    cout << "Nama atau Password salah!\n";
    return false;
}

void tampilkanMenu () {
    cout << "\n=====================================\n";
    cout << "|            MENU UTAMA             |\n";
    cout << "=====================================\n";
    cout << "|1. Lihat Data Warga                |\n";
    cout << "|2. Tambah Data Warga               |\n";
    cout << "|3. Ubah Data Warga                 |\n";
    cout << "|4. Hapus Data Warga                |\n";
    cout << "|5. Urutkan Data Warga              |\n";
    cout << "|6. Cari Data Warga                 |\n";
    cout << "|7. Keluar                          |\n";
    cout << "=====================================\n";
    cout << "Pilih menu (1-7): ";
}

void lihatWarga(Warga DaftarWarga[], int jumlahWarga, int index) {
    if (jumlahWarga == 0) {
        cout << "Belum ada data warga.\n";
        return;
    }
    if (index == 0) {
        cout << "================================================================================================================================\n";
        cout << "No | Nama | Asal SMA | Universitas | Fakultas | Prodi | Kamar | Telepon | Telp Ortu                                             |\n";
        cout << "================================================================================================================================\n";
    }
    if (index == jumlahWarga) return; 
    
    cout << index + 1 << " | "
        << DaftarWarga[index].namaWarga << " | "
        << DaftarWarga[index].asalSMA << " | "
        << DaftarWarga[index].kampus.namaUniversitas << " | "
        << DaftarWarga[index].kampus.fakultas << " | "
        << DaftarWarga[index].kampus.prodi << " | "
        << DaftarWarga[index].nomorKamar << " | "
        << DaftarWarga[index].nomorTelepon << " | "
        << DaftarWarga[index].nomorOrangTua << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
    
    lihatWarga(DaftarWarga, jumlahWarga, index + 1);
}

void tambahWarga(Warga DaftarWarga[], int *ptrJumlahWarga) {
    try {
        if (*ptrJumlahWarga >= MAX_WARGA) {  
            throw runtime_error("Kapasitas warga sudah penuh.");
        }
        cin.ignore();
        Warga *wargaBaru = &DaftarWarga[*ptrJumlahWarga]; 

        cout << "Masukkan nama warga: ";
        getline(cin, wargaBaru->namaWarga); 
        cout << "Masukkan tanggal lahir: ";
        getline(cin, wargaBaru->tanggalLahir);
        cout << "Masukkan tempat tinggal: ";
        getline(cin, wargaBaru->tempatTinggal);
        cout << "Masukkan asal SMA: ";
        getline(cin, wargaBaru->asalSMA);
        cout << "Masukkan angkatan masuk: ";
        cin >> wargaBaru->angkatanMasuk;
        if(cin.fail()) throw invalid_argument("Angkatan masuk harus berupa angka!");

        cout << "Masukkan nomor kamar: ";
        cin >> wargaBaru->nomorKamar;
        if(cin.fail()) throw invalid_argument("Nomor kamar harus berupa angka!");
        cin.ignore();
        cout << "Masukkan nama universitas: ";
        getline(cin, wargaBaru->kampus.namaUniversitas);
        cout << "Masukkan fakultas: ";
        getline(cin, wargaBaru->kampus.fakultas);
        cout << "Masukkan prodi: ";
        getline(cin, wargaBaru->kampus.prodi);
        
        cout << "Masukkan nomor telepon: ";
        cin >> wargaBaru->nomorTelepon;
        cout << "Masukkan nomor orang tua: ";
        cin >> wargaBaru->nomorOrangTua;
        
        (*ptrJumlahWarga)++; 
        cout << "Data warga berhasil ditambahkan.\n";
    } catch (const exception& e) {
        cout << "ERROR: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void tambahWarga(Warga DaftarWarga[], int *ptrJumlahWarga, Warga dataBaru) {
    if (*ptrJumlahWarga >= MAX_WARGA) {
        cout << "Kapasitas warga sudah penuh.\n";
        return;
    }
    DaftarWarga[*ptrJumlahWarga] = dataBaru;
    (*ptrJumlahWarga)++; 
}

void ubahWarga(Warga DaftarWarga[], int jumlahWarga) {
    int index;
    if(jumlahWarga == 0) {
        cout << "Belum ada data warga untuk diubah.\n";
    } else {
        cout << "Daftar Warga:\n";
        cout << "======================================\n";
        for (int i = 0; i < jumlahWarga; i++) {
            cout << "Warga ke-" << i + 1 <<endl;
            cout << "Nama Warga: " << DaftarWarga[i].namaWarga<<endl;
            cout << "----------------------------------\n";
        }
        cout << "Masukkan nomor warga yang ingin diubah (1-" << jumlahWarga << "): ";
        cin >> index;
        if (index > 0 && index <= jumlahWarga) {
            cin.ignore();
            Warga *wargaUbah = &DaftarWarga[index - 1]; 
            cout << "Masukkan nama warga baru: ";
            getline(cin, wargaUbah->namaWarga); 
            cout << "Masukkan tanggal lahir baru: ";
            getline(cin, wargaUbah->tanggalLahir);
            cout << "Masukkan tempat tinggal baru: ";
            getline(cin, wargaUbah->tempatTinggal);
            cout << "Masukkan asal SMA baru: ";
            getline(cin, wargaUbah->asalSMA);
            cout << "Masukkan angkatan masuk baru: ";
            cin >> wargaUbah->angkatanMasuk;
            cout << "Masukkan nomor kamar baru: ";
            cin >> wargaUbah->nomorKamar;
            
            cin.ignore();
            cout << "Masukkan nama universitas baru: ";
            getline(cin, wargaUbah->kampus.namaUniversitas);
            cout << "Masukkan fakultas baru: ";
            getline(cin, wargaUbah->kampus.fakultas);
            cout << "Masukkan prodi baru: ";
            getline(cin, wargaUbah->kampus.prodi);
            
            cout << "Masukkan nomor telepon baru: ";
            cin >> wargaUbah->nomorTelepon;
            cout << "Masukkan nomor orang tua baru: ";
            cin >> wargaUbah->nomorOrangTua;
            cout << "Data warga berhasil diubah.\n";
        } else {
            cout << "Nomor warga tidak valid.\n";
        }
    }
}

void hapusWarga(Warga DaftarWarga[], int *ptrJumlahWarga) {
    int index;
    if(*ptrJumlahWarga == 0) {
        cout << "Belum ada data warga untuk dihapus.\n";
    } else {
        cout << "Daftar Warga:\n";
        cout << "======================================\n";
        for (int i = 0; i < *ptrJumlahWarga; i++) {
            cout << "Warga ke-" << i + 1 <<endl;
            cout << "Nama Warga: " << DaftarWarga[i].namaWarga<<endl;
            cout << "----------------------------------\n";
        }
        cout << "Masukkan nomor warga yang ingin dihapus (1-" << *ptrJumlahWarga << "): ";
        cin >> index;
        try {
            if (cin.fail()) {
                throw invalid_argument("Input harus berupa angka!");
            }
            if (index <= 0 || index > *ptrJumlahWarga) {
                throw out_of_range("Nomor warga tidak valid!");
            }
            for (int i = index - 1; i < *ptrJumlahWarga - 1; i++) {
                DaftarWarga[i] = DaftarWarga[i + 1];
            }
            (*ptrJumlahWarga)--;
            cout << "Data warga berhasil dihapus.\n";
        } catch (const exception& e) {
            cout << "ERROR: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}
void bubblesort(Warga DaftarWarga[], int n){
    for (int i = 0; i < n-1; i++){
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++){
            if (DaftarWarga[j].namaWarga > DaftarWarga[j+1].namaWarga){
                swap(DaftarWarga[j], DaftarWarga[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    } 
}

void selectionsort(Warga DaftarWarga[], int n){
    for (int i = 0; i < n-1; i++){
        int indexMax = i;
        for (int j = i+1; j < n; j++){
            if (DaftarWarga[j].nomorKamar > DaftarWarga[indexMax].nomorKamar){
                indexMax = j;
            }
        }
        if (indexMax != i) {
            swap(DaftarWarga[i], DaftarWarga[indexMax]);
        }
    }
}

void insertionsort(Warga DaftarWarga[], int n){
    for (int i = 1; i < n; i++){
        Warga key = DaftarWarga[i];
        int j = i - 1;
        while (j >= 0 && DaftarWarga[j].angkatanMasuk > key.angkatanMasuk){
            DaftarWarga[j + 1] = DaftarWarga[j];
            j = j - 1;
        }
        DaftarWarga[j + 1] = key;
    }
}

int binarySearch(Warga DaftarWarga[], int n, string *namaCari) {
    int low = 0;
    int high = n -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (DaftarWarga[mid].namaWarga == *namaCari) {
            cout << "Data warga dengan nama " << *namaCari << " ditemukan:\n";
            cout << "Nama Warga: " << DaftarWarga[mid].namaWarga << endl;
            cout << "Asal SMA: " << DaftarWarga[mid].asalSMA << endl;
            cout << "Universitas: " << DaftarWarga[mid].kampus.namaUniversitas << endl;
            cout << "Fakultas: " << DaftarWarga[mid].kampus.fakultas << endl;
            cout << "Prodi: " << DaftarWarga[mid].kampus.prodi << endl;
            cout << "Nomor Kamar: " << DaftarWarga[mid].nomorKamar << endl;
            cout << "Nomor Telepon: " << DaftarWarga[mid].nomorTelepon << endl;
            cout << "Nomor Orang Tua: " << DaftarWarga[mid].nomorOrangTua << endl;
            return mid;
        }
        else if (DaftarWarga[mid].namaWarga < *namaCari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Data warga dengan nama " << *namaCari << " tidak ditemukan.\n";
    return -1;
}

void linearSearch(Warga DaftarWarga[], int n, int *noKamarCari) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++){
        if (DaftarWarga[i].nomorKamar == *noKamarCari) {
            cout << "Data warga dengan nomor kamar " << *noKamarCari << " ditemukan:\n";
            cout << "Nama Warga: " << DaftarWarga[i].namaWarga << endl;
            cout << "Asal SMA: " << DaftarWarga[i].asalSMA << endl;
            cout << "Universitas: " << DaftarWarga[i].kampus.namaUniversitas << endl;
            cout << "Fakultas: " << DaftarWarga[i].kampus.fakultas << endl;
            cout << "Prodi: " << DaftarWarga[i].kampus.prodi << endl;
            cout << "Nomor Telepon: " << DaftarWarga[i].nomorTelepon << endl;
            cout << "Nomor Orang Tua: " << DaftarWarga[i].nomorOrangTua << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "tidak ada warga di kamar " << *noKamarCari << ".\n";
    }
}

int main() {
    Warga warga[MAX_WARGA]; 
    int jumlahWarga = 0; 

    Warga dataAdmin;
    dataAdmin.namaWarga = "Jaki";
    dataAdmin.passwordWarga = "061";
    dataAdmin.tanggalLahir = "21-03-2007";
    dataAdmin.tempatTinggal = "BERAU";
    dataAdmin.asalSMA = "SMAN 1 BERAU";
    dataAdmin.angkatanMasuk = 2025;
    dataAdmin.nomorKamar = 15;
    dataAdmin.kampus.namaUniversitas = "Universitas MULAWARMAN";
    dataAdmin.kampus.fakultas = "Teknik";
    dataAdmin.kampus.prodi = "Informatika";
    dataAdmin.nomorTelepon = "08129876543";
    dataAdmin.nomorOrangTua = "08129876543";

Warga data1 = {"Attar", "046", "19-07-2007", "BERAU", "SMAN 2 BERAU", 2024, 5, {"Universitas MULAWARMAN", "Hukum", "Ilmu Hukum"}, "082153902990", "081234567890"};
Warga data2 = {"Ridho", "065", "29-12-2007", "BERAU", "SMAN 1 BERAU", 2023, 10, {"Universitas MULAWARMAN", "Teknik", "Informatika"}, "08129876543", "08129876543"};

    tambahWarga(warga, &jumlahWarga, dataAdmin); 
    tambahWarga(warga, &jumlahWarga, data1);
    tambahWarga(warga, &jumlahWarga, data2);

    int kesempatan = 0;
    bool loginBerhasil = false;
    while (kesempatan < 3) {
        loginBerhasil = login(warga, jumlahWarga);
        if (loginBerhasil) break;
        kesempatan++;
        cout << "Kesempatan tersisa: " << 3 - kesempatan << "\n";
    }
    if (!loginBerhasil) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihanMenu;
    do {
        tampilkanMenu();
        cin >> pilihanMenu;
        switch (pilihanMenu) {
            case 1:
                lihatWarga(warga, jumlahWarga, 0);
                break;
            case 2:
                tambahWarga(warga, &jumlahWarga); 
                break;
            case 3:
                ubahWarga(warga, jumlahWarga);
                break;
            case 4:
                hapusWarga(warga, &jumlahWarga);
                break;
            case 5:
                cout << "Pilih metode pengurutan:\n";
                cout << "1. Urutkan Nama warga (A-Z)\n";
                cout << "2. Urut berdasarkan nomor kamar \n";
                cout << "3. Urut berdasarkan angkatan masuk\n";
                int pilihanSort;
                cout << "Masukkan pilihan Sorting (1-3): ";
                cin >> pilihanSort;
                switch (pilihanSort) {
                    case 1:
                        bubblesort(warga, jumlahWarga);
                        cout << "Data warga berhasil diurutkan berdasarkan nama (A-Z).\n";
                        lihatWarga(warga, jumlahWarga, 0);
                        break;
                    case 2:
                        selectionsort(warga, jumlahWarga);
                        cout << "Data warga berhasil diurutkan berdasarkan nomor kamar.\n";
                        lihatWarga(warga, jumlahWarga, 0);
                        break;
                    case 3:
                        insertionsort(warga, jumlahWarga);
                        cout << "Data warga berhasil diurutkan berdasarkan angkatan masuk.\n";
                        lihatWarga(warga, jumlahWarga, 0);
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            case 6: {
                int pilihanCari;
                cout << "Pilih metode pencarian:\n";
                cout << "1. Cari berdasarkan nama\n";
                cout << "2. Cari berdasarkan nomor kamar\n";
                cin >> pilihanCari; 
                switch(pilihanCari) {
                    case 1: {
                        cin.ignore();
                        string namaCari;
                        cout << "Masukkan nama yang ingin dicari: ";
                        getline(cin, namaCari);
                        bubblesort(warga, jumlahWarga); 
                        binarySearch(warga, jumlahWarga, &namaCari);
                        break;
                    }
                    case 2: {
                        int noKamarCari;
                        cout << "Masukkan nomor kamar yang ingin dicari: ";
                        cin >> noKamarCari;
                        linearSearch(warga, jumlahWarga, &noKamarCari);
                        break;
                        }
                    default:
                        cout << "Pilihan tidak valid.\n";
                        break;
                }
                break;
            }
            case 7:
                cout << "Terima kasih telah menggunakan sistem data anak asrama!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu 1-7.\n";
        }
    } while (pilihanMenu != 7);
    return 0;
}




