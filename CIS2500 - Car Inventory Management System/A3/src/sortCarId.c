#include "../include/headerA3.h"

void sortCarId (struct car ** headLL) {
    int numOfCars = countCars(*headLL);
    int arrOfIds[numOfCars];
    char arrOfCarModels[numOfCars][MAX_LENGTH];
    char arrOfCarTypes[numOfCars][MAX_LENGTH];
    double arrOfPrices[numOfCars];
    int arrOfYears[numOfCars];

    a3Car *curPosn = *headLL;

    // Store all the carIds in the linked list in the array defined below
    for (int i = 0; i < numOfCars; i++) {
        arrOfIds[i] = curPosn->carId;
        strcpy(arrOfCarModels[i], curPosn->model);
        strcpy(arrOfCarTypes[i], curPosn->type);
        arrOfPrices[i] = curPosn->price;
        arrOfYears[i] = curPosn->year;
        curPosn = curPosn->nextCar;
    }

    // Sort the array
    int idHolder;
    char carModelHolder[100];
    char carTypesHolder[100];
    double priceHolder;
    int yearHolder;

    // Apply the sophisticated bubble sort algorithm to our lovely cars
    for (int i = 0; i < numOfCars - 1; i++) {
        for (int j = 0; j < numOfCars - i - 1; j++) {
            if (arrOfIds[j] > arrOfIds[j+1]) {
                idHolder = arrOfIds[j];
                arrOfIds[j] = arrOfIds[j+1];
                arrOfIds[j+1] = idHolder;

                strcpy(carModelHolder, arrOfCarModels[j]);
                strcpy(arrOfCarModels[j], arrOfCarModels[j+1]);
                strcpy(arrOfCarModels[j+1], carModelHolder);

                strcpy(carTypesHolder, arrOfCarTypes[j]);
                strcpy(arrOfCarTypes[j], arrOfCarTypes[j+1]);
                strcpy(arrOfCarTypes[j+1], carTypesHolder);

                priceHolder = arrOfPrices[j];
                arrOfPrices[j] = arrOfPrices[j+1];
                arrOfPrices[j+1] = priceHolder;

                yearHolder = arrOfYears[j];
                arrOfYears[j] = arrOfYears[j+1];
                arrOfYears[j+1] = yearHolder;
            }
        }
    }

    curPosn = *headLL;
    for (int i = 0; i < numOfCars; i++) {
        curPosn->carId = arrOfIds[i];
        strcpy(curPosn->model, arrOfCarModels[i]);
        strcpy(curPosn->type, arrOfCarTypes[i]);
        curPosn->price = arrOfPrices[i];
        curPosn->year = arrOfYears[i];
        curPosn = curPosn->nextCar;
    }

}