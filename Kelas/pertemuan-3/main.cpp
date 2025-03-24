#include <iostream>
using namespace std;


struct Alamat {
    string jalan;
    string no;
    string kota;

};


struct Mahasiswa {
    string nama;
    string nim;
    string prodi;
    float ipk;
    int angkatan;
    Alamat alamat;

};

int main () {
    Mahasiswa mhs1 ;
    Mahasiswa mhs2 ;
    mhs1.nama = "Naufal";
    mhs1.nim = "6049";
    mhs1.prodi = "Teknik Informatika";
    mhs1.ipk = 3.5;
    mhs1.angkatan = 2024;
    mhs1.alamat.jalan = "Jalan Pramuka";
    mhs1.alamat.no = "123";
    mhs1.alamat.kota = "Samarinda";

    mhs2.nama = "Harahap";
    mhs2.nim = "6050";
    mhs2.prodi = "Teknik Informatika";
    mhs2.ipk = 3.8;
    mhs2.angkatan = 2024;

    cout << "Nama : " << mhs1.nama << endl;
    cout << "NIM : " << mhs1.nim << endl;
    cout << "Prodi : " << mhs1.prodi << endl;
    cout << "IPK : " << mhs1.ipk << endl;
    cout << "Angkatan : " << mhs1.angkatan << endl;
    cout << "Alamat : " << mhs1.alamat.jalan << endl;
    cout << mhs1.alamat.no << endl;
    


    cout << "Nama : " << mhs2.nama << endl;
    cout << "NIM : " << mhs2.nim << endl;
    cout << "Prodi : " << mhs2.prodi << endl;
    cout << "IPK : " << mhs2.ipk << endl;
    cout << "Angkatan : " << mhs2.angkatan << endl;

    return 0;
}