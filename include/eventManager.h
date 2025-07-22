#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "event.h"

typedef struct {
    Event *events;  // pointer to an array of events
    int count;      // number of events read from file on start
    int capacity;   // dynamically allocated size of the events array
} EventManager;

// initialize event manager
void initEventManager(EventManager *mgr);

// ensure there is enough space for new events (private)
int ensureCapacity(EventManager *mgr, int minCapacity);

// free allocated memory in event manager
void freeEventManager(EventManager *mgr);

// add a new event (dynamic resizing)
int addEvent(EventManager *mgr, Event newEvent);

#endif // EVENTMANAGER_H