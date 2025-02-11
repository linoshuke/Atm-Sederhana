#include <iostream>
#include <cstdlib>

using namespace std;

void header() {
    cout << "================================================\n"
         << "\t      ATM Sederhana\n"
         << "\t by: Yafi Widya Putra (34)\n"
         << "\t     Dede Ichsan R (16)\n"
         << "\t    M Khoirus Zaman (28)\n"
         << "================================================\n";
}

void footer() {
    cout << "================================================\n"
         << "       Terima Kasih atas kunjungan Anda\n"
         << "\tSilahkan cek kembali uang Anda\n"
         << "dan pastikan tidak ada barang yang tertinggal\n"
         << "================================================\n";
}

void menu() {
    cout << "1. Tarik Tunai\n"
         << "2. Setor Tunai\n"
         << "3. Cek Saldo\n"
         << "4. Ganti PIN\n"
         << "5. Keluar\n"
         << "6. Kembali ke Menu Utama\n";
}

int main() {
    int saldo_awal = 2000000;
    int pin_benar = 1234; // PIN yang benar
    int pin_input, tarik, setor, pilihan, kembali;

    header();

    // Meminta PIN awal
    cout << "Silahkan masukkan pin Anda: ";
    cin >> pin_input;

    // Memeriksa PIN
    if (pin_input != pin_benar) {
        cout << "PIN salah. Akses ditolak.\n";
        return 0; // Keluar dari program jika PIN salah
    }

    do {
        menu();
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:  // Tarik Tunai
                cout << "Jumlah uang yang ingin Anda ambil: ";
                cin >> tarik;
                if (tarik % 50000 != 0 || tarik <= 0) {
                    cout << "Masukkan jumlah dalam kelipatan 50000.\n";
                } else if (tarik > saldo_awal) {
                    cout << "Saldo tidak cukup.\n";
                } else {
                    saldo_awal -= tarik;
                    cout << "Anda telah berhasil menarik Rp" << tarik << ".\n";
                    cout << "Saldo Anda sekarang adalah Rp" << saldo_awal << ".\n";
                }
                break;
            case 2:  // Setor Tunai
                cout << "Jumlah uang yang ingin Anda setor: ";
                cin >> setor;
                if (setor % 50000 != 0 || setor <= 0) {
                    cout << "Masukkan jumlah dalam kelipatan 50000.\n";
                } else {
                    saldo_awal += setor;
                    cout << "Anda telah berhasil menyimpan Rp" << setor << ".\n";
                    cout << "Saldo Anda sekarang adalah Rp" << saldo_awal << ".\n";
                }
                break;
            case 3:  // Cek Saldo
                cout << "Saldo Anda saat ini adalah Rp" << saldo_awal << ".\n";
                break;
            case 4:  // Ganti PIN
                int pin_baru;
                cout << "Masukkan PIN baru: ";
                cin >> pin_baru;
                pin_benar = pin_baru; // Mengubah PIN
                cout << "PIN berhasil diubah.\n";
                break;
            case 5:  // Keluar
                footer();
                return 0;
            case 6:  // Kembali ke Menu Utama
                // Meminta PIN lagi
                cout << "Silahkan masukkan pin Anda: ";
                cin >> pin_input;

                // Memeriksa PIN
                if (pin_input != pin_benar) {
                    cout << "PIN salah. Akses ditolak.\n";
                    return 0; // Keluar dari program jika PIN salah
                }
                continue; // Kembali ke menu utama
        }

        cout << "\nApakah Anda ingin melakukan transaksi lain?\n1. Ya\n2. Tidak\n";
        cout << "Pilih opsi: ";
        cin >> kembali;
        if (kembali == 2) {
            footer();
            return 0;
        }

        system("cls");
        header();
    } while (true);  // Selalu kembali ke menu sampai pengguna memilih untuk keluar

    return 0;
}