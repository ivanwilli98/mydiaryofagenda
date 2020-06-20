#include"pustaka.h"

///GANTI VERSI TIAP KALI UPDATE!!
float version =1.8;

void menuUtama()
{
    Sleep(100);
    printf("==========================\n=== MY DIARY of AGENDA ===\n===     Version %.1f    ===\n==========================\n",version);
    Sleep(500);
    printf(" Daftar Menu :\n");
    Sleep(300);
    printf("  1. Tambah Kegiatan\n");
    printf("  2. Tampilkan Kegiatan\n");
    printf("  3. Hapus Kegiatan\n");
    printf("  4. Cari Kegiatan\n");
    printf("  5. Cetak Kalender\n");
    printf("  6. About Us!\n");
    printf("  0. Exit\n");
    Sleep(500);
    printf("==========================\n\n");
    Sleep(300);
    printf(" Masukkan Pilihan : ");
    fflush(stdin); ///Fix infinite looping ketika input selain angka
}

void outputKegiatan(struct dataKegiatan kegiatan[], int jmlData)
{
    urutKegiatan(kegiatan,jmlData); ///Diurutkan lagi
    int i;
    for(i=0;i<jmlData;i++)
    {
        printf("\n");
        printf("%2d. Tanggal kegiatan       : ",i+1);


        ///Tampilan DATE
        ///tanggal
        if(kegiatan[i].tanggal <10 && kegiatan[i].tanggal>0){
            printf("0%d/",kegiatan[i].tanggal);
        }else{
            printf("%d/",kegiatan[i].tanggal);
        }
        ///bulan
        if(kegiatan[i].bulan <10 && kegiatan[i].bulan>0){
            printf("0%d/",kegiatan[i].bulan);
        }else{
            printf("%d/",kegiatan[i].bulan);
        }
        ///Tahun
        printf("%d\t   [DD/MM/YYYY]\n",kegiatan[i].tahun);

        printf("    Waktu kegiatan         : ");
        ///Tampilan waktu
        ///Jam
        if(kegiatan[i].jam <10 && kegiatan[i].jam >=0)
        {
            printf("0%d:",kegiatan[i].jam);
        }
        else
        {
            printf("%d:",kegiatan[i].jam);
        }
        ///Menit
        if(kegiatan[i].menit <10 && kegiatan[i].menit >=0)
        {
            printf("0%d:",kegiatan[i].menit);
        }
        else
        {
            printf("%d:",kegiatan[i].menit);
        }
        ///Detik
        if(kegiatan[i].detik <10 && kegiatan[i].detik >=0)
        {
            printf("0%d\t   [HH:MM:SS]\n",kegiatan[i].detik);
        }
        else
        {
            printf("%d\t   [HH:MM:SS]\n",kegiatan[i].detik);
        }
        printf("    Nama kegiatan          : %s\n", kegiatan[i].nama_kegiatan);
        printf("    Nama orang terkait     : %s\n", kegiatan[i].nama_orang_terkait);
    }
}

void loading()
{
    ///timing set
    Sleep(100);printf("\tGENERATING");int i;
    for (i=0; i<4; i++){Sleep(100);printf(" .");}
    system("cls");
}

void reading()
{
    ///timing set
    Sleep(100);printf("\tREADING ");int i;
    for (i=0; i<4; i++){Sleep(100);printf(" .");}
    system("cls");
}

void notif()
{
    ///timing set
    Sleep(500);printf("\t\tCleaning Chache then EXITING ");int i;
    for (i=0; i<4; i++){Sleep(700);printf(" .");}
    Sleep(500);
    printf("  DONE!!");
    Sleep(700);
    printf("\n\t\t       See You AGAIN!!");
    Sleep(1700);
    system("cls");
}

void aboutUs()
{
    printf("==========================\n=== MY DIARY of AGENDA ===\n===     Version %.1f    ===\n==========================\n\n",version);
    printf("  ABOUT US!!\n-------------\n");
    printf("  Crew :\n");
    printf("    1. Ivan William\t\t(A11.2016.09376)\n");
    printf("    2. Kevin Ronaldo Cahyono\t(A11.2016.09381)\n");
    printf("    3. Muhammad Arif Arsyalan\t(A11.2016.09383)\n");
    printf("    4. Faulza Resiqoha\t\t(A11.2016.09406)");
    printf("\n\n==========================\n\n");
    Sleep(1000);
    printf("\n   Thank You for using \"MY DIARY of AGENDA\" !!\n\n%c",7);
}

void dataEmpty(int jmlData)
{
    if(jmlData == -1)
    {
        printf("\n\t\tE M P T Y !%c%c\n\tPress ANY KEY to Continue!!\n",7,7);
    }
}
