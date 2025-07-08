#include "../include/event.h"

void editEvent(Event *events, int count, int indexToEdit) {
    if (indexToEdit < 0 || indexToEdit >= count) {
        printf("invalid index\n");
        return;
    }

    printf("edit event: %s\n", events[indexToEdit].name);
    add(&events[indexToEdit]);
}