#include "../include/edit.h"
#include <stdio.h>

int deleteEvent(Event *events, int *count, int indexToDelete) {
    if (indexToDelete < 0 || indexToDelete >= *count) {
        printf("invalid index\n");
        return 0;
    }

    // shift events down to overwrite the one being deleted
    for (int i = indexToDelete; i < *count -1; i++) {
        events[i] = events[i+1];
    }

    (*count)--;  // reduce event count
    return 1;
}