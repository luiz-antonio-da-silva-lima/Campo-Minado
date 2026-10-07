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
#define largura 40
#define altura 20

char buffer[altura * largura * 28 + (altura * 28)];
typedef struct tabuleiro
{
    char bg[28];
    bool ContemBomba;
} tabuleiro;

tabuleiro canvas[altura][largura];

void criarCampo()
{
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            if ((x + y) % 2)
            {
                strcpy(canvas[y][x].bg, VerdeClaro);
            }
            else
            {
                strcpy(canvas[y][x].bg, VerdeEscuro);
            }
            }
        }
    }
    void printarCampo()
    {
        int idx = 0;
        idx += sprintf(idx + buffer, "%s", setCursorIncio);
        for (int y = 0; y < altura; y++)
        {
            for (int x = 0; x < largura; x++)
            {
                idx += sprintf(idx + buffer, "%s", canvas[y][x].bg);
            }
            idx += sprintf(buffer + idx, "\x1b[0m\n");
        }
        fputs(buffer, stdout);
    }

    int main()
    {
        criarCampo();
        printarCampo();
    }