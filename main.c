#include "pustaka.h"

int main()
{
    ///Kamus
    int menu;
    int isiData = -1;       ///-1 supaya bisa menampilkan empty data
    struct dataKegiatan dataKegiatan[999];
    int cari,hapus,keberapa;
    int kesempatan = 0; ///untuk kesempatan error
    int cek = 1; ///variable untuk cek, di set true

    ///Algoritma
    menu:
    menuUtama();
    scanf("%d", &menu);
    switch(menu)
    {
        case 1 : ///Tambah Kegiatan
        {
            ///Ubah isiData biar ga empty dan bisa diimput
            if(isiData == -1)
            {
                isiData = 0;
            }
            system("cls");
            loading();
            tambahKegiatantanggal(dataKegiatan, isiData);
            isiData++;
            system("cls");
            goto menu;
            break;
        }

        case 2 : ///Tampilkan kegiatan
        {
            system("cls");
            reading();
            printf("==========================================\n\t   Menampilkan Kegiatan\n==========================================\n");
            if(isiData == -1)
            {
                dataEmpty(isiData);
            }
            else
            {
                outputKegiatan(dataKegiatan, isiData);
                printf("==========================================\n");
                printf("\n     ... PRESS ANY KEY TO CONTINUE ...\n");
            }
            printf("\n==========================================\n");
            getch();
            system("cls");
            goto menu;
            break;
        }

        case 3 : ///Hapus kegiatan
        {
            system("cls");
            reading();
            printf("==========================================\n\t     Menghapus Kegiatan\n==========================================\n");
            if(isiData == -1)
            {
                dataEmpty(isiData);
            }
            else
            {
                outputKegiatan(dataKegiatan, isiData);
                printf("==========================================\n");
                pilihTanggalHapus(&hapus);
                if(hapus == 0 || hapus > 31)
                {
                    printf("Mohon maaf, tolong inputkan TANGGAL dengan benar%c%c",7,7);
                }
                else
                {
                    cariKegiatan(dataKegiatan, isiData, hapus, &cek,1);
                    if(cek == 1) ///true
                    {
                        pilihDataHapus(hapus, &keberapa);
                        hapusKegiatan(dataKegiatan, isiData, hapus, keberapa, &cek);
                        if(cek == 1) /// true
                        {
                            printf("Data berhasil di HAPUS!\n\n");
                            printf("==========================================\n");
                            printf("\n     ... PRESS ANY KEY TO CONTINUE ...\n");
                            printf("==========================================\n");
                            geserNol(dataKegiatan,&isiData);
                        }
                        else
                        {
                            printf("Maaf, DATA yang dicari tidak ketemu!%c%c",7,7);
                        }
                    }
                    else if(cek == 0)
                    {
                        printf("Maaf, TANGGAL yang dicari tidak ketemu!\n%c%c",7,7);
                    }
                }
            }
            printf("\n==========================================\n");
            getch();
            system("cls");
            goto menu;
            break;
        }

        case 4 : ///Cari kegiatan
        {
            system("cls");
            reading();
            printf("==========================================\n\t     Mencari Kegiatan\n==========================================\n");
            if(isiData == -1)
            {
                dataEmpty(isiData);
            }
            else
            {
                printf("Inputkan TANGGAL yang mau dicari : "); scanf("%d",&cari);
                printf("\n\n\n==========================================\n  Result : \n------------------------------------------\n");
                cariKegiatan(dataKegiatan, isiData, cari, &cek,2);
                if(cek == 0)
                {
                    printf("  Tanggal yang dicari tidak ketemu!\n\n%c%c",7,7);
                }
                printf("==========================================\n");
                printf("\n     ... PRESS ANY KEY TO CONTINUE ...\n");
            }
            printf("\n==========================================\n");
            getch();
            system("cls");
            goto menu;
            break;
        }


        case 5: ///Output Kalender
        {
            system("cls");
            reading();
            inputKalender();
            getch();
            system("cls");
            goto menu;
            break;
        }

        case 6 : ///ABOUT US!
        {
            system("cls");
            aboutUs();
            getch();
            system("cls");
            goto menu;
            break;
        }

        case 0 : ///EXIT
        {
            system("cls");
            Sleep(300);
            printf("\n\n\tTerima Kasih sudah menggunakan Mesin \"My DIARY of AGENDA\" !\n");
            notif();
            break;
        }

        default : ///Jika jawaban selain 0~6
        {
            system("cls");
            printf("\n\tEh, Menunya cuma ada 0-6, press any key to go back!");
            printf("\n\t\tAnda sudah salah input sebanyak %dx", kesempatan+1);
            ///Suara Notif Peringatan!
            int c;
            for(c=-1; c<kesempatan; c++){
                printf("%c",7);
            }
            getch();
            system("cls");
            kesempatan=kesempatan+1;
            if(kesempatan == 3)
            {
                printf("\n\t      Anda sudah Salah input sebanyak %dx!\n", kesempatan);
                printf("\t         Silahkan buka program lagi!\n%c%c",7,7);
                getch();
                notif();
                break;
            }
            else
            {
                goto menu;
                break;
            }
        }
    }
    return 0;
}
