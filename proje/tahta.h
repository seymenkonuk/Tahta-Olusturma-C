/*
Oyunlar i�in Tahta Olu�turur ve WASD Tu�lar� ile Tahtada Gezinmeyi Sa�lar
*/

#ifndef TAHTA_H
#define TAHTA_H
#include <stdio.h>
#include <stdlib.h>
#include "../lib/imlec.h" // https://github.com/seymenkonuk/Imlec-Kontrol-C

void tahtaOlustur(int g, int y, int mod);   // Uzunluk De�erlerine G�re �ekilli Tahta Olu�tur
void tahtaGit(int x, int y);                // Tahtan�n Girilen Koordinatlar�na �mleci G�t�r
void tahtaKontrol(const char tus, int mod); // Tu�a G�re Tahtada Hareket Ettir

int konumx, konumy;
int genislik, yukseklik;

void tahtaGit(int x, int y) {
    gotoxy(4*x-2, 2*y-1);
    konumx = x; konumy = y;
}

void tahtaOlustur(int g, int y, int mod) {
    system("cls");
    int i, j;
    genislik = g; yukseklik = y;
    
    if (mod == 0); // G�r�nt�s�z / Sadece limitleri belirlemek i�in
    else if (mod == 1) { // D�� kenarl�k
        for (i=0; i<genislik; i++) printf("%c %c ", 254, 254); printf("%c\n", 254);
        for (i=0; i<yukseklik*2-1; i++) {
            printf("%c ", 254);
            for (j=0; j<2*genislik-1; j++) printf("  ");
            printf("%c\n", 254);
        }
        for (i=0; i<genislik; i++) printf("%c %c ", 254, 254); printf("%c\n", 254);
    }
    else { // �� kenarl�k
        for (i=0; i<=yukseklik; i++) {
            for (j=0; j<genislik; j++) printf("+ - "); printf("+\n");
            if (i==yukseklik) break;
            for (j=0; j<genislik; j++) printf("|   "); printf("|\n");
        }
    }
    tahtaGit(1,1);
}

void tahtaKontrol(const char tus, int mod) {
    // mod = 0: limit d���na hareket edilemez.
    // mod = 1: limit d���na hareket edildi�inde tersinden geri ��k�l�r.
    // mod = 2: limit d���na hareket edildi�inde z bi�imli hareket eder.
    tahtaGit(konumx, konumy);
    if (tus == 'w' || tus == 'W') {
        if (konumy > 1)
            tahtaGit(konumx, konumy-1);
        else if (mod == 0)
            tahtaGit(konumx, konumy);
        else if (mod == 1)
            tahtaGit(konumx, yukseklik);
        else if (mod == 2 && konumx < genislik)
            tahtaGit(konumx+1, yukseklik);
    }
    else if (tus == 's' || tus == 'S') {
        if (konumy < yukseklik)
            tahtaGit(konumx, konumy+1);
        else if (mod == 0)
            tahtaGit(konumx, konumy);
        else if (mod == 1)
            tahtaGit(konumx, 1);
        else if (mod == 2 && konumx > 1)
            tahtaGit(konumx-1, 1);
    }
    else if (tus == 'a' || tus == 'A') {
        if (konumx > 1)
            tahtaGit(konumx-1, konumy);
        else if (mod == 0)
            tahtaGit(konumx, konumy);
        else if (mod == 1)
            tahtaGit(genislik, konumy);
        else if (mod == 2 && konumy > 1)
            tahtaGit(genislik, konumy-1);
    }
    else if (tus == 'd' || tus == 'D') {
        if (konumx < genislik)
            tahtaGit(konumx+1, konumy);
        else if (mod == 0)
            tahtaGit(konumx, konumy);
        else if (mod == 1)
            tahtaGit(1, konumy);
        else if (mod == 2 && konumy < yukseklik)
            tahtaGit(1, konumy+1);
    }
}
#endif
