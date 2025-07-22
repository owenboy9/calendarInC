#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/event.h"
#include "../include/sort.h"
#include "../include/eventManager.h"

// make sure all is lower case
void toLowerStr(char *dest, const char *src, size_t maxLen) {
    size_t i;
    for (i = 0; i < maxLen - 1 && src[i]; i++) {
        dest[i] = tolower((unsigned char)src[i]);
    }
    dest[i] = '\0';  // terminate *right after* last character copied
}


// rewriting the whole file after editing or deleting something
int writeAllEventsToFile(const EventManager *mgr, const char *filename) {
    FILE *f = fopen(filename, "w");  // overwrite the whole thing
    if (!f) return 0;

    // sort events before writing

    qsort(mgr->events, mgr->count, sizeof(Event), compareEventsByDate);

    for (int i = 0; i < mgr->count; i++) {
        Event *e = &mgr->events[i];
        char nameLower[100];
        char categoryLower[100];
        toLowerStr(nameLower, e->name, sizeof(nameLower));
        toLowerStr(categoryLower, e->category, sizeof(categoryLower));

        fprintf(f, "%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
            nameLower, categoryLower,
            e->year, e->month, e->day,
            e->startHour, e->startMinute,
            e->endHour, e->endMinute,
            e->hasTime, e->hasEndTime,
            e->isRecurring,
            e->recurrenceCount, e->recurrenceInterval, e->recurrenceType);
    }
    
    fclose(f);
    return 1;
}