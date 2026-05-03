// kelompok 9 : 123250037, 123250042, 123250043

#include <iostream>
#include <string>
using namespace std;

struct DataAnggota {
    long noAnggota;
    string namaAnggota;
    string alamat;
};

const int MAX_DATA = 100;
DataAnggota listAnggota[MAX_DATA];
int jumlah = 0;

void inputData() {
    cout << "==================================" << endl;
    cout << "Jumlah data yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "==================================" << endl;
        cout << "Data ke-" << (i + 1) << endl;
        cout << "  No. Anggota  : ";
        cin >> listAnggota[i].noAnggota;
        cin.ignore();
        cout << "  Nama Anggota : ";
        getline(cin, listAnggota[i].namaAnggota);
        cout << "  Alamat       : ";
        getline(cin, listAnggota[i].alamat);
    }
    cout << "==================================" << endl;
    cout << "Data berhasil diinput!" << endl;
}

void tampilData() {
    cout << "==================================" << endl;
    if (jumlah == 0) {
        cout << "data belum diinput" << endl;
        return;
    }
    cout << "  NO. ANGGOTA\tNAMA ANGGOTA\t\tALAMAT" << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "  " << listAnggota[i].noAnggota
             << "\t" << listAnggota[i].namaAnggota
             << "\t" << listAnggota[i].alamat << endl;
    }
    cout << "==================================" << endl;
}

void shellSort() {
    int i, j, k;

    for (i = jumlah / 2; i > 0; i = i / 2) {
        for (j = i; j < jumlah; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (listAnggota[k + i].noAnggota < listAnggota[k].noAnggota) {
                    swap(listAnggota[k], listAnggota[k + i]);
                }
            }
        }
    }

    cout << "Data Setelah Shell Sort:" << endl;
}

void menuSorting(){
    int pilih;
    cout << "MENU :" << endl;
    cout << "==========================" << endl;
    cout << "1. BUBBLE SORT" << endl;
    cout << "2. SELECTION SORT" << endl;
    cout << "3. INSERTION SORT" << endl;
    cout << "4. SHELL SORT" << endl;
    cout << "5. QUICK SORT" << endl;
    cout << "6. MERGE SORT" << endl;
    cout << "7. EXIT" << endl;
    cout << "==========================" << endl;
    cout << "Pilih : "; cin >> pilih;

    switch (pilih){
        case 1: cout <<"ajjasakj";
        case 2: cout <<"ahsdakjdha";
        case 3: cout <<"ajdhskd";
        case 4: shellSort(); break;
        
        default:
            break;
    }

    tampilData();
    
}

void menuSearching(){
    cout << "MENU :" << endl;
        cout << "==========================" << endl;
        cout << "1. SEQUENTIAL SEARCH" << endl;
        cout << "2. BINARY SEARCH" << endl;
        cout << "3. EXIT" << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
}

int main() {
    int pilih;
    char kembali;

    do {
        cout << "MENU :" << endl;
        cout << "==========================" << endl;
        cout << "1. INPUT DATA" << endl;
        cout << "2. TAMPIL DATA" << endl;
        cout << "3. SEARCHING" << endl;
        cout << "4. SORTING" << endl;
        cout << "5. EXIT" << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 5) {
            cout << "Keluar dari program..." << endl;
            return 0;
        }

        switch (pilih) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: menuSearching(); break;
            case 4: menuSorting(); break;
            default: cout << "Pilihan menu tidak ada..." << endl;
        }

        cout << "Kembali ke Menu Utama(y/t)? ";
        cin >> kembali;

    } while (kembali == 'y' || kembali == 'Y');

    cout << "Keluar dari program..." << endl;
    return 0;
}
