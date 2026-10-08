#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#define VerdeEscuro "\x1b[48;2;9;175;30m  "
#define VerdeClaro "\x1b[48;2;59;247;73m  "
#define VerdeEscuro "\x1b[48;2;9;175;30m  "
#define VerdeClaro "\x1b[48;2;59;247;73m  "
#define Vermelho "\x1b[48;2;255;0;0m  "
#define AzulEscuro "\x1b[48;2;0;0;200m  "
#define AzulmenosEscuro "\x1b[48;2;0;120;255m  "
#define linhaNova "\x1b[0m\n"
#define setCursorIncio "\033[H"
#define esconderCursor "\033[?25l"
#define mostrarCursor "\033[?25h"
#define margem_x 4
#define margem_y 3
#define largura 40
#define altura 20
#define minas 20

int minasnotabuleiro;
char buffer[altura * largura * 28 + (altura * 28)];
typedef struct tabuleiro
{
    char bg[28];
    bool ContemBomba;
} tabuleiro;

tabuleiro Campo[altura][largura];

void posicionarCursor(int x,int y){
    printf("\033[%d;%dH", x, y);
}

void criarNotacao(){
    posicionarCursor(1, margem_x);
    for (int i = 0; i < largura; i++){
        if (i % 10 == 0) printf("%-2d", i / 10);
        else             printf("  ");
    }
    posicionarCursor(2, margem_x);
    for (int i = 0; i < largura; i++){
        printf("%-2d", i % 10);
    }
    for (int i = 0; i < altura; i++){
        posicionarCursor(margem_y + i, 1);
        printf("%2d", i);
    }
}


void criarCampo()
{
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            if ((x + y) % 2)
            {
                if (Campo[y][x].ContemBomba == true)
                {
                    strcpy(Campo[y][x].bg, Vermelho);
                }
                else if(Campo[y][x].ContemBomba == false)
                {
                    strcpy(Campo[y][x].bg, VerdeClaro);
                }
            }
            else
            {
                if (Campo[y][x].ContemBomba == true)
                {
                    strcpy(Campo[y][x].bg, Vermelho);
                }
                else if(Campo[y][x].ContemBomba == false)
                {
                    strcpy(Campo[y][x].bg, VerdeEscuro);
                }
            }
        }
    }
}
void printarCampo()
{
    int idx = 0;
    posicionarCursor(margem_x+1,margem_y+1);
    for (int y = 0; y < altura; y++)
    {
        idx += sprintf(idx + buffer, "\033[%d;%dH", margem_y + y, margem_x);
        for (int x = 0; x < largura; x++)
        {
            idx += sprintf(idx + buffer, "%s", Campo[y][x].bg);
        }
         idx += sprintf(buffer + idx, "\x1b[0m");

}
    buffer[idx] = '\0';
    fputs(buffer, stdout);
}
void plantarMinas()
{
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            Campo[y][x].ContemBomba = false;
        }
    }
    for (int i = 0; i < minas; i++)
    {
        {
            int y = rand() % altura;
            int x = rand() % largura;
            if (!(Campo[y][x].ContemBomba))
            {
                Campo[y][x].ContemBomba = true;
                minasnotabuleiro++;
            }
            else if ((Campo[y][x].ContemBomba))
            {
                i--;
            }
        }
    }
}
int main()
{
    SetConsoleOutputCP(65001);
    int seed;
    minasnotabuleiro = 0;
    printf("Digite uma seed");
    scanf("%d", &seed);
    srand(seed);
    system("cls");
    plantarMinas();
    criarNotacao();
    criarCampo();
    printarCampo();
    posicionarCursor(altura + 5, 1);
    printf("%d", minasnotabuleiro);
}