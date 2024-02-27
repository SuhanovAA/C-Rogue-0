FLAGS := -std=c11 -Wall -Werror -Wextra
FILE := game

game:
	gcc $(FLAGS) $(FILE).c -o $(FILE).o -lncurses

clean:
	rm -rf *.exe *.out *.o

style:
	clang-format -style=Google -i *.c *.h

install_MacOS:
	brew install ncurses

install_Linux:
	sudo apt-get install libncurses-dev