#include "game.h"

int main(void) {
  game_init();
  return 0;
}

void game_init(void) {
  initscr();  // init ncurses (lib and struct)
  settings_ncurses();

  int movement_button = 0;
  int py = 5, px = 5;

  do {
    clear();
    dungeon_map();
    movement_character(movement_button, &py, &px);
  } while ((movement_button = getch()) != (int)113);

  endwin();  // end ncurses lib and clear struct data
}

void dungeon_map(void) {
  for (int yy = 0; yy <= ROWS; yy++) {
    for (int xx = 0; xx <= COLS; xx++) {
      if (yy == 0 || xx == 0 || yy == ROWS || xx == COLS) {
        game_map[yy][xx] = WALL;
        mvaddch(yy, xx, WALL);
      }
    }
  }
}

void movement_character(const int movement_button, int *py, int *px) {
  int temp_py = *py;
  int temp_px = *px;
  if (movement_button == 'w' && game_map[temp_py - 1][temp_px] != WALL) {
    temp_py--;
  } else if (movement_button == 's' && game_map[temp_py + 1][temp_px] != WALL) {
    temp_py++;
  } else if (movement_button == 'a' && game_map[temp_py][temp_px - 1] != WALL) {
    temp_px--;
  } else if (movement_button == 'd' && game_map[temp_py][temp_px + 1] != WALL) {
    temp_px++;
  }
  *py = temp_py;
  *px = temp_px;

  mvaddch(temp_py, temp_px, CHARACTER);
}

void settings_ncurses(void) {
  keypad(stdscr, TRUE);  // on addition keys
  noecho();              // don`t display input
  curs_set(0);           // off curs
}