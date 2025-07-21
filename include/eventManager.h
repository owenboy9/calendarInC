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

// free allocated memory in event manager
void freeEventManager(EventManager *mgr);

// load events from file, update count and capacity
int loadEvents(EventManager *mgr, const char *filename);

// save events to file
int saveEvents(EventManager *mgr, const char *filename);

// add a new event (dynamic resizing)
int addEvent(EventManager *mgr, Event newEvent);

// delete event by index
int deleteEvent(EventManager *mgr, int index);

// edit event at index
void editEvent(EventManager *mgr, int index);

#endif // EVENTMANAGER_H