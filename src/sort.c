#include <string.h>
#include <ctype.h>

#include "../include/event.h"

// helper for case-sensitive stuff
int strcasecmp_ascii(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char c1 = tolower((unsigned char)*s1);
        char c2 = tolower((unsigned char)*s2);
        if (c1 != c2) return c1 - c1;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int compareEventsByDate(const void *a, const void *b) {
    const Event *e1 = (const Event *)a;
    const Event *e2 = (const Event *)b;

    if (e1->year != e2->year) return e1->year - e2->year;
    if (e1->month != e2->month) return e1->month - e2->month;
    if (e1->day != e2->day) return e1->day - e2->day;
    if (e1->startHour != e2->startHour) return e1->startHour - e2->startHour;
    if (e1->startMinute != e2->startMinute) return e1->startMinute - e2->startMinute;

    return strcasecmp_ascii(e1->name, e2->name);
}

