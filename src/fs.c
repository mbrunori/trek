#include "fs.h"

int enterNext(AppState *app)
{
    Entry *e = &app->entries[app->selected];
    if(!e->isDir)
        return -1;

    char newPath[4096];
    snprintf(newPath, sizeof(newPath), "%s/%s", app->path, e->name);
    strcpy(app->path,  newPath);

    loadDir(app);

    app->selected = 0;
    return 0;
}

int goParent(AppState *app)
{
    char *lastSlash = strrchr(app->path, '/');
    if(lastSlash != NULL && lastSlash != app->path) 
    {
        *lastSlash = '\0';
    }
    else 
    {
        strcpy(app->path, "/");  // at root
    }
    loadDir(app);
    app->selected = 0;
}

int loadDir(AppState *app)
{
    DIR *dir = opendir(app->path);
    struct dirent *entry;

    if(dir == NULL)
        return -1;

    app->subDirCount = 0;

    while((entry = readdir(dir)) != NULL)
    {
        if(app->subDirCount >= MAX_ENTRIES)
            break;

        strcpy(app->entries[app->subDirCount].name, entry->d_name);

        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", app->path, entry->d_name);

        struct stat st;
        if(stat(fullpath, &st) == 0)
        {
            app->entries[app->subDirCount].isDir = S_ISDIR(st.st_mode);
        } else
        {
            app->entries[app->subDirCount].isDir = 0;
        }

        app->subDirCount++;
        
    }

    closedir(dir);
    return 0;
}
