// kelompok 9 : 123250037, 123250042, 123250043

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct DataAnggota {
    long noAnggota;
    string namaAnggota;
    string alamat;
};

const int MAX_DATA = 100;
DataAnggota listAnggota[MAX_DATA];
DataAnggota listAnggotaSorted[MAX_DATA];
DataAnggota eBox[MAX_DATA];
string listFile[MAX_DATA];
ofstream myFile();
ofstream file();
int jumlah = 0;
int jumFile = 0;

void createFile(string namaFile){
    ofstream file("dataFile.txt");
    file << namaFile << endl;
}

void inputData() {
    string namaFile;
    system("cls");
    cout << "Nama file(.txt) : "; cin >> namaFile;
    ofstream myFile(namaFile);
    listFile[jumFile] = namaFile;
    cout << "===========================" << endl;
    cout << "Jumlah data yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "===========================" << endl;
        cout << "Data ke-" << (i + 1) << endl;
        cout << "  No. Anggota  : ";
        cin >> listAnggota[i].noAnggota;
        cin.ignore();
        myFile << listAnggota[i].namaAnggota << ", ";
        cout << "  Nama Anggota : ";
        getline(cin, listAnggota[i].namaAnggota);
        myFile << listAnggota[i].namaAnggota << ", ";
        cout << "  Alamat       : ";
        getline(cin, listAnggota[i].alamat);
        myFile << listAnggota[i].alamat << "/\n";
    }
    cout << "===========================" << endl;
    cout << namaFile << "complate\n";
    cout << "Data berhasil diinput!" << endl;
    jumFile++;
}

/**
 * Tampilkan semua data
 * @param array[] array yang ingin di gunakan
 */
void tampilData(DataAnggota array[]) {
    int pilih;
    string myText, text;
    system("cls");
    /*if (jumFile == 0){
        cout << "===========================" << endl;
        cout << "data belum diinput" << endl;
        return;
    }*/

    ifstream file("dataFile.txt");
    cout << "List-File: \n";
    for(int f = 0;f < jumFile;f++){
        cout << f+1 << ". " << listFile[f] << endl;
    }

    cout << "Pilih : "; cin >> pilih;
    ifstream myReadFile(listFile[pilih]);
    while(getline (myReadFile, myText)){
        cout << myText << endl;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "===========================" << endl;
        cout << " No. Anggota  : " << array[i].noAnggota << endl;
        cout << " Nama Anggota : " << array[i].namaAnggota << endl;
        cout << " Alamat       : " << array[i].alamat << endl;
        cout << "===========================" << endl << endl;
    }
}

/**
 * Tampilkan isi data berdasarkan index
 * @param i index yang ingin di tampilkan
 * @param array[] array yang ingin di gunakan
 */
void tampilDataById(int i, DataAnggota array[]) {
    system("cls");
    cout << "\nData di temukan" << endl;
    cout << "===========================" << endl;
    cout << " No. Anggota  : " << array[i].noAnggota << endl;
    cout << " Nama Anggota : " << array[i].namaAnggota << endl;
    cout << " Alamat       : " << array[i].alamat << endl;
    cout << "===========================" << endl;
}

/**
 * copy array listAnggota ke listAnggotaSorted
 * supaya data utama tidak ter-sort
 */
void copyData() {
    for (int i = 0; i < jumlah; i++) {
        listAnggotaSorted[i] = listAnggota[i];
    }
}

// Searching
void sequentialSearch() {
    char ulangi = 't';
    int noAnggota;

    if (jumlah == 0) {
        cout << "===========================" << endl;
        cout << "data belum diinput" << endl;
        return;
    }
    
    do {
        system("cls");
        int i = 0;
        cout << "\n\n";
        cout << "==========================" << endl;
        cout << "     SEQUENTIAL SEARCH    " << endl;
        cout << "==========================" << endl;
        cout << "\nNo Anggota yang dicari : ";
        cin >> noAnggota;

        while (i < jumlah && listAnggota[i].noAnggota != noAnggota)
        {
            i++;
        }
        if (i == jumlah)
            cout << "\nData tidak ditemukan" << endl;
        else
            tampilDataById(i, listAnggota);
        
        cout << "Ulangi? (y/t) : ";
        cin >> ulangi;

    } while (ulangi == 'y' || ulangi == 'Y');
}

void bubbleSort();
void binarySearch() {
    char ulangi = 't';
    int noAnggota, low, high, mid;

    if (jumlah == 0) {
        cout << "===========================" << endl;
        cout << "data belum diinput" << endl;
        return;
    }
    
    bubbleSort();
    
    do {
        system("cls");
        cout << "\n\n";
        cout << "==========================" << endl;
        cout << "       BINARY SEARCH      " << endl;
        cout << "==========================" << endl;
        cout << "\nNo Anggota yang dicari : ";
        cin >> noAnggota;

        low = 0;
        high = jumlah - 1;
        bool ditemukan = false;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (noAnggota == listAnggotaSorted[mid].noAnggota) {
                ditemukan = true;
                break;
            }
            else if (noAnggota > listAnggotaSorted[mid].noAnggota) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (ditemukan) {
            tampilDataById(mid, listAnggotaSorted);
        } else {
            cout << "\nData tidak ditemukan" << endl;
        }
        
        cout << "Ulangi? (y/t) : ";
        cin >> ulangi;

    } while (ulangi == 'y' || ulangi == 'Y');
}


// Sorting
void bubbleSort() {
    int i, j;

    copyData();

    // sorting process
    for (i = 0; i < jumlah - 1; i++) {
        for (j = 0; j < jumlah - 1 - i; j++) {
            if (listAnggotaSorted[j].noAnggota > listAnggotaSorted[j+1].noAnggota) {
                swap(listAnggotaSorted[j], listAnggotaSorted[j+1]);
            }
        }
    }
}

// Bubble sort nya dua, yang atas buat sorting sebelum binary search
void bubbleSortDisplay() {
    bubbleSort();
    tampilData(listAnggotaSorted);
}

void selectionSort() {
    int i, j;

    copyData();

    for (i = 0; i < jumlah -1; i++)
    {
        int minIndex = i;
        for (j = i+1; j < jumlah; j++)
        {
            if (listAnggotaSorted[j].noAnggota < listAnggotaSorted[minIndex].noAnggota) {
                minIndex = j;
            }
        }
        
        swap(listAnggotaSorted[i], listAnggotaSorted[minIndex]);
    }

    tampilData(listAnggotaSorted);
}

void insertionShort(){
    int i, j;

    copyData();

    for(i = 1; i < jumlah; i++){
        eBox[i] = listAnggotaSorted[i];
        j = i - 1;
        while ((j >= 0) && (listAnggotaSorted[j].noAnggota > eBox[i].noAnggota)){
            listAnggotaSorted[j+1] = listAnggotaSorted[j];
            j--;
        }
        listAnggotaSorted[j+1] = eBox[i];
    }
    tampilData(listAnggotaSorted);
};

void shellSort() {
    int i, j, k;

    copyData();

    for (i = jumlah / 2; i > 0; i = i / 2) {
        for (j = i; j < jumlah; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (listAnggotaSorted[k + i].noAnggota < listAnggotaSorted[k].noAnggota) {
                    swap(listAnggotaSorted[k], listAnggotaSorted[k + i]);
                }
            }
        }
    }

    cout << "Data Setelah Shell Sort:" << endl;
    tampilData(listAnggotaSorted);
}

int partition(int low, int high){
    int pivot = listAnggotaSorted[high].noAnggota;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(listAnggotaSorted[j].noAnggota <= pivot){
            i++;
            swap(listAnggotaSorted[i], listAnggotaSorted[j]);
        }
    }

    swap(listAnggotaSorted[i + 1], listAnggotaSorted[high]);
    return i + 1;
}

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void quickSortDisplay() {
    copyData();
    quickSort(0, jumlah - 1);
    tampilData(listAnggotaSorted);
}

void merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right){
        if(listAnggotaSorted[i].noAnggota < listAnggotaSorted[j].noAnggota){
            eBox[k] = listAnggotaSorted[i]; 
            i++;
        } else {
            eBox[k] = listAnggotaSorted[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        eBox[k] = listAnggotaSorted[i];
        i++; 
        k++;
    }
    
    while(j <= right){
        eBox[k] = listAnggotaSorted[j];
        j++; 
        k++;
    }
    
    for(int x = left; x <= right; x++){
        listAnggotaSorted[x] = eBox[x];
    }
}

void mergeSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void mergeSortDisplay(){
    copyData();
    mergeSort(0, jumlah - 1);
    tampilData(listAnggotaSorted);
}

// Menus
void menuSorting(){
    system("cls");
    
    int pilih;
    
    cout << "==========================" << endl;
    cout << "PILIH ALGORITMA SORTING   " << endl;
    cout << "==========================" << endl;
    cout << " 1. BUBBLE SORT           " << endl;
    cout << " 2. SELECTION SORT        " << endl;
    cout << " 3. INSERTION SORT        " << endl;
    cout << " 4. SHELL SORT            " << endl;
    cout << " 5. QUICK SORT            " << endl;
    cout << " 6. MERGE SORT            " << endl;
    cout << " 7. EXIT                  " << endl;
    cout << "==========================" << endl;
    cout << "Pilih : "; cin >> pilih;

    switch (pilih){
        case 1: bubbleSortDisplay(); break;
        case 2: selectionSort(); break;
        case 3: insertionShort(); break;
        case 4: shellSort(); break;
        case 5: quickSortDisplay(); break;
        case 6: mergeSortDisplay(); break;
        
        default:
            break;
    }    
}

void menuSearching(){
    system("cls");
    
    int pilih;
    
    cout << "==========================" << endl;
    cout << "PILIH ALGORITMA SEARCHING " << endl;
    cout << "==========================" << endl;
    cout << " 1. SEQUENTIAL SEARCH     " << endl;
    cout << " 2. BINARY SEARCH         " << endl;
    cout << " 3. EXIT                  " << endl;
    cout << "==========================" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch (pilih)
    {
        case 1: sequentialSearch(); break;
        case 2: binarySearch(); break;
        case 3: break;
    
        default: cout << "Pilihan menu tidak ada..." << endl;
    }
}

int main() {
    
    int pilih;
    char kembali;
    
    do {
        system("cls");
        cout << "==========================" << endl;
        cout << "           MENU           " << endl;
        cout << "==========================" << endl;
        cout << " 1. INPUT DATA            " << endl;
        cout << " 2. TAMPIL DATA           " << endl;
        cout << " 3. SEARCHING             " << endl;
        cout << " 4. SORTING               " << endl;
        cout << " 5. OPERASI FILE          " << endl;
        cout << " 6. EXIT                  " << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 5) {
            cout << "Keluar dari program..." << endl;
            return 0;
        }

        switch (pilih) {
            case 1: inputData(); break;
            case 2: tampilData(listAnggota); break;
            case 3: menuSearching(); break;
            case 4: menuSorting(); break;
            case 5: break;
            default: cout << "Pilihan menu tidak ada..." << endl;
        }

        cout << "Kembali ke Menu Utama(y/t)? ";
        cin >> kembali;

    } while (kembali == 'y' || kembali == 'Y');

    cout << "Keluar dari program..." << endl;
    return 0;
}
