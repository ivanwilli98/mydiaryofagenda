#include "pustaka.h"

void urutKegiatan(struct dataKegiatan kegiatan[], int jmlData)
{
    urutDetik(kegiatan,jmlData);
    urutMenit(kegiatan,jmlData);
    urutJam(kegiatan,jmlData);
    urutTanggal(kegiatan,jmlData);
    urutBulan(kegiatan,jmlData);
    urutTahun(kegiatan,jmlData);
}

void urutTahun(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].tahun < kegiatan[min].tahun)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void urutBulan(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].bulan < kegiatan[min].bulan)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void urutTanggal(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].tanggal < kegiatan[min].tanggal)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void urutJam(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].jam < kegiatan[min].jam)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void urutMenit(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].menit < kegiatan[min].menit)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void urutDetik(struct dataKegiatan kegiatan[], int jmlData)
{
    int i,j,min;
    for(i=0;i<jmlData;i++)
    {
        min=i;
        for(j=i;j<jmlData;j++)
        {
            if(kegiatan[j].detik < kegiatan[min].detik)
            {
                swapInt(&j,&min);
            }
        }
        swapKegiatan(&kegiatan[i],&kegiatan[min]);
    }
}

void swapInt(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapKegiatan(struct dataKegiatan *a, struct dataKegiatan *b)
{
    struct dataKegiatan temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
