#include "gudang.h"

void createlistPemasok(listPemasok& L){
    first(L) = NULL;
}

void createlistBarang(listBarang& L){
    first(L) = NULL;
}

adrPemasok alokasiPemasok(Pemasok p){
    adrPemasok x = new elmPemasok;
    info(x) = p;
    hasRelation(x) = NULL;
    next(x) = NULL;
    return x;
}

adrBarang alokasiBarang(Barang p){
    adrBarang x = new elmBarang;
    info(x) = p;
    next(x) = NULL;
    return x;
}

void insertFirstPemasok(listPemasok &L, adrPemasok p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        next(p) = first(L);
        first(L) = p;
    }
}
void insertLastPemasok(listPemasok& L, adrPemasok p){
    adrPemasok Q = first(L);
    if(first(L)== NULL){
        first(L) = p;
    }else{
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = p;
        cout << "Data Pemasok sudah ditambahkan" << endl;
    }
}
void insertFirstBarang(listBarang &L, adrBarang p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        next(p) = first(L);
        first(L) = p;
    }
}
void insertLastBarang(listBarang& L, adrBarang p){
    adrBarang j = first(L);
    if (first(L) == NULL){
        first(L) = p;
    }else{
        while (next(j) != NULL){
            j = next(j);
        }
        next(j) = p;
    }
}

adrPemasok cariPemasokByID(listPemasok L, Pemasok p){
    adrPemasok j = first(L);
    if (first(L) == NULL){
        cout << "List Pemasok Kosong" << endl;
        return NULL;
    }else{
        while (j != NULL && info(j).id != p.id){
            j = next(j);
        }
        if(info(j).id == p.id && j !=NULL){
            return j;
        }else{
            return NULL;
        }
    }
}

void deleteLastPemasok(listPemasok &L, adrPemasok p){
    if(first(L)== NULL){
        p = NULL;
        cout << "List Pemasok Kosong" << endl;
    }else if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        adrPemasok q = first(L);
        while (next(next(q)) != NULL){
            q = next(q);
        }
        p = q;
        next(q) = NULL;
         cout << "Data Pemasok dihapus" << endl;
    }
}

void deleteFirstPemasok(listPemasok &L, adrPemasok p){
    if(first(L) != NULL){
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
        cout << "Data Pemasok telah dihapus" << endl;
    }else{
        p = NULL;
        cout << "List Pemasok Kosong" << endl;
    }
}
void deleteAfterPemasok(listPemasok &L,adrPemasok &prec){
    if(prec != NULL){
        adrPemasok j = first(L);
        if (next(first(L)) == NULL){
            first(L) = NULL;
        }else{
            j = next(prec);
            next(prec) = next(j);
            next(j) = NULL;
            cout << "Data Pemasok telah dihapus" << endl;
        }
    }
}
void deleteFirstBarang(listBarang &L, adrBarang p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
        cout << "Data Barang dihapus" << endl;
    }
}

void deleteLastBarang(listBarang &L, adrBarang p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        adrBarang j = first(L);
        while (next(next(j)) != NULL){
            j = next(j);
        }
        p = j;
        next(j) = NULL;
         cout << "Data Barang dihapus" << endl;
    }
}

void deleteAfterBarang(listBarang &L,adrBarang &prec){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        adrBarang j = first(L);
        while (next(j) != NULL && next(j) != prec){
            j = next(j);
        }
        adrBarang p = next(j);
        next(j) = next(p);
         cout << "Data Barang dihapus" << endl;
    }
}
void deletePemasok(listPemasok &L, Pemasok p) {
    adrPemasok FindP = cariPemasokByID(L, p);
    if (FindP != NULL) {
        cout << "Cari Pemasok: " << info(FindP).nama << "ID: " << info(FindP).id << endl;
        hasRelation(FindP) = NULL;
        if (FindP == first(L)) {
            cout << "Hapus Pemasok Awal" << endl;
            deleteFirstPemasok(L, FindP);
        } else if (next(FindP) == NULL) {
            cout << "Hapus Pemasok Akhir" << endl;
            deleteLastPemasok(L, FindP);
        } else {
            cout << "hapus Pemasok di Tengah list" << endl;
            deleteAfterPemasok(L, FindP);
        }
        cout << "Pemasok dengan nama " << info(FindP).nama << " dihapus" << endl;
    } else {
        cout << "Pemasok tidak ditemukan" << endl;
    }
}

adrBarang cariBarangByIDBarang(listBarang L, Barang p){
    if (first(L) == NULL){
        cout << "List Gudang Kosong" << endl;
        return NULL;
    }else{
        adrBarang j = first(L);
        while (j != NULL && info(j).idBarang != p.idBarang){
            j = next(j);
        }
        return j;
    }
}

adrBarang cekBarangDenganPemasok(listPemasok L, Pemasok x, string idBarang){
      adrPemasok findPemasok = cariPemasokByID(L, x);
    if (findPemasok != NULL) {
        adrRelation rl = hasRelation(findPemasok);
        cout << "relasi" << endl;
        while (rl != NULL && info(relationPemasok(rl)).id != x.id) {
            rl = next(rl);
        }
        if (rl != NULL) {
            while (rl != NULL && info(relationBarang(rl)).idBarang != idBarang) {
                rl = next(rl);
            }
            if (rl != NULL) {
                return relationBarang(rl);
            } else {
                cout << "data Barang tidak di temukan" << endl;
            }
        } else {
            cout << "Pemasok belum memasukan Barang" << endl;
        }
    } else {
        cout << "Pemasok tidak di temukan" << endl;
    }

    return NULL;
};

adrRelation alokasiRelation(adrPemasok p1, adrBarang p2){
    adrRelation p = new elmRelasi;
    relationPemasok(p) = p1;
    relationBarang(p) = p2;
    next(p) = NULL;
    return p;
};

void connect(listPemasok &L1, listBarang L2,Pemasok infoPemasok, Barang infoGudang){
    adrPemasok FindPm = cariPemasokByID(L1,infoPemasok);
    adrBarang FindGd = cariBarangByIDBarang(L2,infoGudang);
    if (FindPm != NULL && FindGd != NULL){
        if (hasRelation(FindPm) == NULL){
            hasRelation(FindPm) = alokasiRelation(FindPm,FindGd);
        }else{
            adrRelation j =  alokasiRelation(FindPm,FindGd);
            adrRelation p = hasRelation(FindPm);
            while (next(p) != NULL){
                p = next(p);
            }
            next(p) = j;
        }
         cout << "Barang sudah terdaftar , Terima kasih sudah memakai layanan kami" << endl;
    }else{
        cout << "Barang belum terdaftar" << endl;
    }
};

void deleteBarang(listPemasok &L, listBarang &L2, Barang infoGudang){
    adrBarang findBarang = cariBarangByIDBarang(L2,infoGudang);
    if (findBarang != NULL){
        adrPemasok p = first(L);
        while(p != NULL){
            adrRelation child = hasRelation(p);
            if (child != NULL){
                while(child != NULL && findBarang != relationBarang(child)){
                    child = next(child);
                }
                if(hasRelation(p) == child){
                    hasRelation(p) = next(hasRelation(p));
                }else if(next(hasRelation(p)) == NULL){
                    adrRelation j = hasRelation(p);
                    while (next(j) != NULL){
                        j = next(j);
                    }
                    next(j) = NULL;
                }else{
                  adrRelation j = hasRelation(p);
                    while (next(j) != NULL && next(j) != child){
                        j = next(j);
                    }
                  adrRelation k = next(j);
                  next(j) = next(k);
                }
            }
            p = next(p);
        }
        if(first(L2) == findBarang){
                cout << "here  1" << endl;
            deleteFirstBarang(L2,findBarang);
        }else if(next(findBarang) == NULL){
            cout << "here  2" << endl;
            deleteLastBarang(L2,findBarang);
        }else{
            cout << "here  3" << endl;
            deleteAfterBarang(L2,findBarang);
        }

    }else{
        cout << "Error" << endl;
    }
}

void showPemasok(listPemasok P1) {
    if (first(P1) == NULL) {
        cout << "List Pemasok Belum ditambahkan" << endl;
    } else {
        adrPemasok j = first(P1);
        cout << "List Pemasok" << endl;
        while (j != NULL) {
            cout << endl;
            cout << "ID Pemasok: " << info(j).id << endl;
            cout << "Nama Pemasok: " << info(j).nama << endl;
            cout << "Alamat: " << info(j).alamat << endl;
            cout << "Nomor Telepon: " << info(j).noTelp << endl;
            j = next(j);
        }
    }
}

void showBarang(listBarang P2) {
    if (first(P2) == NULL) {
        cout << "List Barang belum ditambahkan" << endl;
    } else {
        adrBarang j = first(P2);
        cout << "List Barang" << endl;
        while (j != NULL) {
            cout << endl;
            cout << "ID Barang: " << info(j).idBarang << endl;
            cout << "Jenis Barang: " << info(j).jenis << endl;
            cout << "Jumlah Barang: " << info(j).jumlah << endl;
            j = next(j);
        }
    }
}

void showAll(listPemasok L){
     if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        adrPemasok j = first(L);
        int counter = 0;
        cout << "Show All List" << endl;
        while (j != NULL){
            cout << endl;
            cout << "List ke " << counter++ << endl;
            cout << "List Pemasok" << endl;
            cout << "Id Pemasok : " << info(j).id << endl;
            cout << "Nama Peamsok: " << info(j).nama << endl;
            cout << "Alamat : " << info(j).alamat << endl;
            cout << "Nomor Telepon : " << info(j).noTelp << endl;
            cout << endl;
            if (hasRelation(j) != NULL){
                cout << "List Barang yang terhubung dengan " << info(j).nama  << endl;
                adrRelation k = hasRelation(j);
                while (k != NULL){
                    cout << endl;
                    cout << "ID Barang : " <<info(relationBarang(k)).idBarang << endl;
                    cout << "Jenis : " <<info(relationBarang(k)).jenis << endl;
                    cout << "Jumlah Barang : " <<info(relationBarang(k)).jumlah << endl;
                    k = next(k);
                }
            };
            cout << endl;
            j = next(j);
        }
    }
};

void showPemasokBarang(listPemasok LP, listBarang LB) {
    if (first(LP) == NULL) {
        cout << "List Pemasok Kosong" << endl;
    } else {
        adrPemasok pemasokPtr = first(LP);
        int pemasokCount = 1;
        while (pemasokPtr != NULL) {
            cout << "Pemasok ke-" << pemasokCount << ":" << endl;
            cout << "ID Pemasok: " << info(pemasokPtr).id << endl;
            cout << "Nama Pemasok: " << info(pemasokPtr).nama << endl;
            cout << "Alamat: " << info(pemasokPtr).alamat << endl;
            cout << "Nomor Telepon: " << info(pemasokPtr).noTelp << endl;
            adrRelation relationPtr = hasRelation(pemasokPtr);
            if (relationPtr != NULL) {
                cout << "Barang yang terhubung:" << endl;
                while (relationPtr != NULL) {
                    cout << "  ID Barang: " << info(relationBarang(relationPtr)).idBarang << endl;
                    cout << "  Jenis Barang: " << info(relationBarang(relationPtr)).jenis << endl;
                    cout << "  Jumlah Barang: " << info(relationBarang(relationPtr)).jumlah << endl;
                    relationPtr = next(relationPtr);
                }
            } else {
                cout << "Tidak ada Barang yang terhubung." << endl;
            }
            cout << "-----------------------" << endl;
            pemasokPtr = next(pemasokPtr);
            pemasokCount++;
        }
    }
}
