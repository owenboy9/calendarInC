#include "../include/event.h"
#include "../include/inpututils.h"
#include "../include/eventManager.h"
#include <stdio.h>

void editEvent(EventManager *mgr, int index) {

    if (index < 0 || index >= mgr->count) {
        printf("invalid index\n");
        return;
    }

    Event *e = &mgr->events[index];

    printf("edit event: %s\n(leave blank to keep the current value)\n", e->name);

    promptString("new name", e->name, NAME_SIZE, 1);
    promptString("new category", e->category, CATEGORY_SIZE, 1);
    promptInt("new year", &e->year, 1);
    promptInt("new month (1-12)", &e->month, 1);
    promptInt("new day (1-31)", &e->day, 1);
    promptInt("is this a timed event? (0 = all day, 1 = timed)", &e->hasTime, 1);

    if (e->hasTime) {
        promptInt("start hour (0-23)", &e->startHour, 1);
        promptInt("start minute (0-59)", &e->startMinute, 1);
        promptInt("does it have end time? (0 = no, 1 = yes)", & e->hasEndTime, 1);

        if (e->hasEndTime) {
            promptInt("end hour (0-23)", &e->endHour, 1);
            promptInt("end minute (0-59)", &e->endMinute, 1);
        }
    }

    promptInt("is this a recurring event? (0 = no, 1 = yes)", &e->isRecurring, 1);
    if (e->isRecurring) {
        promptInt("recurrence type (0 = days, 1 = weeks, 2 = months, 3 = years)", &e->recurrenceType, 1);
        promptInt("every... days / weeks, etc?", &e->recurrenceInterval, 1);
        promptInt("how many times?", &e->recurrenceCount, 1);
    }
}