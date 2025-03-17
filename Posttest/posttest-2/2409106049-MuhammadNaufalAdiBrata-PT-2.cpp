#include <iostream>
#include <iomanip> // Untuk manipulasi tabel
#include <string>
using namespace std;

#define MAX_LAPANGAN 5

// Struktur data untuk lapangan
struct Lapangan {
    string id;
    string harga;
    string lokasi;
    string status;
};

int kesempatanLogin = 3;
string userLogin[2];
int jumlahLapangan = 0;
int pilihanMenu;

// Array of struct untuk menyimpan data lapangan
Lapangan dataLapangan[MAX_LAPANGAN];

int main() {
    while (kesempatanLogin > 0) {
        cout << "Masukkan Nama : ";
        cin >> userLogin[0];
        cout << "Masukkan Nim : ";
        cin >> userLogin[1];

        if (userLogin[0] == "Naufal" && userLogin[1] == "6049") {
            cout << "Login berhasil!" << endl;
            break; 
        } else {
            kesempatanLogin--;
            if (kesempatanLogin > 0) {
                cout << "Login gagal! Anda memiliki " << kesempatanLogin << " kesempatan lagi." << endl;
            } else {
                cout << "Anda telah mencapai batas kesempatan login. Silakan ulang nanti." << endl;
                return 0; 
            }
        }
    }

    do {
        cout << "\n============================" << endl;
        cout << "\nMenu Program Lapangan Futsal" << endl;
        cout << "1. Tambah lapangan" << endl;
        cout << "2. Lihat lapangan" << endl;
        cout << "3. Ubah lapangan" << endl;
        cout << "4. Hapus lapangan" << endl;
        cout << "5. Exit" << endl;
        cout << "============================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: 
                if (jumlahLapangan < MAX_LAPANGAN) {
                    string idLapangan;
                    cout << "Masukkan ID lapangan : ";
                    cin >> idLapangan; 

                    bool idUsed = false; 
                    for (int i = 0; i < jumlahLapangan; i++) {
                        if (dataLapangan[i].id == idLapangan) {
                            idUsed = true; 
                            break;
                        }
                    }

                    if (idUsed) {
                        cout << "ID lapangan sudah digunakan! Silakan masukkan ID yang berbeda." << endl;
                    } else {
                        dataLapangan[jumlahLapangan].id = idLapangan; 
                        cout << "Masukkan harga sewa lapangan : ";
                        cin >> dataLapangan[jumlahLapangan].harga; 
                        cout << "Masukkan lokasi lapangan : ";
                        cin >> dataLapangan[jumlahLapangan].lokasi; 
                        cout << "Masukkan status ketersediaan lapangan: ";
                        cin >> dataLapangan[jumlahLapangan].status; 
                        cout << "Tambah Lapangan Berhasil !!" << endl;
                        jumlahLapangan++;
                    }
                } else {
                    cout << "Lapangan sudah penuh!" << endl;
                }
                break;

            case 2:
                if (jumlahLapangan == 0) {
                    cout << "Lapangan masih kosong!" << endl;
                } else {
                    cout << "\n=== DAFTAR LAPANGAN FUTSAL ===" << endl;

                    cout << "+" << setfill('-') << setw(13) << "+" << setw(13) << "+" << setw(15) << "+" << setw(13) << "+" << endl;
                    cout << "| " << setfill(' ') << left << setw(11) << "ID Lapangan" << "| "
                        << setw(11) << "Harga Sewa" << "| "
                        << setw(13) << "Lokasi" << "| "
                        << setw(11) << "Status" << "|" << endl;
                    cout << "+" << setfill('-') << setw(13) << "+" << setw(13) << "+" << setw(15) << "+" << setw(13) << "+" << endl;
                    
                    for (int i = 0; i < jumlahLapangan; i++) {
                        cout << "| " << setfill(' ') << left << setw(11) << dataLapangan[i].id << "| "
                            << setw(11) << dataLapangan[i].harga << "| "
                            << setw(13) << dataLapangan[i].lokasi << "| "
                            << setw(11) << dataLapangan[i].status << "|" << endl;
                    }
                    
                    cout << "+" << setfill('-') << setw(13) << "+" << setw(13) << "+" << setw(15) << "+" << setw(13) << "+" << endl;
                }
                break;

            case 3: 
                if (jumlahLapangan == 0) {
                    cout << "Lapangan masih kosong!" << endl;
                } else {
                    cout << "\n=== DAFTAR ID LAPANGAN ===" << endl;
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    cout << "| " << setfill(' ') << left << setw(5) << "No" << "| "
                        << setw(23) << "ID Lapangan" << "|" << endl;
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    
                    for (int i = 0; i < jumlahLapangan; i++) {
                        cout << "| " << setfill(' ') << left << setw(5) << i + 1 << "| "
                            << setw(23) << dataLapangan[i].id << "|" << endl;
                    }
                    
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    
                    int idLapanganUbah;
                    cout << "Masukkan nomor lapangan yang akan diubah: ";
                    cin >> idLapanganUbah;
                    
                    if (idLapanganUbah > 0 && idLapanganUbah <= jumlahLapangan) {
                        cout << "Masukkan harga sewa lapangan baru: ";
                        cin >> dataLapangan[idLapanganUbah - 1].harga;
                        cout << "Masukkan lokasi lapangan baru: ";
                        cin >> dataLapangan[idLapanganUbah - 1].lokasi; 
                        cout << "Masukkan status ketersediaan lapangan baru: ";
                        cin >> dataLapangan[idLapanganUbah - 1].status; 
                        cout << "Lapangan berhasil diubah!" << endl;
                    } else {
                        cout << "Nomor lapangan tidak valid!" << endl;
                    }
                }
                break;

            case 4: 
                if (jumlahLapangan == 0) {
                    cout << "Lapangan masih kosong!" << endl;
                } else {
                    cout << "\n=== DAFTAR ID LAPANGAN ===" << endl;
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    cout << "| " << setfill(' ') << left << setw(5) << "No" << "| "
                        << setw(23) << "ID Lapangan" << "|" << endl;
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    
                    for (int i = 0; i < jumlahLapangan; i++) {
                        cout << "| " << setfill(' ') << left << setw(5) << i + 1 << "| "
                            << setw(23) << dataLapangan[i].id << "|" << endl;
                    }
                    
                    cout << "+" << setfill('-') << setw(7) << "+" << setw(25) << "+" << endl;
                    
                    int idLapanganHapus;
                    cout << "Pilih nomor lapangan yang ingin dihapus: ";
                    cin >> idLapanganHapus;

                    if (idLapanganHapus > 0 && idLapanganHapus <= jumlahLapangan) {
                        for (int i = idLapanganHapus - 1; i < jumlahLapangan - 1; i++) {
                            dataLapangan[i].id = dataLapangan[i + 1].id;
                            dataLapangan[i].harga = dataLapangan[i + 1].harga;
                            dataLapangan[i].lokasi = dataLapangan[i + 1].lokasi;
                            dataLapangan[i].status = dataLapangan[i + 1].status;
                        }
                        jumlahLapangan--;
                        cout << "Lapangan berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor lapangan tidak valid!" << endl;
                    }
                }
                break;

            case 5: 
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihanMenu != 5);

    return 0;
}