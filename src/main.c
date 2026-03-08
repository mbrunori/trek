#include "app.h"
#include "ui.h"
#include "fs.h"

int main(int argc, char const *argv[])
{
    AppState app;
    getcwd(app.path, sizeof(app.path));

    struct termios original;
    
    app.tty = fopen("/dev/tty", "r+");
    int ttyfd = fileno(app.tty);

    enableRawMode(&original, ttyfd);

    char nextChar;
    int running = 1;
    loadDir(&app);

    //printf("\033[?1049h"); //enters alternate screen

    while (running)
    {
        printAvailable(&app);
        
        nextChar = fgetc(app.tty);

        switch (nextChar)
        {
            case 'c':
                running = 0;
                break;

            case 'j':
                if(app.selected < app.subDirCount)
                    app.selected++;
                break;

            case 'k':
                if(app.selected > 0)
                    app.selected--;
                break;

            case 'l':
                enterNext(&app);
                break;
            
            case 'h':
                goParent(&app);
                break;

            case 'i':
                //printf("\033[?1049l"); //exits alternate screen
                disableRawMode(&original, ttyfd);
                printf("%s\n", app.path);
                fclose(app.tty);
                return 0;
                break;

            default:
                break;
        }

    }

    fclose(app.tty);
    
    //printf("\033[?1049l"); //exits alternate screen
    disableRawMode(&original, ttyfd);

    return 0;
}
