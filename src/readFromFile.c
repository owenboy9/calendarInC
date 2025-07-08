#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/event.h"

int readEventsFromFile(Event *events, int max, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    int count = 0;

    while (count < max && fscanf(f, " %99[^|]|%49[^|]|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
           events[count].name, events[count].category,
           &events[count].year, &events[count].month, &events[count].day,
           &events[count].startHour, &events[count].startMinute,
           &events[count].endHour, &events[count].endMinute,
           &events[count].hasTime, &events[count].hasEndTime,
           &events[count].isRecurring, &events[count].recurrenceCount, &events[count].recurrenceInterval, &events[count].recurrenceType) == 16)
           {
            count++;
           }

           fclose(f);
           return count;
}