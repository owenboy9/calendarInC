#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/event.h"

// make sure all is lower case
void toLowerStr(char *dest, const char *src, size_t maxLen) {
    for (size_t i = 0; i < maxLen - 1 && src[i]; i++) {
        dest[i] = tolower((unsigned char)src[i]);
    }
    dest[maxLen - 1] = '\0';  // ensure null-termination
}


// adding a single event
void saveEventToFile(Event *e, const char *filename) {
    FILE *f = fopen(filename, "a");  // append to it

    if (!f) {
        perror("could not open file to save the event to");
        return;
    }

    char nameLower[100];
    char categoryLower[100];
    toLowerStr(nameLower, e->name, sizeof(nameLower));
    toLowerStr(categoryLower, e->category, sizeof(categoryLower));

    fprintf(f, "%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
            nameLower, categoryLower,
            e->year, e->month, e->day,
            e->startHour, e->startMinute,
            e->endHour, e->endMinute,
            e->hasTime, e->hasEndTime,
            e->isRecurring, e->recurrenceCount, e->recurrenceInterval, e->recurrenceType);
    fclose(f);
}

// rewriting the whole file after editing or deleting something
void writeAllEventsToFile(Event *events, int count, const char *filename) {
    FILE *f = fopen(filename, "w");  // overwrite the whole thing
    if (!f) {
        perror("couldn't write events to file");
        return;
    }

    for (int i = 0; i < count; i++) {
        char nameLower[100];
        char categoryLower[100];
        toLowerStr(nameLower, events[i].name, sizeof(nameLower));
        toLowerStr(categoryLower, events[i].category, sizeof(categoryLower));

        fprintf(f, "%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
            nameLower, categoryLower,
            events[i].year, events[i].month, events[i].day,
            events[i].startHour, events[i].startMinute,
            events[i].endHour, events[i].endMinute,
            events[i].hasTime, events[i].hasEndTime,
            events[i].isRecurring,
            events[i].recurrenceCount, events[i].recurrenceInterval, events[i].recurrenceType);
    }
    
    fclose(f);
}