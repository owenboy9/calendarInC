#ifndef SEACH_H
#define SEARCH_H

#include "event.h"
#include "eventManager.h"

int searchByString(EventManager *mgr, const char *term, const char *field);

int searchByInt(EventManager *mgr, int value, const char *field);

#endif