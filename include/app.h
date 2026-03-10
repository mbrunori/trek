#ifndef APP_H
#define APP_H

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>

#define MAX_ENTRIES 2048
#define PATH_MAX 4096

typedef struct Entry
{
    char name[256];
    int isDir;
}Entry;


typedef struct AppState
{
    char path[PATH_MAX];

    size_t subDirCount;
    size_t selected;

    Entry entries[MAX_ENTRIES];

    FILE *tty;
}AppState;


#endif