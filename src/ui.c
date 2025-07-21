#include "../include/event.h"
#include "../include/sort.h"
#include "../include/readFromFile.h"
#include "../include/eventManager.h"
#include <stdlib.h>

const int MAX_EVENTS = 1000; // Maximum number of events to read

void listEvents(EventManager *mgr) {
    for (int i = 0; i < mgr->count; i++) {
        printf("%s  *  %s  * %d/%d/%d\n", mgr->events[i].name, mgr->events[i].category,
               mgr->events[i].day, mgr->events[i].month, mgr->events[i].year);
        if (mgr->events[i].hasTime) {
            printf("@ %02d:%02d", mgr->events[i].startHour, mgr->events[i].startMinute);
            if (mgr->events[i].hasEndTime) {
                printf(" - %02d:%02d", mgr->events[i].endHour, mgr->events[i].endMinute);
            }
            printf("\n");
        }
    }
}

void handleViewCalendar(EventManager *mgr, const char *filename) {
    readEventsFromFile(mgr, filename);
    qsort(mgr->events, mgr->count, sizeof(Event), compareEventsByDate);
    listEvents(mgr);
}