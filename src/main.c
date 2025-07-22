#include <stdio.h>
#include "../include/event.h"
#include "../include/dateutils.h"
#include "../include/saveToFile.h"
#include "../include/eventManager.h"
#include "../include/ui.h"
#include "../include/readFromFile.h"

int main() {
    EventManager mgr;
    initEventManager(&mgr);
    readEventsFromFile(&mgr, "calendar.txt");
    showMainMenu(&mgr);
    writeAllEventsToFile(&mgr, "calendar.txt");
    freeEventManager(&mgr);

    /*
    if (newEvent.hasTime) {
        printf("starts at: %02d:%02d\n", newEvent.startHour, newEvent.startMinute);
        if (newEvent.hasEndTime) {
            printf("ends at: %02d:%02d\n", newEvent.endHour, newEvent.endMinute);
        } else {
            printf("lasts all day!\n");
        }
    }

    if (newEvent.isRecurring) {
        printf("all of its occurences are:\n");
        weekday(newEvent.year, newEvent.month, newEvent.day,
               newEvent.recurrenceType, newEvent.recurrenceInterval, newEvent.recurrenceCount);
    }

    saveEventToFile(&newEvent, "calendar.txt");
    */

    return 0;
}
