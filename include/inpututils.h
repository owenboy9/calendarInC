#ifndef INPUTUTILS_H
#define INPUTUTILS_H

#include <stddef.h>

void promptString(const char *label, char *buffer, int size, int allowEmpty);

void promptInt(const char *label, int *field, int showCurrent);

#endif