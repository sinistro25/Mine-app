CC= g++
CFLAGS= -Wall -I/usr/include -lsfml-graphics -lsfml-window -lsfml-system

mine-app: table_ui.o Board.o main.o
	$(CC) -o mine-app main.o table_ui.o Board.o
