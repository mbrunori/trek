#ifndef FS_H
#define FS_H

#include "app.h"

int enterNext(AppState *app);
int goParent(AppState *app);

int loadDir(AppState *app);

#endif