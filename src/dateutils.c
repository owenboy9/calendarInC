#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "../include/dateutils.h"

void weekday(int year, int month, int day, int measure, int interval, int count) {
    struct tm t = {0};
    t.tm_year = year - 1900; // tm_year is years since 1900
    t.tm_mon = month - 1;    // tm_mon is 0-indexed (0 = january)
    t.tm_mday = day;

    char buf[100];

    for (int i = 0; i < count; i++) {
        mktime(&t);  // normalize the tm struct
        strftime(buf, sizeof(buf), "%A, %d-%m-%Y", &t);

        for (int j = 0; buf[j]; j++) {
            buf[j] = tolower((unsigned char)buf[j]);
        }

        puts(buf);  // print the formatted string

        if (measure == 0) {
            t.tm_mday += interval; // increment by days
        } else if (measure == 1) {
            t.tm_mday += 7 * interval; // increment by weeks
        } else if (measure == 2) {
            t.tm_mon += interval; // increment by months
        } else if (measure == 3) {
            t.tm_year += interval; // increment by years
        } 
    }
}