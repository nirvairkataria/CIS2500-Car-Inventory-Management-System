#include "../include/headerA3.h"

void noMoreCars (a3Car ** headLL) {
    char confirmation = 'z';
    
    // keep running until the user inputs n or y
    while (confirmation != 'n' && confirmation != 'y') {
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &confirmation);
        // user decided not to remove all car data, return to main
        if (confirmation == 'n') {
            return;
        } else if (confirmation == 'y') {
            while ((*headLL) != NULL) {
                a3Car * delete = *headLL;
                *headLL = (*headLL)->nextCar;
                free(delete);
            }
            free(*headLL);
            
            printf("All removed. Linked list is now empty.\n");
            return;
        } else {
            printf("That is not a valid option. Please try again.\n");
        }
    }
    
}