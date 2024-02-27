#ifndef _GAME_H_
#define _GAME_H_

#include <ncurses.h>
#include <stdlib.h>  // rand
#include <time.h>    // time for rand

#define ROWS 10
#define COLS 20

#define WALL '#'
#define CHARACTER '@'
#define ENEMY 'X'

struct Person {
  int shot;
};

char game_map[ROWS + 1][COLS + 1];

void game_init(void);
void dungeon_map(void);
void movement_character(int movement_button, int *py, int *px);
void generate_enemy(int *ey, int *ex);
int check_attack_enemy(int py, int px, int ey, int ex);
void info_character(struct Person ci);

void settings_ncurses(void);

#endif  // _GAME_H_