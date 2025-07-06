#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/event.h"

void trimNewLine(char *str) {
    // remove newline from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] = '\0';
}

void add(Event *e) {
    char buffer [100];

    printf("enter event name: ");
    fgets(buffer, sizeof(buffer), stdin);
    trimNewLine(buffer);
    strncpy(e->name, buffer, sizeof(e->name) - 1);

    printf("enter event category: ");
    fgets(buffer, sizeof(buffer), stdin);
    trimNewLine(buffer);
    strncpy(e->category, buffer, sizeof(buffer) -1);

    printf("enter year: ");
    scanf("%d", &e->year);

    printf("enter month (1-12): ");
    scanf("%d", &e->month);

    printf("enter day (1-31): ");
    scanf("%d", &e->day);

    printf("is this a timed event? (0 = all day, 1 = yes): ");
    scanf("%d", &e->hasTime);

    if(e->hasTime) {
        printf("start hour (0-23): ");
        scanf("%d", &e->startHour);
        printf("start minute (0-59): ");
        scanf("%d", &e->startMinute);

        printf("does it have an end time? (0 = no, 1 = yes): ");
        scanf("%d", &e->hasEndTime);

        if (e->hasEndTime) {
            printf("end hour (0-23): ");
            scanf("%d", &e->endHour);
            printf("end minute (0-59): ");
            scanf("%d", &e->endMinute);
        } else {
            // default one hour later
            e->endHour = (e->startHour + 1) % 24;
            e->endMinute = e->startMinute;
        }
    } else {
        // no time for all day events
        e->startHour = e->startMinute = 0;
        e->endHour = e->endMinute = 0;
        e->hasEndTime = 0;
    }
    printf("is this a recurring event? (0 = no, 1 = yes): ");
    scanf("%d", &e->isRecurring);

    if(e->isRecurring) {
        printf("recurrence type (0 = days, 1 = weeks, 2 = months, 3 = years): ");
        scanf("%d", &e->recurrenceType);

        printf("how many times do you want to repeat it? ");
        scanf("%d", &e->recurrenceCount);

        printf("interval between occurences (e.g., every 2 weeks): ");
        scanf("%d", &e->recurrenceInterval);
    } else {
        e->recurrenceType = 0; // default to days
        e->recurrenceCount = 0; // no recurrence
        e->recurrenceInterval = 0; // no interval
    }

    // clear stdin buffer (in case it's needed for next fgets)
    while (getchar() != '\n');
}