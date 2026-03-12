
#include<iostream>
using namespace std;

struct Universitas{
    string namaUniversitas;
    string fakultas;
    string prodi;
};

struct Warga{
    string namaWarga;
    string passwordWarga;
    string tanggalLahir;
    string tempatTinggal;
    string asalSMA;
    string angkatanMasuk;
    string nomorKamar;
    Universitas kampus;
    string nomorTelepon;
    string nomorOrangTua;
};

#define MAX_WARGA 54
int jumlahWarga = 0;
Warga warga[MAX_WARGA]; 

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
    cout << "=====================================\n";
    cout << "|            MENU UTAMA             |\n";
    cout << "=====================================\n";
    cout << "|1. Lihat Data Warga                |\n";
    cout << "|2. Tambah Data Warga               |\n";
    cout << "|3. Ubah Data Warga                 |\n";
    cout << "|4. Hapus Data Warga                |\n";
    cout << "|5. Keluar                          |\n";
    cout << "=====================================\n";
    cout << "Pilih menu (1-5): ";
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
void tambahWarga(Warga DaftarWarga[], int &jumlahWarga) {
    if (jumlahWarga < MAX_WARGA) {
                    cin.ignore();
                    cout << "Masukkan nama warga: ";
                    getline(cin, DaftarWarga[jumlahWarga].namaWarga);
                    cout << "Masukkan tanggal lahir: ";
                    getline(cin, DaftarWarga[jumlahWarga].tanggalLahir);
                    cout << "Masukkan tempat tinggal: ";
                    getline(cin, DaftarWarga[jumlahWarga].tempatTinggal);
                    cout << "Masukkan asal SMA: ";
                    getline(cin, DaftarWarga[jumlahWarga].asalSMA);
                    cout << "Masukkan angkatan masuk: ";
                    cin >> DaftarWarga[jumlahWarga].angkatanMasuk;
                    cout << "Masukkan nomor kamar: ";
                    cin >> DaftarWarga[jumlahWarga].nomorKamar;
                    cout << "Masukkan nama universitas: ";
                    cin.ignore();
                    getline(cin, DaftarWarga[jumlahWarga].kampus.namaUniversitas);
                    cout << "Masukkan fakultas: ";
                    getline(cin, DaftarWarga[jumlahWarga].kampus.fakultas);
                    cout << "Masukkan prodi: ";
                    getline(cin, DaftarWarga[jumlahWarga].kampus.prodi);
                    cout << "Masukkan nomor telepon: ";
                    cin >> DaftarWarga[jumlahWarga].nomorTelepon;
                    cout << "Masukkan nomor orang tua: ";
                    cin >> DaftarWarga[jumlahWarga].nomorOrangTua;
                    jumlahWarga++;
                    cout << "Data warga berhasil ditambahkan.\n";
                    } else {
                    cout << "Kapasitas warga sudah penuh.\n";
                }
    }
void tambahWarga(Warga DaftarWarga[], int &jumlahWarga, Warga dataBaru) {
    if (jumlahWarga >= MAX_WARGA) {
        cout << "Kapasitas warga sudah penuh.\n";
        return;
    }
    DaftarWarga[jumlahWarga] = dataBaru;
    jumlahWarga++;
    cout << "Data warga berhasil ditambahkan.\n";
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
                        cout << "Masukkan nama warga baru: ";
                        getline(cin, DaftarWarga[index - 1].namaWarga);
                        cout << "Masukkan tanggal lahir baru: ";
                        getline(cin, DaftarWarga[index - 1].tanggalLahir);
                        cout << "Masukkan tempat tinggal baru: ";
                        getline(cin, DaftarWarga[index - 1].tempatTinggal);
                        cout << "Masukkan asal SMA baru: ";
                        getline(cin, DaftarWarga[index - 1].asalSMA);
                        cout << "Masukkan angkatan masuk baru: ";
                        cin >> DaftarWarga[index - 1].angkatanMasuk;
                        cout << "Masukkan nomor kamar baru: ";
                        cin >> DaftarWarga[index - 1].nomorKamar;
                        cout << "Masukkan nama universitas baru: ";
                        cin.ignore();
                        getline(cin, DaftarWarga[index - 1].kampus.namaUniversitas);
                        cout << "Masukkan fakultas baru: ";
                        getline(cin, DaftarWarga[index - 1].kampus.fakultas);
                        cout << "Masukkan prodi baru: ";
                        getline(cin, DaftarWarga[index - 1].kampus.prodi);
                        cout << "Masukkan nomor telepon baru: ";
                        cin >> DaftarWarga[index - 1].nomorTelepon;
                        cout << "Masukkan nomor orang tua baru: ";
                        cin >> DaftarWarga[index - 1].nomorOrangTua;
                        cout << "Data warga berhasil diubah.\n";
                    } else {
                        cout << "Nomor warga tidak valid.\n";
                    }
                }
    }
void hapusWarga(Warga DaftarWarga[], int &jumlahWarga) {
    int index;
    if(jumlahWarga == 0) {
                    cout << "Belum ada data warga untuk dihapus.\n";
                } else {
                    cout << "Daftar Warga:\n";
                    cout << "======================================\n";
                    for (int i = 0; i < jumlahWarga; i++) {
                        cout << "Warga ke-" << i + 1 <<endl;
                        cout << "Nama Warga: " << DaftarWarga[i].namaWarga<<endl;
                        cout << "----------------------------------\n";
                    }
                    cout << "Masukkan nomor warga yang ingin dihapus (1-" << jumlahWarga << "): ";
                    cin >> index;
                    if (index > 0 && index <= jumlahWarga) {
                        for (int i = index - 1; i < jumlahWarga - 1; i++) {
                            DaftarWarga[i] = DaftarWarga[i + 1];
                        }
                        jumlahWarga--;
                        cout << "Data warga berhasil dihapus.\n";
                    } else {
                        cout << "Nomor warga tidak valid.\n";
                    }
                }
}
int main() {
    Warga dataAwal;
    dataAwal.namaWarga = "Jaki";
    dataAwal.passwordWarga = "061";
    dataAwal.tanggalLahir = "21-03-2007";
    dataAwal.tempatTinggal = "BERAU";
    dataAwal.asalSMA = "SMAN 1 BERAU";
    dataAwal.angkatanMasuk = "2025";
    dataAwal.nomorKamar = "01";
    dataAwal.kampus.namaUniversitas = "Universitas MULAWARMAN";
    dataAwal.kampus.fakultas = "Teknik";
    dataAwal.kampus.prodi = "Informatika";
    dataAwal.nomorTelepon = "08129876543";
    dataAwal.nomorOrangTua = "08129876543";
    tambahWarga(warga, jumlahWarga, dataAwal); 

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
                tambahWarga(warga, jumlahWarga); 
                break;
            case 3:
                ubahWarga(warga, jumlahWarga);
                break;
            case 4:
                hapusWarga(warga, jumlahWarga);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem data anak asrama!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu 1-5.\n";
        }
    } while (pilihanMenu != 5);

    return 0;
}