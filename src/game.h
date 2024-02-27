#ifndef _GAME_H_
#define _GAME_H_

#include <ncurses.h>
#include <stdlib.h>  // rand
#include <time.h>

#define ROWS 10
#define COLS 20

#define WALL '#'
#define CHARACTER '@'
#define ENEMY 'X'

char game_map[ROWS][COLS];

void game_init(void);
void dungeon_map(void);
void movement_character(int movement_button, int *py, int *px);
void generate_enemy(int *ey, int *ex);
int check_attack_enemy(int py, int px, int ey, int ex);

void settings_ncurses(void);

#endif  // _GAME_H_