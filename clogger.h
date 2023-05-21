#ifndef clogger
// this is not on most windows systems, so i'm including it here to make sure things still work
#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
// ----------------------------------------------------------------
// SETTINGS
// all settings can (safely) be set through  SET_<SETTING_NAME>() function,
// or you can just specify them in your C file like DELETE_ON_RERUN = true;
// although that means there is no error checking on your values and could cause undefined behavior.
bool DELETE_ON_RERUN = false;
/**
 * LOG LEVELS
 * 0 : TRACE
 * 1 : DEBUG
 * 2 : INFO
 * 3 : WARNING
 * 4 : ERROR
 * 5 : FATAL
 * 6 : OFF
 */
int LOG_LEVEL = 0;

FILE* fp;

void LOG_INIT(char* path) {
    if (access(path, F_OK) && DELETE_ON_RERUN) {
        remove(path);
    }
    fp = fopen(path, "w+");
}

int SET_DELETE_ON_RERUN(bool b) {
    DELETE_ON_RERUN = b;
    return 0;
}

int SET_LOG_LEVEL(int level) {
    if (level < 0 || level > 7) {
        printf("CLOGGER ERROR: Invalid log level! Levels must be between 0 and 7! Defaulting to log level 0 (DEBUG)...\n");
        return -1;
    } else {
        LOG_LEVEL = level;
    }
    return 0;
}

int TRACE(char* msg) {


}

char* formatter(char* msg) {
    // TODO: add support to log stack frame, date, time, function called from, etc. perhaps add time as another function/param that the user can call from the main program to be slightly more accurate?
    // get time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char * time = malloc(32 * sizeof(char));
    snprintf(time, 32, "%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    // constuct message
    size_t size = sizeof(msg) * sizeof(char);
    char* f_msg = malloc(size);
    snprintf(f_msg, size, "%s: %s\n", time, msg);
}

#endif