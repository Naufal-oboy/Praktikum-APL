#include <iostream>
using namespace std;

#define MAX_BUAH 100 // Ukuran maksimum array buah

int main() {
    int panjang = 0; // Jumlah elemen saat ini
    string buah[MAX_BUAH]; // Array dengan ukuran tetap
    int pilihan, index;

    do {
        cout << "\nMenu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1:
                if (panjang == 0) {
                    cout << "Belum ada buah." << endl;
                } else {
                    cout << "Daftar Buah:" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
                    }
                }
                break;
            
            case 2:
                if (panjang < MAX_BUAH) {
                    cout << "Masukkan nama buah: ";
                    getline(cin, buah[panjang]);
                    panjang++;
                    cout << "Buah berhasil ditambahkan." << endl;
                } else {
                    cout << "Kapasitas penuh! Tidak bisa menambah buah lagi." << endl;
                }
                break;

            case 3:
                if (panjang == 0) {
                    cout << "Belum ada buah untuk diubah." << endl;
                } else {
                    cout << "Daftar Buah:" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
                    }
                    cout << "Masukkan nomor buah yang akan diubah: ";
                    cin >> index;
                    cin.ignore(); // Hindari bug input
                    if (index > 0 && index <= panjang) {
                        cout << "Masukkan nama buah baru: ";
                        getline(cin, buah[index - 1]);
                        cout << "Buah berhasil diubah." << endl;
                    } else {
                        cout << "Nomor buah tidak valid." << endl;
                    }
                }
                break;

            case 4:
                if (panjang == 0) {
                    cout << "Belum ada buah untuk dihapus." << endl;
                } else {
                    cout << "Daftar Buah:" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
                    }
                    cout << "Masukkan nomor buah yang akan dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= panjang) {
                        for (int i = index - 1; i < panjang - 1; i++) {
                            buah[i] = buah[i + 1];
                        }
                        panjang--;
                        cout << "Buah berhasil dihapus." << endl;
                    } else {
                        cout << "Nomor buah tidak valid." << endl;
                    }
                }
                break;

            case 5:
                cout << "Program selesai." << endl;
                break;
            
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << "\nTekan ENTER untuk melanjutkan...";
        cin.get(); // Menunggu input sebelum clear screen
    } while (pilihan != 5);
    
    return 0;
}
