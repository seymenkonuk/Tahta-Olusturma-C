/*
�mlecin Konumunu De�i�tirir
*/

#ifndef IMLEC_H
#define IMLEC_H
#include <windows.h>

void gotoxy(int x, int y); // imleci (x, y) koordinat�na g�t�r�r.

void gotoxy(int x, int y) {
     COORD coord;
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif
