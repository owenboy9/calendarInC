#ifndef SAVE_TO_FILE_H
#define SAVE_TO_FILE_H

#include "event.h"
#include "eventManager.h"

void writeAllEventsToFile(const EventManager *mgr, const char *filename);

#endif