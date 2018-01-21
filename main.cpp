#include <iostream>
#include <ncurses.h>
#include "Ship.hpp"
#include "Enemy.hpp"
#include <ctime>

#define NUM 15
#define ENEMY_COLOR 1
#define PLAYER_COLOR_1 2
#define PLAYER_COLOR_2 3
#define PLAYER_COLOR_3 4
#define SCORE_COLOR 5

int main(void)
{
  Ship Player1(1,1, "C");
  int ch;
  bool exit_requested = false;
	int maxX, maxY;
  srand(time(nullptr));
	
	Enemy enemy[NUM];
	for (int i = 0; i < NUM; i++)
	{
		enemy[i].setX(249 + (rand() %100));
		enemy[i].setY(rand() % 66);
		enemy[i].setSpeed(0.005 * (rand() % 8 + 1));
	}
  initscr();
	refresh();
	start_color();
	init_pair(ENEMY_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(PLAYER_COLOR_1, COLOR_GREEN, COLOR_BLACK);
	init_pair(PLAYER_COLOR_2, COLOR_BLUE, COLOR_BLACK);
	init_pair(PLAYER_COLOR_3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(SCORE_COLOR, COLOR_WHITE, COLOR_RED);
	curs_set(0);
	getmaxyx(stdscr, maxY, maxX);
  
	keypad(stdscr, true);// enable function keys
	nodelay(stdscr, true);// disable input blocking
	noecho();
	timeout(0); // wtimeout(stdscr, 0);

	while(!exit_requested)
	{
		ch = getch();
		erase();
		{//draw score
			attron(A_BOLD | A_REVERSE | COLOR_PAIR(SCORE_COLOR));
			mvprintw(maxY - 1, maxX / 2 - 6, "SCORE: %d", 4399);
			attroff(A_BOLD | A_REVERSE | COLOR_PAIR(SCORE_COLOR));
		}


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

    {//draw player & bullets
			attron(A_BOLD | A_REVERSE | COLOR_PAIR(PLAYER_COLOR_1));
			mvprintw(Player1.getY(), Player1.getX(), &Player1.getType()[0]);
			attroff(A_REVERSE);
			if (Player1.bullet.getX() > 0 && Player1.bullet.getX() < 250)
			{
				Player1.bullet.moveRight();
				Player1.bullet.travel();
			}
			mvprintw(Player1.bullet.getY(), Player1.bullet.getX(), "*");
			attroff(A_BOLD  | COLOR_PAIR(PLAYER_COLOR_1));
		}

		{//draw enemy
			attron(A_BOLD | COLOR_PAIR(ENEMY_COLOR));
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
			attroff(A_BOLD | COLOR_PAIR(ENEMY_COLOR));
		}

		if (exit_requested) break ;

		refresh();
	}






	timeout(-1);
	getch();
	//mvprintw(maxY/2, maxX/2, "GAME OVER!");
	endwin(); /* End curses mode */

	return (0);
}
