#include "../include/eventManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialize empty manager

void initEventManager(EventManager *mgr) {
    mgr->events = NULL;
    mgr->count = 0;
    mgr->capacity = 0;
}

// free allocated memory in event manager
void freeEventManager(EventManager *mgr) {
    free(mgr->events);
    mgr->events = NULL;
    mgr->count = 0;
    mgr->capacity = 0;
}

// ensure there is enough space for new events
int ensureCapacity(EventManager *mgr, int minCapacity) {
    if (mgr->capacity >= minCapacity) return 1;

    int newCapacity = mgr->capacity == 0 ? 10 : mgr->capacity * 2;
    while (newCapacity < minCapacity) newCapacity *= 2;

    Event *newEvents = realloc(mgr->events, newCapacity * sizeof(Event));
    if (!newEvents) {
        perror("could not reallocate memory for events");
        return 0;
    }

    mgr->events = newEvents;
    mgr->capacity = newCapacity;
    return 1;
}

// make space for a new event
int addEvent(EventManager *mgr, Event newEvent) {
    if (!ensureCapacity(mgr, mgr->count + 1)) {
        fprintf(stderr, "failed to allocate memory for new event\n");
        return 0;
    }
    mgr->events[mgr->count++] = newEvent;

    return 1;
}
