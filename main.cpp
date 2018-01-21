#include <iostream>
#include <ncurses.h>
#include "Ship.hpp"
#include "Enemy.hpp"
#include <ctime>

#define NUM 15
int main(void)
{
	srand(time(nullptr));
	Ship Player1(1,1, "C");
	Enemy enemy[NUM];
	for (int i = 0; i < NUM; i++)
	{
		enemy[i].setX(249 + (rand() %100));
		enemy[i].setY(rand() % 66);
		enemy[i].setSpeed(0.005 * (rand() % 8 + 1));
	}
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
		clear();
		

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
				Player1.shoot();
				break;

			default:
				break;
		}

		mvprintw(Player1.getY(), Player1.getX(), &Player1.getType()[0]);
		for (int i = 0; i < NUM; i++)
		{
			if (enemy[i].getX() == Player1.getX() && enemy[i].getY() == Player1.getY()) {
				Player1.damage();
				if (Player1.getLives() <= 0)
					Player1.setType("X");
			}
			if (enemy[i].getX() == Player1.bullet.getX() && enemy[i].getY() == Player1.bullet.getY()) {
				mvprintw(enemy[i].getY(), enemy[i].getX(), "X");
				enemy[i].setX(249 + (rand() %100));
				enemy[i].setY(rand() % 66);
				Player1.bullet.setX(250);
			}
			else {
				mvprintw(enemy[i].getY(), enemy[i].getX(), "<");
				enemy[i].moveLeft();
				enemy[i].travel();
			}

		}
		if (Player1.bullet.getX() > 0 && Player1.bullet.getX() < 250)
		{
			Player1.bullet.moveRight();
			Player1.bullet.travel();
		}
		mvprintw(Player1.bullet.getY(), Player1.bullet.getX(), "*");
		if (exit_requested) break ;

		refresh();
	}






	timeout(-1);
	getch();
	// delwin(game.getGame_window());
	endwin(); /* End curses mode */

	return (0);
}
