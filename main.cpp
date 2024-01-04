#include "gudang.h"

int main()
{
    listPemasok LP;
    listBarang LB;
    createlistPemasok(LP);
    createlistBarang(LB);
    Pemasok x;
    Barang b;
    for (int input = 99; input != 0;) {
        cout << "-------------- Menu -------------- \n";
        cout << "1. Tambah data ke Pemasok\n";
        cout << "2. Tambah data ke Barang\n";
        cout << "3. Hubungkan data dari Pemasok ke Barang\n";
        cout << "4. Show List Pemasok\n";
        cout << "5. Show List Barang\n";
        cout << "6. Show relasi Pemasok dan Barang\n";
        cout << "7. Cek Barang yang terhubung dengan Pemasok\n";
        cout << "8. Hapus data Pemasok\n";
        cout << "9. Hapus data Barang\n";
        cout << "10. Show Pemasok dengan Barangnya \n";
        cout << "0. Keluar\n";
        cout << "---------------------------------- \n  ";
        cout << "Pilihan Anda: ";
        cin >> input;
        if (input == 1) {
            Pemasok x;
            cout << "Masukkan data untuk List Pemasok: \n";
            cout << "ID: ";
            cin >> x.id;
            cout << "Nama : ";
            cin >> x.nama;
            cout << "Alamat : ";
            cin >> x.alamat;
            cout << "Nomer Telepon : ";
            cin >> x.noTelp;
            adrPemasok point_pemasok = alokasiPemasok(x);
            insertLastPemasok(LP, point_pemasok);
        } else if (input == 2) {
            cout << endl;
            cout << "Masukkan data untuk List barang:\n";
            cout << "ID Barang: ";
            cin >> b.idBarang;
            cout << "Jenis Barang: ";
            cin >> b.jenis;
            cout << "Jumlah Barang: ";
            cin >> b.jumlah;
            adrBarang PointBarang = alokasiBarang(b);
            insertLastBarang(LB, PointBarang);
            cout << endl;
        } else if (input == 3) {
            Pemasok infoPemasok;
            Barang infoBarang;
            cout << endl;
            cout << "Masukkan data id pemasok dan id barang untuk dihubungkan\n";
            cout << "Masukkan id pemasok:\n";
            cout << "Id Pemasok: ";
            cin >> infoPemasok.id;
            cout << "Masukkan ID barang: ";
            cin >> infoBarang.idBarang;
            connect(LP, LB, infoPemasok, infoBarang);
            cout << endl;
        } else if (input == 4) {
            showPemasok(LP);
        } else if (input == 5) {
            showBarang(LB);
        } else if (input == 6) {
            showAll(LP);
        } else if (input == 7) {
            adrBarang terhubung;
            cout << endl;
            cout << "Masukkan data pemasok: \n";
            cout << "ID Pemasok : ";
            cin >> x.id;
            cout << "Nama Pemasok : ";
            cin >> x.nama;
            cout << "Alamat : ";
            cin >> x.alamat;
            cout << "Masukkan ID Pemasok : ";
            cin >> b.idBarang;
            terhubung = cekBarangDenganPemasok(LP, x, b.idBarang);
            if (terhubung != NULL) {
                cout << "Pemasok sudah terhubung" << endl;
            } else {
                cout << "Pemasok tidak terhubung" << endl;
            }
            cout << endl;
        } else if (input == 8) {
            cout << endl;
            cout << "Masukkan  id data pemasok yang ingin dihapus: \n";
            cout << "ID Pemasok: ";
            cin >> x.id;
            cout << "Nama Pemasok: ";
            cin >> x.nama;
            cout << "Alamat: ";
            cin >> x.alamat;
            deletePemasok(LP, x);
            cout << endl;
        } else if (input == 9) {
            cout << endl;
            cout << "Masukkan data Barang yang ingin dihapus: \n";
            cout << "ID Barang: ";
            cin >> b.idBarang;
            deleteBarang(LP, LB, b);
            cout << endl;
        } else if(input == 10){
            cout << endl;
            showPemasokBarang(LP, LB);
            cout << endl;
        }else if (input == 0) {
            cout << "Program selesai.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
    return 0;
}
