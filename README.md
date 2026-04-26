## Project Algoritma Lanjut Kelompok 9

Baca

### 1. Setup

**Requirements**

```
- git
- gcc
- vscode
```

**Clone repo and open vscode**

Buka terminal (powershell, cmd, tersrah)

```sh
git clone https://github.com/abcdavk/ecpts-algo-lanjut
cd ecpts-algo-lanjut
code .
```

### 2. Add remote and push

Pilih salah satu cara

#### a. Cara Normal

```sh
git remote add origin https://github.com/abcdavk/ecpts-algo-lanjut
git branch -M main
git add .
git commit -m ""
git push -u origin main

```

#### b. Cara SSH

```sh
git remote add origin git@github.com:abcdavk/ecpts-algo-lanjut.git
git add .
git commit -m ""
git push -u origin main
```

### Aturan penulisan

Demi kenyamanan bersama dan biar kodenya rapi, usahain nulis variabel pake ini ya cuy:

- **Variabel dan fungsi**: `camelCase`
- **Struct**: `PascalCase`
- **Constant**: `UPPER_CASE`

contoh:

```cpp
int namaMahasiswa = "Rusdi";

void hitungPerkalian() {}

struct MahasiswaInformatik {
    string nama;
    int NIM;
};

const int PI = 3.14;
```
