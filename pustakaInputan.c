#include "pustaka.h"

///UNTUK PILIHAN INPUT KEGIATAN
void tambahKegiatantanggal(struct dataKegiatan kegiatan[], int jmlData)
{
    int cektrue = 1;
    fflush(stdin);
    printf("==========================\n   Tambah Kegiatan\n==========================\n\n");
    printf(" 1. Inputkan tanggal, bulan, dan tahun kegiatan\n     \t\t(dd/mm/yyyy)\t= ");
    scanf("%d/%d/%d", &kegiatan[jmlData].tanggal,&kegiatan[jmlData].bulan,&kegiatan[jmlData].tahun);
    cektanggal(kegiatan, jmlData,&cektrue);
    if(cektrue == 1)
    {
        tambahKegiatanwaktu(kegiatan,jmlData);
    }
}

void tambahKegiatanwaktu(struct dataKegiatan kegiatan[], int jmlData)
{
    int cektrue = 1;
    fflush(stdin);
    printf("\n 2. Inputkan jam, menit, dan detik kegiatan dengan format 24 jam\n     \t\t(HH MM SS)\t= ");
    scanf("%d %d %d", &kegiatan[jmlData].jam, &kegiatan[jmlData].menit, &kegiatan[jmlData].detik);
    cekwaktu(kegiatan,jmlData,&cektrue);
    if(cektrue == 1)
    {
        tambahKegiatannama(kegiatan,jmlData);
    }
}

void tambahKegiatannama(struct dataKegiatan kegiatan[], int jmlData)
{
    printf("\n 3. Inputkan nama kegiatan\t: "); fflush(stdin); gets(kegiatan[jmlData].nama_kegiatan);
    printf("\n 4. Inputkan nama orang terkait\t: "); fflush(stdin); gets(kegiatan[jmlData].nama_orang_terkait);

    Sleep(300);
    printf("\n\n\tSAVED SUCCESS!!");
    Sleep(500);
}

///UNTUK PILIHAN HAPUS
void pilihTanggalHapus(int* hapus)
{
    int pilihan;
    printf("\nMau hapus TANGGAL berapa? (dd) : ");
    scanf("%d", &pilihan);
    *hapus = pilihan;
}

void pilihDataHapus(int hapus, int* keberapa)
{
    int pilihan;
    printf("\nMau hapus tanggal %d DATA yang ke berapa? ", hapus);
    scanf("%d", &pilihan);
    *keberapa = pilihan;
}
