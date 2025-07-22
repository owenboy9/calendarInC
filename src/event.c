#include "../include/event.h"
#include <string.h>
#include <time.h>

Event createDefaultEvent() {
    Event e;

    // Clear strings
    memset(e.name, 0, sizeof(e.name));
    memset(e.category, 0, sizeof(e.category));

    // Default: today
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    e.year = t->tm_year + 1900;
    e.month = t->tm_mon + 1;
    e.day = t->tm_mday;

    // Clear time info
    e.startHour = 0;
    e.startMinute = 0;
    e.endHour = 0;
    e.endMinute = 0;
    e.hasTime = 0;
    e.hasEndTime = 0;

    // No recurrence by default
    e.isRecurring = 0;
    e.recurrenceType = 0;
    e.recurrenceCount = 0;
    e.recurrenceInterval = 0;

    return e;
}
