#include "pustaka.h"

void hapusKegiatan(struct dataKegiatan kegiatan[], int jmlData, int hapus, int keberapa, int* cek)
{
    int i;
    int temp=0;
    int ceks = 0; ///set true
    for(i=0;i<jmlData;i++)
    {
        if(kegiatan[i].tanggal == hapus)
        {
            temp++;
            if(temp == keberapa)
            {
                kegiatan[i].tanggal = 0;
                kegiatan[i].bulan = 0;
                kegiatan[i].tahun = 0;
                kegiatan[i].jam = 0;
                kegiatan[i].menit = 0;
                kegiatan[i].detik = 0;
                ceks = 1;
            }
        }
    }
    *cek = ceks;
}

void geserNol(struct dataKegiatan kegiatan[], int *jmlData)
{
    int i,j;
    int jmlDataBaru=0;;
    struct dataKegiatan temp;
    ///Geser 0 ke kanan
    for(i=0;i<*jmlData;i++)
    {
        if(kegiatan[i].tanggal == 0)
        {
            temp = kegiatan[i];
            kegiatan[i] = kegiatan[i+1];
            kegiatan[i+1] = temp;
        }
    }
    ///cek berapa nol
    for(i=0;i<*jmlData;i++)
    {
        if(kegiatan[i].tanggal != 0)
        {
            jmlDataBaru++;
        }
    }
    ///jika jumlah 0 = 0, maka jmlData = -1 (supaya EMPTY)
    if(jmlDataBaru == 0)
    {
        *jmlData = -1;
    }
    else
    {
        *jmlData = jmlDataBaru;
    }
}
