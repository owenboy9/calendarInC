#include "../include/event.h"
#include "../include/eventManager.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// search by name or category

int searchByString(EventManager *mgr, const char *term, const char *field) {
    int found = 0;
    for (int i = 0; i < mgr->count; i++) {
        const char *value = NULL;
        if (strcmp(field, "name") == 0) value = mgr->events[i].name;
        else if (strcmp(field, "category") == 0) value = mgr->events[i].category;

        if (value&& strstr(value, term)) {
            // match found
            printf("%s (%s) on %02d-%02d-%04d\n", mgr->events[i].name, mgr->events[i].category, mgr->events[i].day, mgr->events[i].month, mgr->events[i].year);
            found++;
        }
    }
    return found;
}

int searchByInt(EventManager *mgr, int value, const char *field) {
    int found = 0;
    for (int i = 0; i < mgr->count; i++) {
        int match = 0;
        if (strcmp(field, "year") == 0 && mgr->events[i].year == value) match = 1;
        else if (strcmp(field, "month") == 0 && mgr->events[i].month == value) match = 1;
        else if (strcmp(field, "day") == 0 && mgr->events[i].day == value) match = 1;

        if (match) {
            printf("%s (%s) on %02d-%02d-%04d\n", mgr->events[i].name, mgr->events[i].category, mgr->events[i].day, mgr->events[i].month, mgr->events[i].year);

            found++;
        }
    }

    return found;
}