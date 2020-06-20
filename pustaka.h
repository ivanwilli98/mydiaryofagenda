#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct dataKegiatan
{
    int tanggal, bulan, tahun;
    int jam, menit, detik;
    char nama_kegiatan[999];
    char nama_orang_terkait[999];
};

void menuUtama();
void outputKegiatan(struct dataKegiatan kegiatan[], int jmlData);
void loading();
void reading();
void notif();
void aboutUs();
void dataEmpty(int jmlData);
void urutKegiatan(struct dataKegiatan kegiatan[], int jmlData);
void urutTahun(struct dataKegiatan kegiatan[], int jmlData);
void urutBulan(struct dataKegiatan kegiatan[], int jmlData);
void urutTanggal(struct dataKegiatan kegiatan[], int jmlData);
void urutJam(struct dataKegiatan kegiatan[], int jmlData);
void urutMenit(struct dataKegiatan kegiatan[], int jmlData);
void urutDetik(struct dataKegiatan kegiatan[], int jmlData);
void swapKegiatan(struct dataKegiatan *a, struct dataKegiatan *b);
void cariKegiatan(struct dataKegiatan kegiatan[], int jmlData, int cari, int* cek, int pilihan);
void cektanggal(struct dataKegiatan kegiatan[], int jmlData, int *ceks);
void cekwaktu(struct dataKegiatan kegiatan[], int jmlData, int *ceks);
void tambahKegiatantanggal(struct dataKegiatan kegiatan[], int jmlData);
void tambahKegiatanwaktu(struct dataKegiatan kegiatan[], int jmlData);
void tambahKegiatannama(struct dataKegiatan kegiatan[], int jmlData);
void pilihTanggalHapus(int* hapus);
void pilihDataHapus(int hapus, int* keberapa);
void hapusKegiatan(struct dataKegiatan kegiatan[], int jmlData, int hapus, int keberapa, int* cek);
void geserNol(struct dataKegiatan kegiatan[], int *jmlData);
int jml_hari(int b, int y1);
void inputKalender();
#endif // PUSTAKA_H_INCLUDED
