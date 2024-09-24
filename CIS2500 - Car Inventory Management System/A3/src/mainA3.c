#include "../include/headerA3.h"

int main() {
    int choice = -1;
    a3Car *userCarHead = NULL; 
    char userFile[MAX_LENGTH] = "inputFile.txt";
    // for function 3
    int userNodeSelection;

    // for function 5
    int userCarId;

    // for function 6
    char userCarInfo[100];

    // for function 9
    int userCarRemoval;

    while (choice != 11) {
        printf("1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");
        printf("Choose menu option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addNewCar(&userCarHead);
        }

        if (choice == 2) {
            loadCarData(&userCarHead, userFile);
        }
        
        if (choice == 3) {
           printAll(userCarHead);
        }
        
        if (choice == 4) {
            printf("Enter a position: ");
            scanf("%d", &userNodeSelection);

            int posnValidation = countCars(userCarHead);

            while (userNodeSelection > posnValidation || userNodeSelection <= 0) {
                if (userNodeSelection > posnValidation) {
                    printf("There are only %d cars in the list. Please choose a number in the range 1 to %d: ", posnValidation, posnValidation);
                } else if (userNodeSelection <= 0) {
                    printf("0 or any negative value is not a valid listing. Please choose a number in the range 1 to %d: ", posnValidation);
                }
                scanf("%d", &userNodeSelection);
            }
            printOne(userCarHead, userNodeSelection);
        }
        
        if (choice == 5) {
            printf("Enter a car ID: ");
            scanf("%d", &userCarId);
            int returnedPosn = lookForCarId(userCarHead, userCarId);
            if (returnedPosn != -1) {
                printOne(userCarHead, returnedPosn);
            } else {
                printf("The car id was not found in the linked list!\n");
            }
        }
        
        if (choice == 6) {
            printf("Enter the model and type (separated by a space): ");
            char errorHolder[10];
            scanf("%c", errorHolder);
            fgets(userCarInfo, 100, stdin);
            int returnedPosn = lookForCarModelType(userCarHead, userCarInfo);
            if (returnedPosn != -1) {
                printOne(userCarHead, returnedPosn);
            } else {
                printf("The car model and type were not found in the linked list!\n");
            }
        }
        
        if (choice == 7) {
            int carCount = countCars(userCarHead);
            printf("Total number of cars = %d\n", carCount);
        }

        if (choice == 8) {
            sortCarId(&userCarHead);
            printAll(userCarHead);
        }
        
        if (choice == 9) {
            int currentCars = countCars(userCarHead);
            printf("Currently there are %d cars.\n", currentCars);
            if (currentCars != 0) {
                printf("Which car do you wish to remove -- enter a value between 1 and %d: ", currentCars);
                scanf("%d", &userCarRemoval);
                while (userCarRemoval <= 0 || userCarRemoval > currentCars) {
                    printf("There are only %d cars in the list. Please enter a valid number from 1 to %d: ", currentCars, currentCars);
                    scanf("%d", &userCarRemoval);
                }
                oneLessCar(&userCarHead, userCarRemoval);
            } else {
                printf("There are no cars to remove\n");
            }
        }
        
        if (choice == 10) {
            noMoreCars(&userCarHead);
        }

        if (choice == 11){
            printf("Exiting\n");
            
            a3Car * holder;
            while (userCarHead != NULL) {
                holder = userCarHead;
                userCarHead = userCarHead->nextCar;
                free(holder);
            }
            free(userCarHead);
        }

        if (choice < 1 || choice > 11) {
            printf("That is not a valid option, please try again.\n");
        }
    }


    
}