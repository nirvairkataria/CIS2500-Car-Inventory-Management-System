#include "../include/headerA3.h"

void printAll (struct car * headLL) {
    int count = 0;
    a3Car * curPosn = headLL;
    while (curPosn != NULL) {
        count++;

        // To print the number in string format with commas
        char priceHandler[11];
        char priceWithComma[11];
        sprintf(priceHandler, "%.2lf", curPosn->price);
        // Produces a comma for ranges 100,000.00 to 999,999.99
        if (strlen(priceHandler) == 9) {
            for (int i = 0; i < 10; i++) {
                if (i == 3) {
                    priceWithComma[i] = ',';
                } else if (i < 3) {
                    priceWithComma[i] = priceHandler[i];
                } else if (i > 3) {
                    priceWithComma[i] = priceHandler[i-1];
                }
            }
            priceWithComma[10] = '\0';
        // Produces a comma for ranges 10,000.00 to 99,999.99    
        } else if (strlen(priceHandler) == 8) {
            for (int i = 0; i < 9; i++) {
                if (i == 2) {
                    priceWithComma[i] = ',';
                } else if (i < 2) {
                    priceWithComma[i] = priceHandler[i];
                } else if (i > 2) {
                    priceWithComma[i] = priceHandler[i-1];
                }
            }
            priceWithComma[9] = '\0';
        // Produces a comma for ranges 1,000.00 to 9,999.99    
        } else if (strlen(priceHandler) == 7) {
            for (int i = 0; i < 8; i++) {
                if (i == 1) {
                    priceWithComma[i] = ',';
                } else if (i < 1) {
                    priceWithComma[i] = priceHandler[i];
                } else if (i > 1) {
                    priceWithComma[i] = priceHandler[i-1];
                }
            }
            priceWithComma[8] = '\0';
        // This price will not have a comma since it is less than 1000    
        } else if (strlen(priceHandler) < 7) {
            for (int i = 0; i < 7; i++) {
                priceWithComma[i] = priceHandler[i];
            }
            priceWithComma[7] = '\0';
        }

        printf("Car # %d:\n", count);
        printf("\tCar id: %d\n", curPosn->carId);
        printf("\tModel: %s\n", curPosn->model);
        printf("\tType: %s\n", curPosn->type);
        printf("\tPrice: CDN $%s\n", priceWithComma);
        printf("\tYear of Manufacture: %d\n", curPosn->year);

        curPosn = curPosn->nextCar;
    }
    printf("Currently, there are %d cars.\n", count);

}