#include "game.h"

int main(void) {
  game_init();
  return 0;
}

void game_init(void) {
  initscr();  // init ncurses (lib and struct)
  settings_ncurses();
  srand(time(NULL));

  int movement_button = 0;
  int py = 1 + (rand() % (ROWS - 1)), px = 1 + (rand() % (COLS - 1));
  int ey, ex;

  struct Person character_info = {0};

  generate_enemy(&ey, &ex);
  do {
    clear();
    dungeon_map();
    movement_character(movement_button, &py, &px);
    if (check_attack_enemy(py, px, ey, ex)) {
      generate_enemy(&ey, &ex);
      character_info.shot += 1;
    }
    mvaddch(ey, ex, ENEMY);
    info_character(character_info);
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

void generate_enemy(int *ey, int *ex) {
  *ey = 1 + (rand() % (ROWS - 1)), *ex = 1 + (rand() % (COLS - 1));
}

int check_attack_enemy(int py, int px, int ey, int ex) {
  int flag = 0;
  if (py == ey && px == ex) {
    flag = 1;
  }
  return flag;
}

void info_character(struct Person ci) {
  mvwprintw(stdscr, ROWS + 2, 0, "Numbers of enemy shot: %d", ci.shot);
}

void settings_ncurses(void) {
  keypad(stdscr, TRUE);  // on addition keys
  noecho();              // don`t display input
  curs_set(0);           // off curs
}