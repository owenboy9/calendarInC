#include <stdio.h>
#include <string.h>
#include <ctype.h>

void promptString(const char *label, char *buffer, int size, int allowEmpty) {
    char temp[256];

    while (1) {
        printf("%s: ", label);
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("error reading input.\n");
            continue;
        }

        // Remove newline
        temp[strcspn(temp, "\n")] = 0;

        if (!allowEmpty && strlen(temp) == 0) {
            printf("input cannot be empty.\n");
            continue;
        }

        strncpy(buffer, temp, size - 1);
        buffer[size - 1] = '\0'; // ensure null-termination
        break;
    }
}

void promptInt(const char *label, int *field, int showCurrent) {
    char buf[100];

    while (1) {
        if (showCurrent) 
            printf("%s (currently %d): ", label, *field);
        else 
            printf("%s: ", label);

        if (!fgets(buf, sizeof(buf), stdin)) {
            printf("input error. \n");
            continue;
        }

        if (buf[0] == '\n')
            break;

        buf[strcspn(buf, "\n")] = '\0';   // remove newline

        char temp;
        if (sscanf(buf, "%d %c", field, &temp) == 1)
            break;
        else
            printf("invalid input. type in a number or press enter to move on.");
    }
}