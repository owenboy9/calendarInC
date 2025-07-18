#include "../include/event.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// search by name or category

int searchByString(Event *events, int count, const char *term, const char *field) {
    int found = 0;
    for (int i =0; i < count; i++) {
        const char *value = NULL;
        if (strcmp(field, "name") == 0) value = events[i].name;
        else if (strcmp(field, "category") == 0) value = events[i].category;

        if (value&& strstr(value, term)) {
            // match found
            printf("%s (%s) on %02d-%02d-%04d\n", events[i].name, events[i].category, events[i].day, events[i].month, events[i].year);
            found++;
        }
    }
    return found;
}

int searchByInt(Event *events, int count, int value, const char *field) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        int match = 0;
        if (strcmp(field, "year") == 0 && events[i].year == value) match = 1;
        else if (strcmp(field, "month") == 0 && events[i].month == value) match = 1;
        else if (strcmp(field, "day") == 0 && events[i].day == value) match = 1;

        if (match) {
            printf("%s (%s) on %02d-%02d-%04d\n", events[i].name, events[i].category, events[i].day, events[i].month, events[i].year);
            
            found++;
        }
    }

    return found;
}