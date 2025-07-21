#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>

#define MAX_OPTIONS 10

void disableRawMode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

void enableRawMode(struct termios *orig_termios) {
    struct termios raw;

    tcgetatts(STDIN_FILENO, orig_termios);
    raw = *orig_termios;

    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int arrowMenu(const char *title, const char *options[], int numOptions) {
    struct termios orig_termios;
    enableRawMode(&orig_termios);

    int selected = 0;
    int ch;

    while (1) {
        printf("\033[H\033[J"); // clear screen
        printf("-----> %s <-----\n", title);
        for (int i = 0; i < numOptions; i++) {
            if (i == selected) {
                printf(" → \033[1m%s\033[0m\n", options[i]);
            } else {
                printf("   %s\n", options[i]);
            }
        }

        ch = getchar();
        if (ch == 'q') {
            break; // exit on 'q'
        } else if (ch == '\033') { // escape sequence
            getchar(); // skip the '[' character
            switch (getchar()) { // get the arrow key
                case 'A': // up arrow
                    selected = (selected - 1 + numOptions) % numOptions;
                    break;
                case 'B': // down arrow
                    selected = (selected + 1) % numOptions;
                    break;
            }
        } else if (ch == '\n') { // enter key
            break; // select the current option
        }
    }

    disableRawMode(&orig_termios);
    return selected;
}