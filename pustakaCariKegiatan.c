#include "pustaka.h"

void cariKegiatan(struct dataKegiatan kegiatan[], int jmlData, int cari, int* cek, int pilihan)
{
    int i;
    int j=1;
    int ceks=0; ///ceks = false;
    ///Pilihan 1 = menampilkan data ke %d
    ///Pilihan 2 = hanya menampilkan data
    for(i=0;i<jmlData;i++)
    {
        if(kegiatan[i].tanggal == cari)
        {
            if(pilihan == 1)
            {
                printf("  \n\n===  DATA ke-%2d  ===\n", j);
                printf("    Tanggal kegiatan       : %d/%d/%d\n", kegiatan[i].tanggal, kegiatan[i].bulan, kegiatan[i].tahun);
            }
            else
            {
                printf("\n");
                printf("%2d. Tanggal kegiatan       : %d/%d/%d\n",i+1, kegiatan[i].tanggal, kegiatan[i].bulan, kegiatan[i].tahun);
            }

            printf("    Waktu kegiatan         : ");
            if(kegiatan[i].jam <10 && kegiatan[i].jam >=0)
            {
                printf("0%d:",kegiatan[i].jam);
            }
            else
            {
                printf("%d:",kegiatan[i].jam);
            }

            if(kegiatan[i].menit <10 && kegiatan[i].menit >=0)
            {
                printf("0%d:",kegiatan[i].menit);
            }
            else
            {
                printf("%d:",kegiatan[i].menit);
            }

            if(kegiatan[i].detik <10 && kegiatan[i].detik >=0)
            {
                printf("0%d\n",kegiatan[i].detik);
            }
            else
            {
                printf("%d\n",kegiatan[i].detik);
            }

            printf("    Nama kegiatan          : %s\n", kegiatan[i].nama_kegiatan);
            printf("    Nama orang terkait     : %s\n\n", kegiatan[i].nama_orang_terkait);
            ceks = 1; ///ceks = false;
            j++; ///untuk data ke ...
        }
        else
        {
            continue;
            ceks = 0; ///ceks = false
        }
    }
    *cek = ceks;
}
