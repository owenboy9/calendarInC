#include "../include/event.h"
#include "../include/inpututils.h"
#include <stdio.h>

void editEvent(Event *events, int count, int indexToEdit) {

    if (indexToEdit < 0 || indexToEdit >= count) {
        printf("invalid index\n");
        return;
    }

    Event *e = &events[indexToEdit];

    printf("edit event: %s\n(leave blank to keep the current value)\n", e->name);

    promptString("new name", e->name, NAME_SIZE);
    promptString("new category", e->category, CATEGORY_SIZE);
    promptInt("new year", &e->year);
    promptInt("new month (1-12)", &e->month);
    promptInt("new day (1-31)", &e->day);
    promptInt("is this a timed event? (0 = all day, 1 = timed)", &e->hasTime);

    if (e->hasTime) {
        promptInt("start hour (0-23)", &e->startHour);
        promptInt("start minute (0-59)", &e->startMinute);
        promptInt("does it have end time? (0 = no, 1 = yes)", & e->hasEndTime);

        if (e->hasEndTime) {
            promptInt("end hour (0-23)", &e->endHour);
            promptInt("end minute (0-59)", &e->endMinute);
        }
    }

    promptInt("is this a recurring event? (0 = no, 1 = yes)", &e->isRecurring);
    if (e->isRecurring) {
        promptInt("recurrence type (0 = days, 1 = weeks, 2 = months, 3 = years)", &e->recurrenceType);
        promptInt("every... days / weeks, etc?", &e->recurrenceInterval);
        promptInt("how many times?", &e->recurrenceCount);
    }
}