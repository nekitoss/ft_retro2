#include <iostream>
#include <ncurses.h>


int main(void)
{
	int ch;
	nodelay(stdscr, TRUE);
	noecho();
	timeout(0); // wtimeout(stdscr, 0);
	curs_set(0);
	bool exit_requested = false;








	while(!exit_requested)
	{

		ch = getch();


		switch (ch)
		{
			case 27:
			case 'q': //exit
				exit_requested = true;
				break;

			case KEY_UP: //move up
			case 'w':
			case 'i':
				break;

			case KEY_DOWN: //move down
			case 's':
			case 'k':
				break;

			case KEY_LEFT: //move left
			case 'a':
			case 'j':
				break;

			case KEY_RIGHT: //move right
			case 'd':
			case 'l':
				break;

			case ' ': //fireeee
				break;

			default:
				break;
		}


		if (exit_requested) break ;

		refresh();
	}






	timeout(-1);
	getch();
	// delwin(game.getGame_window());
	endwin(); /* End curses mode */

	return (0);
}
