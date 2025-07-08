#ifndef SAVE_TO_FILE_H
#define SAVE_TO_FILE

#include "event.h"

void saveEventToFile(Event *e, const char *filename);
void writeAllEventsToFile(Event *events, int count, const char *filename);

#endif