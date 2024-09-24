#include "../include/headerA3.h"

void addNewCar (struct car ** headLL) {
    
    // create the space in memory for the new car
    a3Car *newCar = malloc(sizeof(a3Car));
    char modelHolder[MAX_LENGTH];
    char typeHolder[MAX_LENGTH];

    char lineDestroyer[10];

    // Takes user input for the car model 
    printf("Enter the car model: ");
    scanf("%c", lineDestroyer);
    fgets(modelHolder, MAX_LENGTH, stdin);
    modelHolder[strlen(modelHolder) - 1] = '\0';
    strcpy(newCar->model, modelHolder);

    // fgets(newCar->model, MAX_LENGTH, stdin);

    // Takes user input for the car type
    printf("Enter the car type: ");
    fgets(typeHolder, MAX_LENGTH, stdin);
    typeHolder[strlen(typeHolder) - 1] = '\0';
    strcpy(newCar->type, typeHolder);

    // fgets(newCar->type, MAX_LENGTH, stdin);

    // Saves the year when the car was manufactured
    printf("\nEnter its year of manufacture: ");
    scanf("%d", &newCar->year);

    // Saves the price of the car
    printf("Enter its price: CDN $ ");
    scanf("%lf", &newCar->price);

    // Sums up the ASCII values of the car's model which will be used for the carId
    int sum = 0;
    for (int i = 0; i < strlen(newCar->model); i++) {
        sum = (int) newCar->model[i] + sum;
    }

    // The carId is set to be the sum of the ASCII values and the string length of the car type
    newCar->carId = sum + strlen(newCar->type);

    a3Car *idCheck = *headLL;

    // This checks if the same id already exists on another car in the system
    while (idCheck != NULL) {
        // randomly generate a new carId from 1 to 999 if it already exists
        if (newCar->carId == idCheck->carId) {
            newCar->carId = newCar->carId + (rand() % 999 + 1);
            // set the idCheck back to the beginning, we must make sure the new id isn't the same as any other car as well
            idCheck = *headLL;
        } else {
            idCheck = idCheck->nextCar;
        }
    }
    
    printf("\nYour computer-generated carId is %d\n", newCar->carId);

    // set nextCar as NULL since this new added car is the last car in the linked list
    newCar->nextCar = NULL;
    
    // This struct pointer will traverse each car in the linked list
    a3Car *curPosn = *headLL;
  
    // Runs if there are no cars in the linked list, therefore add the new car as the first car
    if (*headLL == NULL) {
        *headLL = newCar;
        return;
    }

    // Keep iterating the linked list until we reach the last car
    while (curPosn->nextCar != NULL) {
        curPosn = curPosn->nextCar;
    }

    // The former last car's nextCar pointer now points to this new car, adding it to the end of the list
    curPosn->nextCar = newCar;
}