#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Variáveis globais ------>
int teclaEnter = 13;
int setaBaixo = 80;
int setaCima = 72;

void tiraCursor();
bool verificarLogin(char usuario[], char senha[]);
void desenhaMoldura();
void desenhaMolduraLOGIN(int x1, int y1, int x2, int y2);
void desenhaMoldura();
void menuLogin();
void menuGerente();

// Funções ->
void setColor(int color);
void gotoxy(int x, int y);

int main() {
	setlocale(LC_CTYPE, "Portuguese");
	srand(time(NULL));
	tiraCursor();
	menuLogin();
	
  return 0;
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tiraCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

bool verificarLogin(char usuario[], char senha[]) {
	FILE * arquivo = fopen("cadastro.txt", "r");
	if(arquivo == NULL) {
		printf("Erro ao abrir o arquivo de cadastro.\n");
		return false;
	}
	
	char linha[100];
	char usuarioArquivo[50], senhaArquivo[50];
	
	while(fgets(linha, sizeof(linha), arquivo) != NULL) {
		sscanf(linha, "Usuario: %s | Senha: %s", usuarioArquivo, senhaArquivo);
		
		if(strcmp(usuario, usuarioArquivo) == 0 && strcmp(senha, senhaArquivo) == 0) {
			fclose(arquivo);
			return true;
		}
	}
	
	fclose(arquivo);
	return false;
}
void desenhaMoldura() {
  int cor = 1;
  int i;
  setColor(9);

  for (i = 16; i <= 64; i++) {
    gotoxy(i, 2);
    printf("_");
  }
  gotoxy(33, 2);
  printf("Estoque - Mercado");

  for (i = 16; i <= 64; i++) {
    gotoxy(i, 3);
    printf("_");
    gotoxy(i, 18);
    printf("_");
  }

  for (i = 4; i < 18; i++) {
    gotoxy(15, i);
    printf("|");
    gotoxy(65, i);
    printf("|");
  }

  gotoxy(15, 3);
  printf("|");
  gotoxy(65, 3);
  printf("|");
  gotoxy(15, 18);
  printf("|");
  gotoxy(65, 18);
  printf("|");

  setColor(15);
}

void desenhaMolduraLOGIN(int x1, int y1, int x2, int y2) {
  gotoxy(x1, y1);
  printf("+");

  gotoxy(x2, y1);
  printf("+");

  gotoxy(x1, y2);
  printf("+");

  gotoxy(x2, y2);
  printf("+");

  for (int i = x1 + 1; i < x2; i++) {
    gotoxy(i, y1);
    printf("-");
    gotoxy(i, y2);
    printf("-");
  }

  for (int i = y1 + 1; i < y2; i++) {
    gotoxy(x1, i);
    printf("¦");
    gotoxy(x2, i);
    printf("¦");
  }
}

void menuGerente() {
	system("cls");
	desenhaMoldura();
	setColor(15);
  gotoxy(40, 5); 
  Sleep(3000); 
	
}

void menuLogin() {
    char registro[2][100];
    bool erroLogin;

    do {
        system("cls");
        setColor(9);
        
    
        desenhaMolduraLOGIN(28, 1, 72, 17);
        
        gotoxy(45, 2);
        printf("TELA LOGIN");

        
        desenhaMolduraLOGIN(33, 5, 67, 7);
        setColor(15);
        gotoxy(34, 6);
        printf("Usuário: ");
        gets(registro[0]);
        
        
        desenhaMolduraLOGIN(33, 9, 67, 11);
        gotoxy(34, 10);
        printf("Senha: ");
        gets(registro[1]);

      
        erroLogin = verificarLogin(registro[0], registro[1]);

        if (erroLogin) {
            setColor(2);
            gotoxy(37, 14);
            printf("Login bem-sucedido!\n");
            Sleep(2000);
            menuGerente();
        } else {
            setColor(4);
            gotoxy(35, 14);
            printf("Usuário ou senha incorretos");
            gotoxy(40,15);
            printf("Tente novamente!!!");
            Sleep(2000);
        }
    } while (!erroLogin);
}

