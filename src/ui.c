#include "../include/event.h"
#include "../include/sort.h"
#include "../include/readFromFile.h"
#include "../include/eventManager.h"
#include "../include/search.h"
#include "../include/menu.h"
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

void handleSearch(EventManager *mgr) {
    char term[100];
    int choice;

    const char *options[] = {
        "search by name",
        "search by category",
        "search by year",
        "search by month",
        "search by day",
        "back to main menu"
    };

    choice = arrowMenu("search options", options, 6);

    switch (choice) {
        case 0:
            promptString("enter event name", term, sizeof(term), 0);
            searchByString(mgr, term, "name");
            break;
        case 1:
        promptString("enter event category", term, sizeof(term), 0);
            searchByString(mgr, term, "category");
            break;
        case 2:
            promptInt("enter year", &choice, 0);
            searchByInt(mgr, choice, "year");
            break;
        case 3:
            promptInt("enter month (1-12)", &choice, 0);
            searchByInt(mgr, choice, "month");
            break;
        case 4:
            promptInt("enter day (1-31)", &choice, 0);
            searchByInt(mgr, choice, "day");
            break;
        default:
            return; // back to main menu
    }
}