#include <stdio.h>
#include "../include/eventManager.h"

int deleteEvent(EventManager *mgr, int index) {
    if (index < 0 || index >= mgr->count) return 0; // invalid index

    for (int i = index; i < mgr->count -1; i++) mgr->events[i] = mgr->events[i+1]; // shift events left

    mgr->count--;

    return 1;
}