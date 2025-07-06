#ifndef EVENT_H
#define EVENT_H

typedef struct {
    char name[100];
    char category[50];
    int year, month, day;
    int startHour, startMinute;
    int endHour, endMinute;
    int hasTime;  // 0 = all day, 1 = timed event
    int hasEndTime; // 0 = no end time, 1 = has end time
    int isRecurring; // 0 = not recurring, 1 = recurring
    int recurrenceType; // 0 = days, 1 = weeks, 2 = months, 3 = years
    int recurrenceCount; // Number of occurrences for recurring events
    int recurrenceInterval; // Interval for recurrence (e.g., every 2 weeks)
} Event;

#endif