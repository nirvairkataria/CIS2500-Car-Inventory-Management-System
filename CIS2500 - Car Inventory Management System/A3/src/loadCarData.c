#include "../include/headerA3.h"

void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]) {
    
    FILE *fptr; 
    fptr = fopen(fileName, "r");
    
    if (fptr == NULL) {
        printf("failed to open file!\n");
    } else {
        while(!feof(fptr)) {
            // create the space in memory for the new car
            a3Car *newCar = calloc(1, sizeof(a3Car));
            
            char fileLine[200];
            char * split = strtok(fgets(fileLine, 200, fptr), ",");
            
            sscanf(split, "%d", &newCar->carId);
            // check if carid is unique
            a3Car *idCheck = *headLL;
            while (idCheck != NULL) {
                if (idCheck->carId == newCar->carId) {
                    newCar->carId = newCar->carId + (rand() % 999 + 1);
                    // set the idCheck back to the beginning, we must make sure the new id isn't the same as any other car as well
                    idCheck = *headLL;
                } else {
                    idCheck = idCheck->nextCar;
                }
            }

            // scan the car model
            split = strtok(NULL, ",");
            strcpy(newCar->model, split);

            // scan the car type
            split = strtok(NULL, ","); 
            strcpy(newCar->type, split);
            
            // scan the car's year of manufacture
            split = strtok(NULL, ",");
            sscanf(split, "%d", &newCar->year);

            // scan the car's price
            split = strtok(NULL, ",");
            sscanf(split, "%lf", &newCar->price); 

            // set nextCar as NULL since this new added car is the last car in the linked list
            newCar->nextCar = NULL;
            
            // This struct pointer will traverse each car in the linked list
            a3Car *curPosn = *headLL;
        
            // Runs if there are no cars in the linked list, therefore add the new car as the first car
            int keepGoing = 1;
            if (*headLL == NULL) {
                *headLL = newCar;
                keepGoing = 0;
            }

            // Keep iterating the linked list until we reach the last car
            if (keepGoing == 1) {
                while (curPosn->nextCar != NULL) {
                curPosn = curPosn->nextCar;
                }
                // The former last car's nextCar pointer now points to this new car, adding it to the end of the list
                curPosn->nextCar = newCar;
            }
        }
        
    } 
    fclose(fptr);
    
}