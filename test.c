#include <stdio.h>
#include <conio.h>
#include "tahta.h"

main() {
    tahtaOlustur(10, 10, 2);
    tahtaGit(5, 3);
    while (1) {
        tahtaKontrol(getch(), 2);
    }
}
