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

void registrasiPengguna(Pengguna* daftarPengguna, int* dataUser) {
    if (*dataUser < MAX_USER) {
        cout << "Masukkan Nama: ";
        cin >> daftarPengguna[*dataUser].nama;
        cout << "Masukkan NIM: ";
        cin >> daftarPengguna[*dataUser].nim;
        cout << "Masukkan Peran (admin/member): ";
        cin >> daftarPengguna[*dataUser].peran;

        cout << "Masukkan Alamat: ";
        cin.ignore();
        getline(cin, daftarPengguna[*dataUser].kontak.alamat);

        cout << "Masukkan Nomor Telepon: ";
        cin >> daftarPengguna[*dataUser].kontak.telepon;

        (*dataUser)++;
        cout << "Registrasi berhasil!" << endl;
    } else {
        cout << "Jumlah pengguna sudah mencapai batas maksimum!" << endl;
    }
}

void loginPengguna(Pengguna* daftarPengguna, int dataUser, string* peranPengguna, bool* loginBerhasil) {
    string nama, nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;

    *loginBerhasil = false;
    for (int i = 0; i < dataUser; i++) {
        if (daftarPengguna[i].nama == nama && daftarPengguna[i].nim == nim) {
            cout << "Login berhasil! Peran Anda: " << daftarPengguna[i].peran << endl;
            *peranPengguna = daftarPengguna[i].peran;
            *loginBerhasil = true;
            return;
        }
    }
    cout << "Nama atau NIM tidak ditemukan!" << endl;
}

void tambahLapangan(Lapangan* daftarLapangan, int* jumlahLapangan) {
    if (*jumlahLapangan < MAX_LAPANGAN) {
        cout << "Masukkan ID lapangan: ";
        cin >> daftarLapangan[*jumlahLapangan].id;

        cout << "Masukkan harga sewa lapangan: ";
        cin >> daftarLapangan[*jumlahLapangan].harga;

        cout << "Masukkan lokasi lapangan: ";
        cin.ignore();
        getline(cin, daftarLapangan[*jumlahLapangan].lokasi);

        cout << "Masukkan status ketersediaan lapangan: ";
        cin >> daftarLapangan[*jumlahLapangan].status;

        cout << "Tambah Lapangan Berhasil !!" << endl;
        (*jumlahLapangan)++;
    } else {
        cout << "Lapangan sudah penuh!" << endl;
    }
}

void lihatLapangan(Lapangan* daftarLapangan, int jumlahLapangan) {
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
}

void ubahLapangan(Lapangan* daftarLapangan, int jumlahLapangan) {
    cout << "Masukkan ID lapangan yang ingin diubah: ";
    string idLapangan;
    cin >> idLapangan;
    bool found = false;
    for (int i = 0; i < jumlahLapangan; i++) {
        if (daftarLapangan[i].id == idLapangan) {
            cout << "Masukkan harga baru: ";
            cin >> daftarLapangan[i].harga;
            cout << "Masukkan lokasi baru: ";
            cin.ignore();
            getline(cin, daftarLapangan[i].lokasi);
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
}

void hapusLapangan(Lapangan* daftarLapangan, int* jumlahLapangan) {
    cout << "Masukkan ID lapangan yang ingin dihapus: ";
    string idLapangan;
    cin >> idLapangan;
    bool found = false;
    for (int i = 0; i < *jumlahLapangan; i++) {
        if (daftarLapangan[i].id == idLapangan) {
            for (int j = i; j < *jumlahLapangan - 1; j++) {
                daftarLapangan[j] = daftarLapangan[j + 1];
            }
            (*jumlahLapangan)--;
            cout << "Hapus Lapangan Berhasil !!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ID lapangan tidak ditemukan!" << endl;
    }
}

int main() {
    Pengguna daftarPengguna[MAX_USER];
    Lapangan daftarLapangan[MAX_LAPANGAN];
    int dataUser = 0;
    int jumlahLapangan = 0;
    string peranPengguna;
    bool loginBerhasil = false;
    int kesempatanLogin = 3;

    daftarPengguna[dataUser].nama = "Naufal";
    daftarPengguna[dataUser].nim = "6049";
    daftarPengguna[dataUser].peran = "admin";
    daftarPengguna[dataUser].kontak.alamat = "Sempaja";
    daftarPengguna[dataUser].kontak.telepon = "083153058333";
    dataUser++;

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
            case 1:
                registrasiPengguna(daftarPengguna, &dataUser);
                break;
            case 2: {
                kesempatanLogin = 3;
                while (kesempatanLogin > 0) {
                    loginPengguna(daftarPengguna, dataUser, &peranPengguna, &loginBerhasil);
                    if (loginBerhasil) {
                        bool isLogout = false;
                        while (!isLogout) {
                            int pilihanMenu;
                            if (peranPengguna == "admin") {
                                cout << "\n===== Menu Admin =====" << endl;
                                cout << "1. Tambah lapangan" << endl;
                                cout << "2. Lihat lapangan" << endl;
                                cout << "3. Ubah lapangan" << endl;
                                cout << "4. Hapus lapangan" << endl;
                                cout << "5. Logout" << endl;
                                cout << "=======================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1: tambahLapangan(daftarLapangan, &jumlahLapangan); 
                                    break;
                                    case 2: lihatLapangan(daftarLapangan, jumlahLapangan); 
                                    break;
                                    case 3: ubahLapangan(daftarLapangan, jumlahLapangan); 
                                    break;
                                    case 4: hapusLapangan(daftarLapangan, &jumlahLapangan); 
                                    break;
                                    case 5: isLogout = true; cout << "Logout berhasil." << endl; 
                                    break;
                                    default: cout << "Pilihan tidak valid!" << endl;
                                }
                            } else if (peranPengguna == "member") {
                                cout << "\n===== Menu Member =====" << endl;
                                cout << "1. Lihat lapangan" << endl;
                                cout << "2. Logout" << endl;
                                cout << "=======================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1: lihatLapangan(daftarLapangan, jumlahLapangan); 
                                    break;
                                    case 2: isLogout = true; cout << "Logout berhasil." << endl; 
                                    break;
                                    default: cout << "Pilihan tidak valid!" << endl;
                                }
                            }
                        }
                        break;
                    } else {
                        kesempatanLogin--;
                        cout << "Login gagal! Kesempatan tersisa: " << kesempatanLogin << endl;
                        if (kesempatanLogin == 0) {
                            cout << "Anda telah mencapai batas maksimum percobaan login." << endl;
                            return 0;
                        }
                    }
                }
                break;
            }
            case 3:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihanMenuUtama != 3);
    return 0;
}
