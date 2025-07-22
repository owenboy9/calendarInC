#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/event.h"
#include "../include/eventManager.h"

int readEventsFromFile(EventManager *mgr, const char *filename) {
    
    FILE *f = fopen(filename, "r");
    if (!f) {
        // file doesn't exist — create it
        f = fopen(filename, "w");
        if (!f) {
            perror("failed to create events file");
            return 0;
        }
        fclose(f);
        // now open again for reading (will be empty)
        f = fopen(filename, "r");
        if (!f) {
            perror("failed to reopen events file");
            return 0;
        }
    }

    Event temp;
    int count = 0;

    while (fscanf(f, " %99[^|]|%99[^|]|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
            temp.name, temp.category,
            &temp.year, &temp.month, &temp.day,
            &temp.startHour, &temp.startMinute,
            &temp.endHour, &temp.endMinute,
            &temp.hasTime, &temp.hasEndTime,
            &temp.isRecurring,
            &temp.recurrenceCount, &temp.recurrenceInterval, &temp.recurrenceType) == 15) {
        if (!ensureCapacity(mgr, count + 1)) {
            fclose(f);
            return count;
        }

        mgr->events[count++] = temp;
    }


    fclose(f);

    mgr->count = count;
    return count;
}