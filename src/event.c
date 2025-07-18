#include <time.h>
#include <string.h>
#include "../include/event.h"

Event createDefaultEvent() {
    Event e;

    time_t now = time(NULL);
    struct tm *t = localtime(now);

    memset(&e, 0, sizeof(Event));  // initialize all ints to 0, strings to ""

    e.year = t->tm_year + 1900;
    e.month = t->tm_mon +1;
    e.day = t->tm_mday;
    e.startHour = t->tm_hour;
    e.startMinute = t->tm_min;
    e.endHour = (t->tm_hour + 1) % 24;
    e.endMinute = t->tm_min;

    return e;
}