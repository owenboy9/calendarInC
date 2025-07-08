#ifndef SEACH_H
#define SEARCH_H

#include "event.h"

int searchByString(Event *events, int count, const char *term, const char *field);

int searchByInt(Event *events, int count, int value, const char *field);

#endif