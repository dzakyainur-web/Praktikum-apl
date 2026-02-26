#include<iostream>
using namespace std;

int main() { 
    string namaUser,passwordUser;
    string passwordBenar = "061";
    int Jumlahlogin = 0;

while(Jumlahlogin<3) {
    cout << "====================================="<<endl;
    cout << "|         SISTEM KONVERSI WAKTU     |"<<endl;
    cout << "====================================="<<endl;
    cout << "Login Terlebih Dahulu"<<endl;
    cout << "Nama     : " ;
    cin >> namaUser;
    cout << "Password : " ;
    cin >> passwordUser; 

    if(passwordUser==passwordBenar) {
        cout << "Login berhasil!! Selamat datang, " << namaUser << endl;
        break;
    } else {
        Jumlahlogin++;
        cout << "PASSWORD SALAH!!!" << endl;
        cout << "Kesempatan mu sisa " << 3 - Jumlahlogin << endl;
    }
}
    if(Jumlahlogin==3) {
        cout << "GAGAL LOGIN, KESEMPATAN MU HABIS!!!" << endl;
        return 0;
    }

int pilihanMenu;
do {
    cout << "====================================="<<endl;
    cout << "|         MENU UTAMA KONVERSI       |"<<endl;
    cout << "====================================="<<endl;
    cout << "|1. JAM → MENIT DAN DETIK           |"<<endl;
    cout << "|2. MENIT → JAM DAN DETIK           |"<<endl;
    cout << "|3. DETIK → JAM DAN MENIT           |"<<endl;
    cout << "|4. KELUAR MENU                     |"<<endl;
    cout << "====================================="<<endl;
    cout << "Masukkan pilihan mu : ";
    cin >> pilihanMenu;
    
    double jam, menit, detik;
    switch (pilihanMenu) {

    case 1: 
        cout << "====================================="<<endl;
        cout << "|1. JAM → MENIT DAN DETIK           |"<<endl;
        cout << "====================================="<<endl;
        cout << "Masukkan nilai jam : "; 
        cin >> jam; cout << " jam"<<endl; 
        menit = jam * 60;
        detik = jam * 3600;
        cout << jam << " jam = " << menit << " menit"<<endl;
        cout << jam << " jam = " << detik << " detik"<<endl;
        break;

    case 2:
        cout << "====================================="<<endl;
        cout << "|2. MENIT → JAM DAN DETIK           |"<<endl;
        cout << "====================================="<<endl;
        cout << "Masukkan nilai menit : "; 
        cin >> menit; cout << " menit"<<endl;
        jam = menit / 60;
        detik = menit * 60;
        cout << menit << " menit = " << jam << " jam"<<endl;
        cout << menit << " menit = " << detik << " detik"<<endl;
        break;

    case 3:
        cout << "====================================="<<endl;
        cout << "|3. DETIK → JAM DAN MENIT           |"<<endl;
        cout << "====================================="<<endl;
        cout << "Masukkan nilai detik : "; 
        cin >> detik; cout << " detik"<<endl;
        jam = detik / 3600;
        menit = detik / 60;
        cout << detik << " detik = " << jam << " jam"<<endl;
        cout << detik << " detik = " << menit << " menit"<<endl;
        break;
    case 4:
        cout << "====================================="<<endl;
        cout << "|Terima kasih, program selesai.     |"<<endl;
        cout << "====================================="<<endl;
        break;
    default:
        cout << "Pilihan tidak tersedia, silakan pilih menu yang benar." << endl;
    }
}
    while (pilihanMenu != 4);
return 0;
}
