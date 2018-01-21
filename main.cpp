#include <iostream>
#include <ncurses.h>
#include "Ship.hpp"

int main(void)
{

	Ship Player1(1,1, "P");


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
		clear();
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
				Player1.moveUp();
				break;

			case KEY_DOWN: //move down
			case 's':
			case 'k':
				Player1.moveDown();
				break;

			case KEY_LEFT: //move left
			case 'a':
			case 'j':
				Player1.moveLeft();
				break;

			case KEY_RIGHT: //move right
			case 'd':
			case 'l':
				Player1.moveRight();
				break;

			case ' ': //fireeee
				break;

			default:
				break;
		}

		mvprintw(Player1.getY(), Player1.getX(), "P");

		if (exit_requested) break ;

		refresh();
	}






	timeout(-1);
	getch();
	// delwin(game.getGame_window());
	endwin(); /* End curses mode */

	return (0);
}
