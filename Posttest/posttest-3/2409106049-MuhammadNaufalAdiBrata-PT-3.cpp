#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_LAPANGAN 5
#define MAX_USER 10

struct InformasiKontak {
    string alamat;
    string telepon;
};

struct Pengguna {
    string nama;
    string nim;
    string peran; 
    InformasiKontak kontak; 
};

struct Lapangan {
    string id;
    string harga;
    string lokasi;
    string status;
};

int main() {
    int kesempatanLogin = 3; 
    Pengguna daftarPengguna[MAX_USER];
    int dataUser  = 0; 
    Lapangan daftarLapangan[MAX_LAPANGAN];
    int jumlahLapangan = 0;

    daftarPengguna[dataUser ].nama = "Naufal";
    daftarPengguna[dataUser ].nim = "6049";
    daftarPengguna[dataUser ].peran = "admin";
    daftarPengguna[dataUser ].kontak.alamat = "Sempaja"; 
    daftarPengguna[dataUser ].kontak.telepon = "083153058333"; 
    dataUser ++;

    int pilihanMenuUtama;
    do {
        cout << "\n============================" << endl;
        cout << "Menu Registrasi/Login" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "============================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenuUtama;

        switch (pilihanMenuUtama) {
            case 1: {
                if (dataUser  < MAX_USER) {
                    cout << "Masukkan Nama: ";
                    cin >> daftarPengguna[dataUser ].nama;
                    cout << "Masukkan NIM: ";
                    cin >> daftarPengguna[dataUser ].nim;

                    cout << "Masukkan Peran (admin/member): ";
                    cin >> daftarPengguna[dataUser ].peran;

                    cout << "Masukkan Alamat: ";
                    cin.ignore(); 
                    getline(cin, daftarPengguna[dataUser ].kontak.alamat);
                    cout << "Masukkan Nomor Telepon: ";
                    cin >> daftarPengguna[dataUser ].kontak.telepon;

                    dataUser ++;
                    cout << "Registrasi berhasil!" << endl;
                } else {
                    cout << "Jumlah pengguna sudah mencapai batas maksimum!" << endl;
                }
                break;
            }
            case 2: {
                string nama, nim;
                bool loginBerhasil = false;
                string peranPengguna;

                while (kesempatanLogin > 0) {
                    cout << "Masukkan Nama: ";
                    cin >> nama;
                    cout << "Masukkan NIM: ";
                    cin >> nim;


                    for (int i = 0; i < dataUser ; i++) {
                        if (daftarPengguna[i].nama == nama && daftarPengguna[i].nim == nim) {
                            cout << "Login berhasil! Peran Anda: " << daftarPengguna[i].peran << endl;
                            loginBerhasil = true;
                            peranPengguna = daftarPengguna[i].peran; 
                            break;
                        }
                    }

                    if (loginBerhasil) {
                        int pilihanMenu;
                        if (peranPengguna == "admin") {
                            do {
                                cout << "\n============================" << endl;
                                cout << "Menu Admin" << endl;
                                cout << "1. Tambah lapangan" << endl;
                                cout << "2. Lihat lapangan" << endl;
                                cout << "3. Ubah lapangan" << endl;
                                cout << "4. Hapus lapangan" << endl;
                                cout << "5. Exit" << endl;
                                cout << "============================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1: {
                                        if (jumlahLapangan < MAX_LAPANGAN) {
                                            cout << "Masukkan ID lapangan: ";
                                            cin >> daftarLapangan[jumlahLapangan].id;
                                            cout << "Masukkan harga sewa lapangan: ";
                                            cin >> daftarLapangan[jumlahLapangan].harga;
                                            cout << "Masukkan lokasi lapangan: ";
                                            cin >> daftarLapangan[jumlahLapangan].lokasi;
                                            cout << "Masukkan status ketersediaan lapangan: ";
                                            cin >> daftarLapangan[jumlahLapangan].status;
                                            cout << "Tambah Lapangan Berhasil !!" << endl;
                                            jumlahLapangan++;
                                        } else {
                                            cout << "Lapangan sudah penuh!" << endl;
                                        }
                                        break;
                                    }
                                    case 2: {
                                        if (jumlahLapangan == 0) {
                                            cout << "Lapangan masih kosong!" << endl;
                                        } else {
                                            cout << "\n=== DAFTAR LAPANGAN FUTSAL ===" << endl;
                                            cout << "+" << setw(10) << "ID" 
                                            << setw(15) << "Harga" 
                                            << setw(20) << "Lokasi" 
                                            << setw(15) << "Status" << endl;
                                            for (int i = 0; i < jumlahLapangan; i++) {
                                                cout << "+" 
                                                << setw(10) << daftarLapangan[i].id 
                                                << setw(15) << daftarLapangan[i].harga 
                                                << setw(20) << daftarLapangan[i].lokasi 
                                                << setw(15) << daftarLapangan[i].status << endl;
                                            }
                                        }
                                        break;
                                    }
                                    case 3: {
                                        cout << "Masukkan ID lapangan yang ingin diubah: ";
                                        string idLapangan;
                                        cin >> idLapangan;
                                        bool found = false;
                                        for (int i = 0; i < jumlahLapangan; i++) {
                                            if (daftarLapangan[i].id == idLapangan) {
                                                cout << "Masukkan harga baru: ";
                                                cin >> daftarLapangan[i].harga;
                                                cout << "Masukkan lokasi baru: ";
                                                cin >> daftarLapangan[i].lokasi;
                                                cout << "Masukkan status baru: ";
                                                cin >> daftarLapangan[i].status;
                                                cout << "Ubah Lapangan Berhasil !!" << endl;
                                                found = true;
                                                break;
                                            }
                                        }
                                        if (!found) {
                                            cout << "ID lapangan tidak ditemukan!" << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        cout << "Masukkan ID lapangan yang ingin dihapus: ";
                                        string idLapangan;
                                        cin >> idLapangan;
                                        bool found = false;
                                        for (int i = 0; i < jumlahLapangan; i++) {
                                            if (daftarLapangan[i].id == idLapangan) {
                                                for (int j = i; j < jumlahLapangan - 1; j++) {
                                                    daftarLapangan[j] = daftarLapangan[j + 1];
                                                }
                                                jumlahLapangan--;
                                                cout << "Hapus Lapangan Berhasil !!" << endl;
                                                found = true;
                                                break;
                                            }
                                        }
                                        if (!found) {
                                            cout << "ID lapangan tidak ditemukan!" << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        cout << "Keluar dari menu admin." << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Pilihan tidak valid!" << endl;
                                    }
                                }
                            } while (pilihanMenu != 5);
                        } else if (peranPengguna == "member") {
                            int pilihanMenu;
                            do {
                                cout << "\n============================" << endl;
                                cout << "Menu Pengguna" << endl;
                                cout << "1. Lihat lapangan" << endl;
                                cout << "2. Exit" << endl;
                                cout << "============================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1: {
                                        if (jumlahLapangan == 0) {
                                            cout << "Lapangan masih kosong!" << endl;
                                        } else {
                                            cout << "\n=== DAFTAR LAPANGAN FUTSAL ===" << endl;
                                            cout << "+" << setw(10) << "ID" 
                                            << setw(15) << "Harga" 
                                            << setw(20) << "Lokasi" 
                                            << setw(15) << "Status" << endl;
                                            for (int i = 0; i < jumlahLapangan; i++) {
                                                cout << "+" 
                                                << setw(10) << daftarLapangan[i].id 
                                                << setw(15) << daftarLapangan[i].harga 
                                                << setw(20) << daftarLapangan[i].lokasi 
                                                << setw(15) << daftarLapangan[i].status << endl;
                                            }
                                        }
                                        break;
                                    }
                                    case 2: {
                                        cout << "Keluar dari menu pengguna." << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Pilihan tidak valid!" << endl;
                                    }
                                }
                            } while (pilihanMenu != 2);
                        }
                        break;
                    } else {
                        kesempatanLogin--;
                        cout << "Login gagal! Kesempatan tersisa: " << kesempatanLogin << endl;
                    }
                }
                if (!loginBerhasil) {
                    cout << "Anda telah mencapai batas maksimum percobaan login." << endl;
                }
                return 0;
            }
            case 3: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid!" << endl;
            }
        }
    } while (pilihanMenuUtama != 3);
    return 0;
}