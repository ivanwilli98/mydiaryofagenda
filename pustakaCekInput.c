#include "pustaka.h"

void cektanggal(struct dataKegiatan kegiatan[], int jmlData, int *ceks)
{
    ///CEK inputan TAHUN, lempar error ketika tahun terlalu usang dari Tahun 2017!!
    if(kegiatan[jmlData].tahun < 2017){
        printf("\n\nTahun %d terlalu usang!\n",kegiatan[jmlData].tahun);
        kegiatan[jmlData].tanggal = 0;
        kegiatan[jmlData].bulan = 0;
        kegiatan[jmlData].tahun = 0;
        printf("Mohon inputkan Tahun saat ini!%c%c",7,7);
        *ceks = 0;
        getch();
        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
    /// Input bulan lebih dari 12
    else if(kegiatan[jmlData].bulan>12)
    {
        printf("\n\nBulan yang anda inputkan tidak Valid!\n");
        kegiatan[jmlData].tanggal = 0;
        kegiatan[jmlData].bulan = 0;
        kegiatan[jmlData].tahun = 0;
        printf("Mohon ulangi input dari awal!%c%c",7,7);
        *ceks = 0;
        getch();
        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
    ///Input tanggal/bulan/tahun = 0
    else if(kegiatan[jmlData].tanggal == 0 || kegiatan[jmlData].bulan == 0 || kegiatan[jmlData].tahun == 0)
    {
        printf("\n\nInputan anda masih ada yang kosong!\n");
        kegiatan[jmlData].tanggal = 0;
        kegiatan[jmlData].bulan = 0;
        kegiatan[jmlData].tahun = 0;
        printf("Mohon ulangi input dari awal!%c%c",7,7);
        *ceks = 0;
        getch();
        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
    /// TANGGAL MAX 31
    ///                 Januari           ||            Maret             ||               Mei            ||             Juli             ||           Agustus            ||            Oktober            ||            Desember           ||
    else if((kegiatan[jmlData].bulan == 1 || kegiatan[jmlData].bulan == 3 || kegiatan[jmlData].bulan == 5 || kegiatan[jmlData].bulan == 7 || kegiatan[jmlData].bulan == 8 || kegiatan[jmlData].bulan == 10 || kegiatan[jmlData].bulan == 12) && (kegiatan[jmlData].tanggal < 0 || kegiatan[jmlData].tanggal > 31))
    {
        printf("\n\nTanggal %d yang anda inputkan tidak sesuai dengan batas tanggal pada ",kegiatan[jmlData].tanggal);

        ///sebut bulan sesuai angka inputan
        if(kegiatan[jmlData].bulan == 1){
            printf("Bulan Januari!\n");
        }else if(kegiatan[jmlData].bulan == 3){
            printf("Bulan Maret!\n");
        }else if(kegiatan[jmlData].bulan == 5){
            printf("Bulan Mei!\n");
        }else if(kegiatan[jmlData].bulan == 7){
            printf("Bulan Juli!\n");
        }else if(kegiatan[jmlData].bulan == 8){
            printf("Bulan Agustus!\n");
        }else if(kegiatan[jmlData].bulan == 10){
            printf("Bulan Oktober!\n");
        }

        kegiatan[jmlData].tanggal = 0;
        kegiatan[jmlData].bulan = 0;
        kegiatan[jmlData].tahun = 0;
        printf("mohon ulangi input dari awal!%c%c",7,7);
        *ceks = 0;
        getch();

        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
    ///FEBRUARI
    else if(kegiatan[jmlData].bulan == 2)
    {
        if(kegiatan[jmlData].tahun%4 == 0 && (kegiatan[jmlData].tahun%100 != 0 || kegiatan[jmlData].tahun%400==0))
        {
            if(kegiatan[jmlData].tanggal < 0 || kegiatan[jmlData].tanggal > 29)
            {
                printf("\nTanggal %d yang anda inputkan tidak sesuai\ndengan batas tanggal pada Bulan Febuari!\n",kegiatan[jmlData].tanggal);
                kegiatan[jmlData].tanggal = 0;
                kegiatan[jmlData].bulan = 0;
                kegiatan[jmlData].tahun = 0;
                printf("mohon ulangi input dari awal!%c%c",7,7);
                *ceks = 0;
                getch();
                system("cls");
                tambahKegiatantanggal(kegiatan,jmlData);
            }
        }
        else
        {
            if(kegiatan[jmlData].tanggal < 0 || kegiatan[jmlData].tanggal > 28)
            {
                printf("\n\nTanggal %d yang anda inputkan tidak sesuai batas bulan %d!\n",kegiatan[jmlData].tanggal,kegiatan[jmlData].bulan);
                kegiatan[jmlData].tanggal = 0;
                kegiatan[jmlData].bulan = 0;
                kegiatan[jmlData].tahun = 0;
                printf("mohon ulangi input dari awal!%c%c",7,7);
                *ceks = 0;
                getch();
                system("cls");
                tambahKegiatantanggal(kegiatan,jmlData);
            }
        }
    }
    /// TANGGAL MAX 30
    ///               April               ||             Juni             ||            September         ||           November            ||
    else if((kegiatan[jmlData].bulan == 4 || kegiatan[jmlData].bulan == 6 || kegiatan[jmlData].bulan == 9 || kegiatan[jmlData].bulan == 11) && (kegiatan[jmlData].tanggal < 0 || kegiatan[jmlData].tanggal > 30))
    {
        printf("\n\nTanggal %d yang anda inputkan tidak sesuai batas bulan %d!\n",kegiatan[jmlData].tanggal,kegiatan[jmlData].bulan);
        kegiatan[jmlData].tanggal = 0;
        kegiatan[jmlData].bulan = 0;
        kegiatan[jmlData].tahun = 0;
        printf("mohon ulangi input dari awal!%c%c",7,7);
        *ceks = 0;
        getch();
        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
}

void cekwaktu(struct dataKegiatan kegiatan[], int jmlData, int *ceks)
{
    int hasilbagi;
    int hasilmod;
    ///Membatasi inputan jam (max 23)
    if(kegiatan[jmlData].jam > 23)
    {
        printf("inputan jam melebihi batasan (maks 23)\n");
        printf("mohon ulangi input dari awal!%c%c",7,7);
        *ceks = 0;
        getch();
        system("cls");
        tambahKegiatantanggal(kegiatan,jmlData);
    }
    ///Batas input jam => 0 - 24
    else if(kegiatan[jmlData].jam > 0 || kegiatan[jmlData].jam < 24)
    {
        ///Jika detik lebih dari 60
        if(kegiatan[jmlData].detik >= 60)
        {
            hasilbagi = kegiatan[jmlData].detik/60;
            kegiatan[jmlData].menit = kegiatan[jmlData].menit+hasilbagi;

            hasilmod = kegiatan[jmlData].detik%60;
            kegiatan[jmlData].detik = hasilmod;
        }
        ///Jika menit lebih dari 60
        if(kegiatan[jmlData].menit >= 60)
        {
            hasilbagi = kegiatan[jmlData].menit/60;
            kegiatan[jmlData].jam = kegiatan[jmlData].jam+hasilbagi;
            hasilmod = kegiatan[jmlData].menit%60;
            kegiatan[jmlData].menit = hasilmod;
        }
        ///Kalau jam lebih dari 23
        if(kegiatan[jmlData].jam > 23)
        {
            kegiatan[jmlData].tanggal=kegiatan[jmlData].tanggal+1;
            hasilmod = kegiatan[jmlData].jam%24;
            kegiatan[jmlData].jam = hasilmod;
            cektanggal(kegiatan,jmlData,&ceks); ///manggil procedure cektanggal untuk cek tanggal bila melebihi limit
        }
    }
}
