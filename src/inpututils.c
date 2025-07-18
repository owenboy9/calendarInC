#include <stdio.h>
#include <string.h>
#include <ctype.h>

void promptString(const char *label, char *field, size_t maxLen, int showCurrent) {
    char buf[100];

    if (showCurrent) printf("%s (currently '%s'): ", label, field);
    else printf("%s: ", label);

    if (fgets(buf, sizeof(buf), stdin)) {
        if (buf[0] != '\n') {
            buf[strcspn(buf, "\n")] = '\0';   // remove newline
            strncpy(field, buf, maxLen);
            field[maxLen - 1] = '\0';  // ensure null-terminationn
        }
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