#include <stdio.h>
#include "../include/event.h"

void saveEventToFile(Event *e, const char *filename) {
    FILE *f = fopen(filename, "a");  // append to it

    if (!f) {
        perror("could not open file to save the event to");
        return;
    }

    fprintf(f, "%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
            e->name, e->category,
            e->year, e->month, e->day,
            e->startHour, e->startMinute,
            e->endHour, e->endMinute,
            e->hasTime, e->hasEndTime,
            e->isRecurring);
    fclose(f);
}