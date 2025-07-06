#include <stdio.h>
#include "../include/add.h"
#include "../include/event.h"
#include "../include/dateutils.h"

int main() {
    Event newEvent;

    printf("***** add new event *****\n");
    add(&newEvent);

    printf("\nyou just added: %s on %04d-%02d-%02d\n", newEvent.name,
           newEvent.year, newEvent.month, newEvent.day);

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

    return 0;
}
