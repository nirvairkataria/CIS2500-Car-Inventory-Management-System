#include "../include/headerA3.h"

void oneLessCar (a3Car ** headLL, int whichOne) {
    // End the function because the user inputted an empty linked list
    if (*headLL == NULL) {
        printf("There is nothing in the linked list to remove.\n");
        return;
    }
    
    a3Car * carToRemove = *headLL;
    
    int lastCar = countCars(*headLL);

    // Case 1: Remove the first car in the linked list
    if (whichOne ==  1) {
        // PLEASE READ: while the instructions say to print the car id in main and not the function, the main cannot access the carid so during office hours Eason told me to print it in the function
        printf("Car [Id: %d] removed.\n", (*headLL)->carId);
        printf("There are now %d cars remaining.\n", (lastCar - 1));
        *headLL = (*headLL)->nextCar;
        free(carToRemove);
        
    } else if (whichOne == lastCar) {
        // Case 2: Remove the last car in the linked list
        while ((carToRemove->nextCar)->nextCar != NULL) {
            carToRemove = carToRemove->nextCar;
        }
        printf("Car [Id: %d] removed.\n", (carToRemove->nextCar)->carId);
        printf("There are now %d cars remaining.\n", (lastCar - 1));
        free(carToRemove->nextCar);
        carToRemove->nextCar = NULL;
        
    } else {
        // Case 3: Remove a car in the middle of the linked list
        for (int i = 1; i < (whichOne - 1); i++)  {
            carToRemove = carToRemove->nextCar;
        }
        printf("Car [Id: %d] removed.\n", (carToRemove->nextCar)->carId);
        printf("There are now %d cars remaining.\n", (lastCar - 1));
        free(carToRemove->nextCar);
        carToRemove->nextCar = (carToRemove->nextCar)->nextCar;
    }

}