#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
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

#define MAX_MAHASISWA 5

int main()
{
    Mahasiswa  mhs[MAX_MAHASISWA];
    int pilihan;
    int panjang = 0; 

    do
    {
        cout << "\nMenu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan)
        {
        case 1:
            if (panjang == 0) 
                cout << "Belum ada data" << endl;
            else {
                cout << "\nData Mahasiswa:\n";
                for (int i = 0; i < panjang; i++) {
                    cout << "Nama   : " << mhs[i].nama << endl;
                    cout << "NIM    : " << mhs[i].nim << endl;
                    cout << "IPK    : " << mhs[i].ipk << endl;
                    cout << "Jalan  : " << mhs[i].alamat.jalan << endl;
                    cout << "Kota   : " << mhs[i].alamat.kota << endl;
                    cout << "------------------------" << endl;
                }
            }
            break;

        case 2:
            if (panjang < MAX_MAHASISWA) {
                cout << "Masukkan Nama: ";
                getline(cin, mhs[panjang].nama);
                cout << "Masukkan NIM: ";
                getline(cin, mhs[panjang].nim);
                cout << "Masukkan IPK: ";
                cin >> mhs[panjang].ipk;
                cin.ignore();
                cout << "Masukkan Jalan: ";
                getline(cin, mhs[panjang].alamat.jalan);
                cout << "Masukkan Kota: ";
                getline(cin, mhs[panjang].alamat.kota);
                
                panjang++; // Tambah jumlah data
                cout << "Data berhasil ditambahkan!\n";
            } else {
                cout << "Data penuh! Tidak bisa menambahkan lebih banyak.\n";
            }
            break;

        case 3:
            cout << "Fitur ubah data belum tersedia" << endl;
            break;
        case 4:
            cout << "Fitur hapus data belum tersedia" << endl;
            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}