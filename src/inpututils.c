#include <stdio.h>
#include <string.h>
#include <ctype.h>

void promptString(const char *label, char *field, size_t maxLen) {
    char buf[100];
    printf("%s (currently '%s': )", label, field);
    if (fgets(buf, ziseof(buf), stdin)) {
        if (buf[0] != '\n') {
            buf[strcspn(buf, "\n")] = '\0';   // remove newline
            strncpy(field, buf, maxLen);
            field[maxLen - 1] = '\0';
        }
    }
}

void promptInt(const char *label, int *field) {
    char buf[100];
    printf("%s (currently %d): ", label, *field);
    if (fgets(buf, sizeof(buf), stdin)) {
        if (buf[0] != '\n') {
            sscanf(buf, "%d", field);
        }
    }
}