#ifndef INPUTUTILS_H
#define INPUTUTILS_H

#include <stddef.h>

void promptString(const char *label, char *field, size_t maxLen);

void promptInt(const char *label, int *field);

#endif