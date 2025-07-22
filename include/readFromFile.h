#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include "event.h"
#include "eventManager.h"

int readEventsFromFile(EventManager *mgr, const char *filename);

#endif