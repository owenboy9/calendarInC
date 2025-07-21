#include "../include/event.h"
#include "../include/sort.h"
#include "../include/readFromFile.h"
#include <stdlib.h>

const int MAX_EVENTS = 1000; // Maximum number of events to read

void listEvents(Event *events, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s  *  %s  * %d/%d/%d\n", events[i].name, events[i].category,
               events[i].day, events[i].month, events[i].year);
        if (events[i].hasTime) {
            printf("@ %02d:%02d", events[i].startHour, events[i].startMinute);
            if (events[i].hasEndTime) {
                printf(" - %02d:%02d", events[i].endHour, events[i].endMinute);
            }
            printf("\n");
        }
    }
}

void handleViewCalendar(Event *events, int *count, const char *filename) {
    *count = readEventsFromFile(events, MAX_EVENTS, filename);
    qsort(events, *count, sizeof(Event), compareEventsByDate);
    listEvents(events, *count);
}


