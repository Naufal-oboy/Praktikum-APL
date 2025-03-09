#include <iostream>
using namespace std;

int valid_PIN = 6049;
int PIN;
int kesempatan = 3;
int ATM;
double tabungan = 0; 
double setortunai;
double tariktunai;

int main() {
    cout << "     LOGIN      " << endl;
    cout << "================" << endl;

    
    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        cin >> PIN;

        if (PIN == valid_PIN) {
            cout << "PIN yang Anda masukkan benar." << endl;
            cout << "Selamat, Anda berhasil login." << endl;
            break; 
        } else {
            kesempatan--;
            cout << "PIN yang Anda masukkan salah." << endl;
            if (kesempatan > 0) {
                cout << "Anda masih memiliki " << kesempatan << " kesempatan." << endl;
            } else {
                cout << "Anda telah mencoba 3 kali, silakan coba lagi." << endl;
                return 0; 
            }
        }
    }

    
    do {
        cout << "     MENU ATM     " << endl;
        cout << " ================ " << endl;
        cout << " 1. Setor Tunai " << endl;
        cout << " 2. Cek Saldo " << endl;
        cout << " 3. Tarik Tunai " << endl;
        cout << " 4. Keluar " << endl;
        cout << "Pilih menu: ";
        cin >> ATM;

        if (ATM == 1) {
            
            cout << "Masukkan jumlah saldo yang ingin disetor: ";
            cin >> setortunai;
            tabungan += setortunai; 
            cout << "Anda telah menyetor: Rp " << setortunai << endl;
        } else if (ATM == 2) {
            cout << "Saldo Anda: Rp " << tabungan << endl; 
        } else if (ATM == 3) {
            
            cout << "Masukkan jumlah yang ingin ditarik: ";
            cin >> tariktunai;
            if (tariktunai > tabungan) {
                cout << "Saldo tidak cukup!" << endl;
            } else {
                tabungan -= tariktunai; 
                cout << "Anda telah menarik: Rp " << tariktunai << endl;
                cout << "Sisa saldo Anda: Rp " << tabungan << endl;
            }
        } else if (ATM == 4) {
            cout << "Terima kasih sudah menggunakan ATM ini. Semoga hari Anda menyenangkan!" << endl;
        } else {
            cout << "Pilihan tidak ditemukan. Harap masukkan dengan benar." << endl;
        }
    } while (ATM != 4); 

    return 0;
}