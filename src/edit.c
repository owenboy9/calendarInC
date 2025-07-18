#include "../include/event.h"
#include "../include/add.h"
#include <stdio.h>

void editEvent(Event *events, int count, int indexToEdit) {
    if (indexToEdit < 0 || indexToEdit >= count) {
        printf("invalid index\n");
        return;
    }

    printf("edit event: %s\n", events[indexToEdit].name);
    printf("leave blank to keep the current value");
    add(&events[indexToEdit]);
}