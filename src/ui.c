#include "ui.h"

//disabling and enabling of raw mode
void enableRawMode(struct termios *original, int ttyfd)
{
    struct termios raw;
    tcgetattr(ttyfd, original);
    raw = *original;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(ttyfd, TCSAFLUSH, &raw);
}

void disableRawMode(struct termios *original, int ttyfd)
{
    tcsetattr(ttyfd, TCSAFLUSH, original);
}

void printAvailable(AppState *app)
{
	fprintf(app->tty, "\033[3J");  // clear scroll-back buffer
	fprintf(app->tty, "\033[2J");  // clear screen
    fprintf(app->tty, "\033[H");   // cursor to top

	for(size_t i = 0; i < (strlen(app->path) + strlen("current path:")); i++)
		fprintf(app->tty, "=");
	fprintf(app->tty, "\n");

	fprintf(app->tty, "current path:%s\n", app->path);

	for(size_t i = 0; i < app->subDirCount; i++)
	{
		if(i == app->selected)
		{
			fprintf(app->tty, ">    %s\n", app->entries[i].name);
			continue;
		}
		fprintf(app->tty, "     %s\n", app->entries[i].name);
	}

	fflush(app->tty);
}
