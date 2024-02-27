FLAGS := -std=c11 -Wall -Werror -Wextra
FILE := game

all: clean game 

game: check_style
	gcc $(FLAGS) -o ../$(FILE).exe $(FILE).c -lncurses
	../$(FILE).exe

clean:
	rm -rf ../*.exe ../*.out ../*.o

check_style: clean
	clang-format -style=Google -i *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem ../src/

install_MacOS:
	brew install ncurses

install_Linux:
	sudo apt-get install libncurses-dev