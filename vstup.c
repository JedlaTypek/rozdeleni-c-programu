#include "vstup.h"

float zadaniPolomeru() {
    float r;
    float navratGetChar;
    int volba;

    do {
        printf("Chcete zadat polomer nebo prumer?\n");
        printf("1 - Polomer\n2 - Prumer\n");
        scanf("%d", &volba);

        navratGetChar = 0;
        while (getchar() != '\n') {
            navratGetChar++;
        }

        if (navratGetChar != 0 || volba < 1 || volba > 2) {
            printf("Napsal jsi spatnou moznost. Jako desetinou carku musis pouzit tecku.");
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
            }
        }
    } while (volba <= 0 || navratGetChar != 0);
    return r;
}
float zadaniStrany() {
    float strana;
    int navratGetChar;

    do {
        scanf("%f", &strana);
        if (strana <= 0) {
            printf("Strana nemuze byt zaporne cislo ani nula.");
        }

        navratGetChar = 0;
        while (getchar() != '\n') {
            navratGetChar++;
        }
    } while (strana <= 0 || navratGetChar != 0);
    return strana;
}