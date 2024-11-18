#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Variaveis globais ------>

int teclaEnter = 13;
int setaBaixo = 80;
int setaCima = 72;
void tiraCursor();

// Funções ->
int setColor(int color);
void gotoxy(int x, int y);

int main() {
	tiraCursor();


  return 0;
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	/*
CORES:
0	Preto
1	Azul
2	Verde
3	Azul claro
4	Vermelho
5	Roxo
6	Amarelo
7	Branco claro
8	Cinza
9	Azul claro
10	Verde claro
11	Azul piscina
12	Vermelho claro
13	Rosa
14	Amarelo claro
15	Branco
*/
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tiraCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}
