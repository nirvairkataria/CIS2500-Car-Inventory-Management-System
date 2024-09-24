#include "../include/headerA3.h"

//  NEED TO FIX THIS FUNCTION, COMBINE THE TWO STRINGS INSTEAD OF STRTOK'ING IT.
int lookForCarModelType (struct car * headLL, char key [100]) {
    int count = 0;
    a3Car * curPosn = headLL;
    char carInformation[100];
    int removeNewLine = strlen(key);
    key[removeNewLine - 1] = '\0';
    
    while (curPosn != NULL) {
        count++;
        strcpy(carInformation, curPosn->model);
        strcat(carInformation, " ");
        strcat(carInformation, curPosn->type);

        if (strcmp(carInformation, key) == 0) {
            return count;
        } else {
            curPosn = curPosn->nextCar;
        }

        /*
        char split[] = " ";
        char * firstHalf;
        char * secondHalf;

        firstHalf = strtok(key, split);
        secondHalf = strtok(NULL, split);

        if (strcmp(firstHalf, curPosn->model) == 0 && strcmp(secondHalf, curPosn->type) == 0) {
            return count;
        }
        */
    }
    return -1;
}