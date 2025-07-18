#include "../include/event.h"
#include "../include/add.h"
#include <stdio.h>

void editEvent(Event *events, int count, int indexToEdit) {

    if (indexToEdit < 0 || indexToEdit >= count) {
        printf("invalid index\n");
        return;
    }

    Event *e = &events[indexToEdit];

    printf("edit event: %s\n", e->name);
    printf("leave blank to keep the current value");

    char input[100];

    printf("new name (currently '%s'): ", e->name);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') strncpy(e->name, input, sizeof(e->name));

    char input[50];

    printf("new category (currently '%s'): ", e->category);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') strncpy(e->category, input, sizeof(e->category));

    printf("new year (currently: '%d'): ", e->year);
    scanf("%d", &e->year);

    add(&events[indexToEdit]);
}