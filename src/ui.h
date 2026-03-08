#ifndef UI_H
#define UI_H

#include "app.h"

void enableRawMode(struct termios *original, int ttyfd);
void disableRawMode(struct termios *original, int ttyfd);


void printAvailable(AppState *app);


#endif
