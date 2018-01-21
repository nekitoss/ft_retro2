#include <iostream>
#include <ncurses.h>


int main(void)
{
	int ch;
	bool exit_requested = false;



	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	curs_set(0);
	//getmaxyx()
	keypad(stdscr, true);// enable function keys
	nodelay(stdscr, true);// disable input blocking
	noecho();
	timeout(0); // wtimeout(stdscr, 0);








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
