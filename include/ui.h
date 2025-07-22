#ifndef UI_H
#define UI_H
#include "event.h"
#include "eventManager.h"

void listEvents(EventManager *mgr);
void handleViewCalendar(EventManager *mgr);
void handleSearch(EventManager *mgr);
void handleAddEvent(EventManager *mgr);
void showMainMenu(EventManager *mgr);

#endif // UI_H