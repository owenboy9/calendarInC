#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/event.h"
#include "../include/eventManager.h"

void createEventFromUserInput(Event *e) {

    printf("add a new event");

    *e = createDefaultEvent();    

    promptString("name", e->name, NAME_SIZE, 0);
    promptString("category", e->category, CATEGORY_SIZE, 0);
    promptInt("year", &e->year, 0);
    promptInt("month (1-12)", &e->month, 0);
    promptInt("day (1-31)", &e->day, 0);
    promptInt("is this a timed event? (0 = all day, 1 = timed)", &e->hasTime, 0);

    if (e->hasTime) {
        promptInt("start hour (0-23)", &e->startHour, 0);
        promptInt("start minute (0-59)", &e->startMinute, 0);
        promptInt("does it have end time? (0 = no, 1 = yes)", & e->hasEndTime, 0);

        if (e->hasEndTime) {
            promptInt("end hour (0-23)", &e->endHour, 0);
            promptInt("end minute (0-59)", &e->endMinute, 0);
        }
    }

    promptInt("is this a recurring event? (0 = no, 1 = yes)", &e->isRecurring, 0);
    if (e->isRecurring) {
        promptInt("recurrence type (0 = days, 1 = weeks, 2 = months, 3 = years)", &e->recurrenceType, 0);
        promptInt("every... days / weeks, etc?", &e->recurrenceInterval, 0);
        promptInt("how many times?", &e->recurrenceCount, 0);
    }
    
}