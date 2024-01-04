#ifndef GUDANG_H_INCLUDED
#define GUDANG_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define first(L)(L.first)
#define info(p)(p->info)
#define next(p)p->next
#define hasRelation(p)(p->elmRelasi)
#define relationPemasok(p)p->infoPemasok
#define relationBarang(p)p->infoBarang

typedef struct elmPemasok *adrPemasok;
typedef struct elmBarang *adrBarang;
typedef struct elmRelasi *adrRelation;

struct Pemasok {
    int id;
    string nama;
    string alamat;
    int noTelp;
};

struct Barang {
    string idBarang;
    string jenis;
    int jumlah;
};

struct elmPemasok {
    Pemasok info;
    adrRelation elmRelasi;
    adrPemasok next;
};

struct elmBarang {
    Barang info;
    adrBarang next;
};

struct elmRelasi {
    adrPemasok infoPemasok;
    adrBarang infoBarang;
    adrRelation next;
};

struct listPemasok {
    adrPemasok first;
};

struct listBarang {
    adrBarang first;
};

void createlistPemasok(listPemasok &L);
void createlistBarang(listBarang &L);

adrPemasok alokasiPemasok(Pemasok p);
adrBarang alokasiBarang(Barang p);
adrRelation alokasiRelation(adrPemasok p1, adrBarang p2);

void insertFirstPemasok(listPemasok &L, adrPemasok p);
void insertLastPemasok(listPemasok &L, adrPemasok p);
void insertFirstBarang(listBarang &L, adrBarang p);
void insertLastBarang(listBarang &L, adrBarang p);

void deleteFirstPemasok(listPemasok &L, adrPemasok p);
void deleteLastPemasok(listPemasok &L, adrPemasok p);
void deleteAfterPemasok(listPemasok &L, adrPemasok &prec);
void deletePemasok(listPemasok &L, Pemasok p);

void deleteFirstBarang(listBarang &L, adrBarang p);
void deleteLastBarang(listBarang &L, adrBarang p);
void deleteAfterBarang(listBarang &L, adrBarang &prec);
void deleteBarang(listPemasok &L, listBarang &L2, Barang infoBarang);

adrPemasok cariPemasokByID(listPemasok P1, Pemasok p);
adrBarang cariBarangByIDBarang(listBarang P2, Barang p);
adrBarang cekBarangDenganPemasok(listPemasok L, Pemasok pem, string idBarang);

void showPemasok(listPemasok P1);
void showBarang(listBarang p2);
void showAll(listPemasok L);
void showPemasokBarang(listPemasok LP, listBarang LB);

void connect(listPemasok &L1, listBarang L2, Pemasok infoP1, Barang infoP2);

#endif // GUDANG_H_INCLUDED
