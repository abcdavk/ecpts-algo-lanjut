// kelompok 9 : 123250037, 123250042, 123250043

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

/**
 * @note sesuaikan parameter `*__command`
 * dengan command di OS mu agar tidak error.
 */
#define CLEAR_SCREEN system("clear")

using namespace std;
namespace fs = filesystem;

const int MAX_DATA = 100;
struct DataAnggota {
    long noAnggota;
    char namaAnggota[50];
    char alamat[50];
};

DataAnggota listAnggota[MAX_DATA];
DataAnggota listAnggotaSorted[MAX_DATA];
DataAnggota eBox[MAX_DATA];

string fileLoaded;
string listFile[MAX_DATA];
string fileListName = "data/filelist.txt";

int jumlah = 0;
int jumlahFile = 0;

/**
 * Memuat data dari `filelist.txt` ke dalam
 * array `listFile`
 */
void loadListFile() {
    ifstream file(fileListName);

    if (file) {
        file >> jumlahFile;

        file.ignore();

        for (int i = 0; i < jumlahFile; i++) {
            getline(file, listFile[i]);
        }
    
        file.close();
    }
}

/**
 * Menambah data listFile lalu
 * menyimpannya ke `filelist.txt`
 */
void addListFile(string fileName) {
    fs::create_directories("data");
    ofstream file(fileListName);;

    listFile[jumlahFile] = fileName;
    jumlahFile++;

    file << jumlahFile << "\n";

    for (int i = 0; i < jumlahFile; i++) {
        file << listFile[i] << "\n";
    }
    file.close();
}

/**
 * Menulis data ke file binary
 * 
 * @note `fs::create_directory` berfungsi untuk membuat 
 * directory dimana file akan disimpan. 
 * 
 * @param fileName nama file untuk menyimpan data
 * @param array array tujuan
 * @param jumlahData jumlah data dari array
 */
void writeBinaryFile(string fileName, DataAnggota array[], int &jumlahData) {
    fs::create_directory("data");
    ofstream file("data/" + fileName + ".bin", ios::binary);

    addListFile(fileName);
    
    if (file.is_open()) {
        file.write(
            reinterpret_cast<char*>(&jumlahData), 
            sizeof(jumlahData)
        );

        file.write(
            reinterpret_cast<char*>(array), 
            sizeof(DataAnggota) * jumlahData
        );
        file.close();
    }
}

/**
 * Membaca data dari file binary
 * 
 * @param fileName nama file
 * @param array array tujuan
 * @param jumlahData jumlah data dari array
 */
void readBinaryFile(
    string fileName,
    DataAnggota array[],
    int &jumlahData
) {
    ifstream file("data/" + fileName + ".bin", ios::binary);

    if (file.is_open()) {

        // baca jumlah data
        file.read(
            reinterpret_cast<char*>(&jumlahData),
            sizeof(jumlahData)
        );

        // baca seluruh isi array
        file.read(
            reinterpret_cast<char*>(array),
            sizeof(DataAnggota) * jumlahData
        );

        file.close();
    }
}

void inputData() {
    CLEAR_SCREEN;

    string fileName;
    cout << "Input nama file: "; cin >> fileName;
    
    cout << "===========================" << endl;
    cout << "Jumlah data yang ingin diinput: ";
    cin >> jumlah;
    
    
    for (int i = 0; i < jumlah; i++) {
        cout << "===========================" << endl;
        cout << "Data ke-" << (i + 1) << endl;
        cout << "  No. Anggota  : ";
        cin >> listAnggota[i].noAnggota;
        cin.ignore();
        cout << "  Nama Anggota : ";
        cin.getline(listAnggota[i].namaAnggota, 50);
        
        cout << "  Alamat       : ";
        cin.getline(listAnggota[i].alamat, 50);
    }

    writeBinaryFile(fileName, listAnggota, jumlah);
    cout << "===========================" << endl;
    cout << "Data berhasil diinput!" << endl;

    fileLoaded = fileName+".bin";
}

/**
 * Tampilkan semua data
 * @param array[] array yang ingin di gunakan
 */
void tampilData(DataAnggota array[]) {
    CLEAR_SCREEN;
    int pilih;

    if (jumlah == 0) {
        cout << "===========================" << endl;
        cout << "data belum diinput" << endl;
        return;
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
    CLEAR_SCREEN;
    cout << "\nData di temukan" << endl;
    cout << "===========================" << endl;
    cout << " No. Anggota  : " << array[i].noAnggota << endl;
    cout << " Nama Anggota : " << array[i].namaAnggota << endl;
    cout << " Alamat       : " << array[i].alamat << endl;
    cout << "===========================" << endl;
}

void pilihFile() {
    CLEAR_SCREEN;
    int pilih;

    cout << "Pilih File" << endl;

    for (int i = 0; i < jumlahFile; i++) 
        cout << i+1 << ". " << listFile[i] << endl;
    
    cout << "===========================" << endl;
    cout << "Pilih: "; cin >> pilih;
    
    if (pilih > jumlahFile || pilih <= 0) {
        cout << "Pilihan tidak ada\n";
        return;
    }

    fileLoaded = listFile[pilih-1]+".bin";
    readBinaryFile(listFile[pilih-1], listAnggota, jumlah);
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
        CLEAR_SCREEN;
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
        CLEAR_SCREEN;
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

void mergeFileUrut() {
    
}

// Menus
void operasiFileMergeUrut() {
    CLEAR_SCREEN;
    int jumlahMerge;
    int pilih[MAX_DATA];
    cout << "Pilih file: " << endl;
    
    for (int i = 0; i < jumlahFile; i++) 
        cout << i+1 << ". " << listFile[i] << endl;
    
    cout << "==========================" << endl;
    
    cout << "Jumlah file yang ingin di merge: "; cin >> jumlahMerge;

    if (jumlahMerge <= 1 || jumlahMerge > jumlahFile) {
        cout << "Jumlah file tidak valid." << endl;
    }

    for (int i = 0; i < jumlahMerge; i++) {
        cout << "Pilih file-" << i+1 << ": "; cin >> pilih[i];
    }
    
    DataAnggota hasilMerge[MAX_DATA];
    int jumlahHasil = 0;

    for (int i = 0; i < jumlahMerge; i++)
    {
        DataAnggota temp[MAX_DATA];
        int jumlahTemp;

        readBinaryFile(listFile[pilih[i]-1], temp, jumlahTemp);

        for (int j = 0; j < jumlahTemp; j++)
        {
            hasilMerge[jumlahHasil] = temp[j];
            jumlahHasil++;
        }        
    }

    string hasilFileName;
    cout << "\nNama file untuk menyimpan hasil merge: "; cin >> hasilFileName;
    
    writeBinaryFile(hasilFileName, hasilMerge, jumlahHasil);
    
    for (int i = 0; i < jumlah; i++) {
        cout << "===========================" << endl;
        cout << " No. Anggota  : " << hasilMerge[i].noAnggota << endl;
        cout << " Nama Anggota : " << hasilMerge[i].namaAnggota << endl;
        cout << " Alamat       : " << hasilMerge[i].alamat << endl;
        cout << "===========================" << endl << endl;
    }    
}

void menuSorting(){
    CLEAR_SCREEN;
    
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
    CLEAR_SCREEN;
    
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
    
    loadListFile();

    do {
        CLEAR_SCREEN;

        cout << "==========================" << endl;
        cout << "           MENU           " << endl;
        cout << "==========================" << endl;
        cout << " 0. PILIH FILE            " << endl;
        cout << " 1. INPUT DATA            " << endl;
        cout << " 2. TAMPIL DATA           " << endl;
        cout << " 3. SEARCHING             " << endl;
        cout << " 4. SORTING               " << endl;
        cout << " 5. FILE: MERGING URUT    " << endl;
        cout << " 6. EXIT                  " << endl;
        cout << "==========================" << endl;
        cout << "File di-load: " << fileLoaded << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 6) {
            cout << "Keluar dari program..." << endl;
            return 0;
        }

        switch (pilih) {
            case 0: pilihFile(); break;
            case 1: inputData(); break;
            case 2: tampilData(listAnggota); break;
            case 3: menuSearching(); break;
            case 4: menuSorting(); break;
            case 5: operasiFileMergeUrut(); break;
            default: cout << "Pilihan menu tidak ada..." << endl;
        }

        cout << "Kembali ke Menu Utama(y/t)? ";
        cin >> kembali;

    } while (kembali == 'y' || kembali == 'Y');

    cout << "Keluar dari program..." << endl;
    return 0;
}
