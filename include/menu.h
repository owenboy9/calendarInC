#ifndef MENU_H
#define MENU_H

#include <termios.h>

void disableRawMode(struct termios *orig_termios);
void enableRawMode(struct termios *orig_termios);
int arrowMenu(const char *title, const char *options[], int numOptions);

#endif // MENU_H