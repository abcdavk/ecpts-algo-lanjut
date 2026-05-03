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

void sequentialSearch() {
    char ulangi = 't';
    int noAnggota;
    
    do {
        int i = 0;
        cout << "\n\n";
        cout << "SEQUENTIAL SEARCH" << endl;
        cout << "=================" << endl;
        cout << "\nNo Anggota yang dicari : ";
        cin >> noAnggota;

        while (listAnggota[i].noAnggota != noAnggota)
        {
            i++;
        }
        cout << "\n\nData di temukan" << endl;
        cout << "==================================" << endl;
        cout << " No. Anggota  : " << listAnggota[i].noAnggota << endl;
        cout << " Nama Anggota : " << listAnggota[i].namaAnggota << endl;
        cout << " Alamat       : " << listAnggota[i].alamat << endl;
        cout << "==================================" << endl;       

        cout << "Ulangi? (y/t) : ";

        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');
}

void inputData() {
    cout << "==================================" << endl;
    cout << "Jumlah data yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << " Nama Anggota : " << listAnggota[i].namaAnggota;
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
        cout << "Pilih : ";

        switch (pilih){
        case 1:
            break;
        
        default:
            break;
        }
        
}

void menuSearching(){
    int pilih;
    cout << "MENU :" << endl;
        cout << "==========================" << endl;
        cout << "1. SEQUENTIAL SEARCH" << endl;
        cout << "2. BINARY SEARCH" << endl;
        cout << "3. EXIT" << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
    cin >> pilih;
    switch (pilih)
    {
        case 1: sequentialSearch(); break;
    
        default: cout << "Pilihan menu tidak ada..." << endl;
    }
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
