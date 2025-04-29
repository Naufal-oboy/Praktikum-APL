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
    int harga;     
    int lokasi;    
    string status;
};

void registrasiPengguna(Pengguna* daftarPengguna, int* dataUser) {
    if (*dataUser >= MAX_USER) {
        cout << "Maaf, kapasitas pengguna sudah penuh." << endl;
        return;
    }
    cout << "\n=== Registrasi Pengguna ===" << endl;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, daftarPengguna[*dataUser].nama);
    cout << "Masukkan NIM: ";
    getline(cin, daftarPengguna[*dataUser].nim);
    daftarPengguna[*dataUser].peran = "member";
    cout << "Masukkan Alamat: ";
    getline(cin, daftarPengguna[*dataUser].kontak.alamat);
    cout << "Masukkan No Telepon: ";
    getline(cin, daftarPengguna[*dataUser].kontak.telepon);
    cout << "Registrasi berhasil. Silakan login." << endl;
    (*dataUser)++;
}

void loginPengguna(Pengguna* daftarPengguna, int dataUser, string* peranPengguna, bool* loginBerhasil) {
    string nimLogin, namaLogin;
    cout << "\n=== Login Pengguna ===" << endl;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, namaLogin);
    cout << "Masukkan NIM: ";
    getline(cin, nimLogin);

    for (int i = 0; i < dataUser; i++) {
        if (daftarPengguna[i].nama == namaLogin && daftarPengguna[i].nim == nimLogin) {
            *peranPengguna = daftarPengguna[i].peran;
            *loginBerhasil = true;
            cout << "Login berhasil sebagai " << *peranPengguna << endl;
            return;
        }
    }
    *loginBerhasil = false;
    cout << "Login gagal. Nama atau NIM salah." << endl;
}

void tambahLapangan(Lapangan* daftarLapangan, int* jumlahLapangan) {
    if (*jumlahLapangan >= MAX_LAPANGAN) {
        cout << "Maaf, kapasitas data lapangan sudah penuh." << endl;
        return;
    }
    cout << "\n=== Tambah Data Lapangan ===" << endl;
    cout << "Masukkan ID Lapangan: ";
    cin >> daftarLapangan[*jumlahLapangan].id;
    cout << "Masukkan Harga Sewa (angka saja): ";
    cin >> daftarLapangan[*jumlahLapangan].harga;
    cout << "Masukkan Nomor Lantai (angka saja): ";
    cin >> daftarLapangan[*jumlahLapangan].lokasi;
    cout << "Masukkan Status Lapangan (Tersedia/Tidak Tersedia): ";
    cin.ignore();
    getline(cin, daftarLapangan[*jumlahLapangan].status);
    cout << "Data lapangan berhasil ditambahkan." << endl;
    (*jumlahLapangan)++;
}

void lihatLapangan(Lapangan* daftarLapangan, int jumlahLapangan) {
    cout << "\n=== Daftar Lapangan ===" << endl;
    if (jumlahLapangan == 0) {
        cout << "Belum ada data lapangan." << endl;
        return;
    }
    cout << left << setw(15) << "ID Lapangan" 
        << setw(10) << "Harga" 
        << setw(15) << "Lantai" 
        << setw(20) << "Status" << endl;
    for (int i = 0; i < jumlahLapangan; i++) {
        cout << left << setw(15) << daftarLapangan[i].id 
            << setw(10) << daftarLapangan[i].harga 
            << setw(15) << daftarLapangan[i].lokasi
            << setw(20) << daftarLapangan[i].status << endl;
    }
}

void ubahLapangan(Lapangan* daftarLapangan, int jumlahLapangan) {
    string idCari;
    bool ditemukan = false;
    cout << "\n=== Ubah Data Lapangan ===" << endl;
    cout << "Masukkan ID Lapangan yang ingin diubah: ";
    cin >> idCari;
    for (int i = 0; i < jumlahLapangan; i++) {
        if (daftarLapangan[i].id == idCari) {
            cout << "Masukkan Harga Sewa Baru: ";
            cin >> daftarLapangan[i].harga;
            cout << "Masukkan Nomor Lantai Baru (angka saja): ";
            cin >> daftarLapangan[i].lokasi;
            cout << "Masukkan Status Baru: ";
            cin.ignore();
            getline(cin, daftarLapangan[i].status);
            cout << "Data lapangan berhasil diubah." << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan ID tersebut tidak ditemukan." << endl;
    }
}

void hapusLapangan(Lapangan* daftarLapangan, int* jumlahLapangan) {
    string idCari;
    bool ditemukan = false;
    cout << "\n=== Hapus Data Lapangan ===" << endl;
    cout << "Masukkan ID Lapangan yang ingin dihapus: ";
    cin >> idCari;
    for (int i = 0; i < *jumlahLapangan; i++) {
        if (daftarLapangan[i].id == idCari) {
            for (int j = i; j < *jumlahLapangan - 1; j++) {
                daftarLapangan[j] = daftarLapangan[j + 1];
            }
            (*jumlahLapangan)--;
            cout << "Data lapangan berhasil dihapus." << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan ID tersebut tidak ditemukan." << endl;
    }
}

void bubbleSortLokasi(Lapangan* daftarLapangan, int jumlahLapangan) {
    for (int i = 0; i < jumlahLapangan - 1; i++) {
        for (int j = 0; j < jumlahLapangan - i - 1; j++) {
            if (daftarLapangan[j].lokasi > daftarLapangan[j + 1].lokasi) {
                swap(daftarLapangan[j], daftarLapangan[j + 1]);
            }
        }
    }
}

void selectionSortHarga(Lapangan* daftarLapangan, int jumlahLapangan) {
    for (int i = 0; i < jumlahLapangan - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < jumlahLapangan; j++) {
            if (daftarLapangan[j].harga > daftarLapangan[maxIdx].harga) {
                maxIdx = j;
            }
        }
        swap(daftarLapangan[i], daftarLapangan[maxIdx]);
    }
}

void insertionSortStatus(Lapangan* daftarLapangan, int jumlahLapangan) {
    for (int i = 1; i < jumlahLapangan; i++) {
        Lapangan key = daftarLapangan[i];
        int j = i - 1;
        while (j >= 0 && daftarLapangan[j].status > key.status) {
            daftarLapangan[j + 1] = daftarLapangan[j];
            j--;
        }
        daftarLapangan[j + 1] = key;
    }
}

void menuSorting(Lapangan* daftarLapangan, int jumlahLapangan) {
    int pilihanSort;
    cout << "\n=== Menu Sorting Lapangan ===" << endl;
    cout << "1. Urutkan berdasarkan Lantai " << endl;
    cout << "2. Urutkan berdasarkan Harga (Tertinggi ke Terendah)" << endl;
    cout << "3. Urutkan berdasarkan Status " << endl;
    cout << "Pilih metode sorting: ";
    cin >> pilihanSort;

    switch (pilihanSort) {
        case 1:
            bubbleSortLokasi(daftarLapangan, jumlahLapangan);
            cout << "Data diurutkan berdasarkan Lantai (1-N)." << endl;
            break;
        case 2:
            selectionSortHarga(daftarLapangan, jumlahLapangan);
            cout << "Data diurutkan berdasarkan Harga (Tertinggi ke Terendah)." << endl;
            break;
        case 3:
            insertionSortStatus(daftarLapangan, jumlahLapangan);
            cout << "Data diurutkan berdasarkan Status (A-Z)." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
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
                                cout << "5. Sorting Lapangan" << endl;
                                cout << "6. Logout" << endl;
                                cout << "=======================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1:
                                        tambahLapangan(daftarLapangan, &jumlahLapangan);
                                        break;
                                    case 2:
                                        lihatLapangan(daftarLapangan, jumlahLapangan);
                                        break;
                                    case 3:
                                        ubahLapangan(daftarLapangan, jumlahLapangan);
                                        break;
                                    case 4:
                                        hapusLapangan(daftarLapangan, &jumlahLapangan);
                                        break;
                                    case 5:
                                        menuSorting(daftarLapangan, jumlahLapangan);
                                        break;
                                    case 6:
                                        isLogout = true;
                                        cout << "Logout berhasil." << endl;
                                        break;
                                    default:
                                        cout << "Pilihan tidak valid!" << endl;
                                }
                            } else if (peranPengguna == "member") {
                                cout << "\n===== Menu Member =====" << endl;
                                cout << "1. Lihat lapangan" << endl;
                                cout << "2. Logout" << endl;
                                cout << "=======================" << endl;
                                cout << "Pilih menu: ";
                                cin >> pilihanMenu;
                                switch (pilihanMenu) {
                                    case 1:
                                        lihatLapangan(daftarLapangan, jumlahLapangan);
                                        break;
                                    case 2:
                                        isLogout = true;
                                        cout << "Logout berhasil." << endl;
                                        break;
                                    default:
                                        cout << "Pilihan tidak valid!" << endl;
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