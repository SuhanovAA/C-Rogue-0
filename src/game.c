#include "game.h"

int main(void){
    game_init();
    return 0;
}

void game_init(void){
    initscr();  // init ncurses (lib and struct)
    printw("123");
    getch();
    endwin();   // end ncurses lib and clear struct data
}