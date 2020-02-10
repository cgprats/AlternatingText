#include <curses.h>
#include <unistd.h>
#include <string.h>
int main() {
	int x = 0, y = 3;
	int max_y = 0, max_x = 0;
	int direction_x = 1, direction_y = 1;
	char outputOne[] = "defaultOutputOne";
	char outputTwo[] = "defaultOutputTwo";
	char sleepBool[] = "Y";
	char clearBool[] = "Y";
	int sleepVal = 1;
	int clearVal = 0;
	int flipper;
	initscr();
	curs_set(FALSE);
	refresh();
	mvprintw(0, 0, "Input Two Strings to Output");
	mvprintw(1, 0, "Output One: ");
	getstr(outputOne);
	mvprintw(2, 0, "Output Two: ");
	getstr(outputTwo);
	mvprintw(3, 0, "Wait a Second After Each Output: [Y/n]");
	getstr(sleepBool);
	if (sleepBool[0] == 'N' || sleepBool[0] == 'n') {
		sleepVal = 0;
	}
	mvprintw(4, 0, "Clear Output After Each Output: [y/N]");
	getstr(clearBool);
	if (clearBool[0] == 'Y' || clearBool[0] == 'y') {
		clearVal = 1;
	}
	clear();
	while (1) {
		if (clearVal == 1) {
			clear();
		}
		noecho();
		getmaxyx(stdscr, max_y, max_x);
		flipper = x % 2;
		mvprintw(0, 0, "Coordinates: (%d,%d)", x, y);
		mvprintw(1, 0, "Max_x %d", max_x);
		mvprintw(2, 0, "Max_y %d", max_y);
		if (flipper == 0) {
			mvprintw(y, x, outputOne);
		}
		else {
			mvprintw(y, x, outputTwo);
		}
		if (x == max_x) {
			direction_x = -1;
		}
		else if (x == 0) {
			direction_x = 1;
		}
		x += direction_x;
		if (y == max_y) {
			direction_y = -1;
		}
		else if (y == 0) {
			direction_y = 1;
		}
		y += direction_y;
		refresh();
		if (sleepVal == 1) {
			sleep(1);
		}
	}
	endwin();
}
