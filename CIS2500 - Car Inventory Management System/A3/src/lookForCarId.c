#include "../include/headerA3.h"

int lookForCarId (struct car * headLL, int key) {
    int count = 0;
    a3Car * curPosn = headLL;

    while (curPosn != NULL) {
        count++;
        if (curPosn->carId == key) {
            // the matching carId has been found, return the position in the linked list back to main
            return count;
        } else {
            curPosn = curPosn->nextCar;
        }
    }

    // if loop was not satisfied, then the function will return -1
    return -1;
}