
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include "vstup.h"
int main() {
    float a;
    float b;
    float c;
    char strana;
    float vyska;
    float r;
    float obvod;
    float obsah;
    float objem;
    float povrch;
    int volba;
    int navratGetChar;

    printf("Vitejte v programu na obvodu, obsahu, objemu a povrchu teles a tvaru.\nPro ukonceni programu zadejte kamkoli nulu.\nJako desetinou carku pouzivej tecku!\n");

    do {
        printf("1 - Trojuhelnik\n2 - Ctverec\n3 - Obdelnik\n4 - Kruh\n5 - Krychle\n6 - Kvadr\n7 - Valec\n8 - Jehlan\n9 - Kuzel\n10 - Koule\n\n");
        printf("Vyber tvar:");
        scanf("%d", &volba);

        switch (volba) {
            case 1:
                printf("Trojuhelnik:");
                printf("Zadej stranu a:");
                a = zadaniStrany();
                printf("Zadej stranu b:");
                b = zadaniStrany();
                printf("Zadej stranu c:");
                c = zadaniStrany();
                printf("Zadej vysku:");
                vyska = zadaniStrany();

                printf("Na kterou stranu byla vyska?:");
                scanf("%c", &strana);


                while (getchar() != '\n') {
                    navratGetChar++;
                }

                if (navratGetChar == 0 && (strana == 'a' || strana == 'b' || strana == 'c')) {
                    obvod = a + b + c;
                    switch (strana) {
                        case 'a':
                            obsah = (a * vyska) / 2.0;
                            break;

                        case 'b':
                            obsah = (b * vyska) / 2.0;
                            break;

                        case 'c':
                            obsah = (c * vyska) / 2.0;
                    }
                    printf("Obvod: %.2f cm\n", obvod);
                    printf("Obsah: %.2f cm ctverecnich\n", obsah);
                } else {
                    printf("Zadal jsi spatnou stranu.\n");
                }

                break;
            case 2:
                printf("Ctverec:");
                printf("Zadej v cm stranu a:");
                a = zadaniStrany();

                obvod = 4.0 * a;
                obsah = a * a;

                printf("Obvod: %.2f cm\nObsah: %.2f cm ctverecnich", obvod, obsah);
                break;
            case 3:
                printf("Obdelnik:");
                printf("Zadej v cm stranu a:");
                a = zadaniStrany();
                printf("Zadej v cm stranu b:");
                b = zadaniStrany();

                obvod = 2 * (a + b);
                obsah = a * b;

                printf("Obvod: %.2f cm\nObsah: %.2f cm ctverecnich", obvod, obsah);
                break;
            case 4:
                printf("Kruh:");
                r = zadaniPolomeru();
                obvod = 2 * M_PI * r;
                obsah = M_PI * pow(r, 2);

                printf("Obvod: %.2f cm\nObsah: %.2f cm ctverecnich\n", obvod, obsah);
                break;
            case 5:
                printf("Krychle:");
                printf("Zadej stranu a:");
                a = zadaniStrany();
                povrch = 6.0 * pow(a, 2);
                objem = pow(a, 3);

                printf("Povsrch: %.2f cm ctverecnich\nObjem: %.2f cm krychlovych", povrch, objem);
                break;
            case 6:
                printf("Kvadr:");
                break;
            case 7:
                printf("Valec:");
                break;
            case 8:
                printf("Jehlan:");
                break;
            case 9:
                printf("Kuzel:");
                break;
            case 10:
                printf("Koule:");
                printf("Chcete zadat polomer nebo prumer?\n");
                printf("1 - Polomer\n2 - Prumer\n");
                scanf("%d", &volba);

                navratGetChar = 0;
                while (getchar() != '\n') {
                    navratGetChar++;
                }

                if (navratGetChar != 0 || volba < 1 || volba > 2) {
                    printf("Napsal jsi spatnou moznost.");
                } else if (volba == 0) {
                    return 0;
                } else {
                    printf("Zadejte hodnotu v centimetrech:\n");
                    scanf("%f", &r);

                    navratGetChar = 0;
                    while (getchar() != '\n') {
                        navratGetChar++;
                    }

                    if (navratGetChar != 0) {
                        printf("Napsal jsi spatne polomer.");
                    } else if (r <= 0) {
                        printf("Polomer nemuze byt zaporne cislo.");
                    } else {
                        if (volba == 2) {
                            r = r / 2.0;
                        }
                        objem = 4.0 / 3.0 * M_PI * r * r * r;
                        povrch = 4 * M_PI * pow(r, 2);

                        printf("Objem: %f centimetru krychlovych\n", objem);
                        printf("Povrch: %f centimetru ctverecnich\n", povrch);
                    }
                }
                printf("\n");
                break;
            default:
                printf("Chybna volba.");


        }
    }while (volba != 0);


return 0;
}