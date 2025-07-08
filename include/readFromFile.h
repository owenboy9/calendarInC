#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include "event.h"

int readEventsFromFile(Event *events, int max, const char *filename);

#endif