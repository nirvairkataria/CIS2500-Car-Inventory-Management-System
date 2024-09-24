#include "../include/headerA3.h"

int countCars (a3Car * headLL) {
    int count = 0;
    a3Car * curPosn = headLL;
    // For each node we pass through, increment the count variable
    while (curPosn != NULL) {
        count++;
        curPosn = curPosn->nextCar;
    }
    
    return count;
}
