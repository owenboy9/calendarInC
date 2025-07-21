#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void disableRawMode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);  // flush and restore original terminal settings (constants used by system calls to manipulate terminal i/o settings through termios api)
}

/*
TCSANOW — apply immediately.

TCSADRAIN — wait for output to drain, then apply.

TCSAFLUSH — wait for output to drain, and discard any unread input.
*/

void enableRawMode(struct termios *orig_termios) {
    struct termios raw;

    tcgetattr(STDIN_FILENO, orig_termios);  // store current terminal attributes
    raw = *orig_termios;  // make a copy to modify

    raw.c_lflag &= ~(ECHO | ICANON);  // disable canonical mode (user must press enter to submit input) and echo (typed chars won't be displayed))
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);  // apply the modified settings
}

int arrowMenu(const char *title, const char *options[], int numOptions) {
    struct termios orig_termios;
    enableRawMode(&orig_termios);

    int selected = 0;
    char ch;

    while (1) {
        printf("\033[2J\033[H"); // clear screen: \033[2J = ANSI escape code to clear the screen; \033[H Moves cursor to the home position (top-left)
        printf("-----> %s <-----\n", title);
        for (int i = 0; i < numOptions; i++) {
            if (i == selected) {
                printf(" → \033[1m%s\033[0m\n", options[i]);  // highlight
            } else {
                printf("   %s\n", options[i]);
            }
        }

        ch = getchar();
        if (tolower(ch) == 'q') {
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