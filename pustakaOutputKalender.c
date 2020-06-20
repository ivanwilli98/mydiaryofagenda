#include "pustaka.h"

int jml_hari(int b, int y1)
{
    int h;
    ///Deklarasi jumlah hari dalam 1 bulan
    if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
    {
        h = 31;
    }
    else if(b == 4 || b == 6 || b == 9 || b == 11)
    {
        h = 30;
    }
    else if((y1%100!=0 && y1%4==0) || y1%400==0)
    {
        h = 29;///untuk tahun kabisat
    }
    else
    {
        h=28;
    }
    return h;
}

void inputKalender()
{
    ///Kamus
    int t,tahun,y1,bulan,b,h,i,j,k;
    char pil; ///pilihan untuk ulang kalender
    char nama_bulan[12][20]={"Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};

    ///Algoritma
    ulang:

    printf("==========================================\n\t      Lihat Kalender\n==========================================\n");
    ulgkalender:
    printf("Masukkan tahun (FROM 2010 - NOW): ");
    fflush(stdin); scanf("%d",&tahun);

    if(tahun >1990 && tahun < 2010){
        printf("\n Tahun %d sudah terlalu usang!!\n%c%c",tahun,7,7);
        getch();
        system("cls");
        goto ulang;
    }else if(tahun < 1990 || tahun > 2099){
        printf("\n Maaf, Inputan Tahun anda salah atau tidak valid!!\n%c%c",7,7);
        getch();
        system("cls");
        goto ulang;
    }

    ulgbln:
    printf("Masukkan bulan (FROM 1 - 12): ");
    fflush(stdin);scanf("%d",&bulan);

    if(bulan < 1 || bulan >12){
        printf("Bulan ke-%d Tidak ada dalam daftar kalender!!\n%c%c",bulan,7,7);
        getch();
        system("cls");
        goto ulang;
    }


    system("cls");

    ///hitung jumlah hari sampai tahun sebelumnya
    t=0;
    for(y1=0;y1<tahun;y1++)
    {
        if((y1%100!=0 && y1%4==0) || y1%400==0)
        {
            t=t+366;
        }
        ///tahun kabisat
        else
        {
            t=t+365;
        }
    }
    ///hitung jumlah hari sampai bulan sebelumnya
    b=1;
    for(b=1;b<bulan;b++)
    {
        h=jml_hari(b,tahun);
        t=t+h;
    }
    h=t%7;

    ///LOADING INTERFACE KALENDER
    loading();

    ///pengaturan tampilan kalender
    printf("\t      K A L E N D E R\n");
    printf("============================================\n      ------------ %d --------------\n",tahun);
    printf("              ---- %s ----\n",nama_bulan[bulan-1]);
    printf(" -------------------------------------------\n");
    printf(" | Min | Sen | Sel | Rab | Kam | Jum | Sab | \n");
    printf(" -------------------------------------------\n");
    k=1;
    for(i=1;i<=jml_hari(bulan,tahun);i++,k++)
    {
        if(i==1)///penempatan tanggal satu
        {
            if(h==0)
            {
                for(j=1;j<7;j++,k++)
                printf("%6s","");
            }
            else
            {
                for(j=1;j<h;j++,k++)
                printf("%6s","");
            }
        }
        printf("%6d",i);
		if(k%7==0)///untuk memisah antar minggunya
        {
            printf("\n");
        }
    }printf("\n====================[][]====================\n");

    Sleep(1000);
    printf("\n\nIngin lihat Kalender dengan BULAN yang BERBEDA\ndi TAHUN yang SAMA (Y / N)? "); fflush(stdin); scanf("%c", &pil);
    if (pil == 'y' || pil == 'Y'){
        printf("\n\n  ");
        goto ulgbln;
    }else{
        printf("\n  Ingin lihat kalender dengan TAHUN dan BULAN\n  yang BERBEDA (Y / N)? "); fflush(stdin); scanf("%c", &pil);
        if (pil == 'y' || pil == 'Y'){
            printf("\n\n");
            goto ulgkalender;
        }else{
            printf("\n\n\t... PRESS ANY KEY TO CONTINUE ...\n");
        }
    }

}
