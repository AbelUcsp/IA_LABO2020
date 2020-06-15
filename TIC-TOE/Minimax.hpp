#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <random>

#include<GL/glut.h>

using namespace std;

int player; ///0 IA,		1 JUGADOR,		-1 LIBRE
int tablero[3][3];

struct coodernadas {
public:

    coodernadas() :x{0}, y{0} {}
    coodernadas(int x_, int y_) {
        x = x_;
        y = y_;
    }
    int x, y;
};

bool ExistenMovimientos() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (tablero[i][j] == -1) /// -1 POS LIBRE
                return true;
    return false;
}

int AlguienGano() {
    for (int i = 0; i < 3; ++i) { ///horizontal
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] == 0) ///IA
                return 0;
            else if (tablero[i][0] == 1) ///IA
                return 1;
        }
    }

    for (int i = 0; i < 3; ++i) { ///vertical
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] == 0) ///IA
                return 0;
            else if (tablero[0][i] == 1) ///IA
                return 1;
        }
    }


    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) { ///diagolnal principal
        if (tablero[0][0] == 0) ///IA
            return 0;
        else if (tablero[0][0] == 1) ///PLAYER
            return 1;
    }
    if (tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2]) { ///diagolnal secundaria
        if (tablero[2][0] == 0) ///IA
            return 0;
        else if (tablero[2][0] == 1) ///PLAYER
            return 1;
    }
    return -1;///nadie gano
}

int MiniMax(int profStatic, int profundidad, bool MinMax) { ///MinMax true=IA, false=JUGADOR
    int marcador = AlguienGano();
    int mejorValor = 10;

    if (marcador == 0)
        return 10;///maximizar
    if (marcador == 1)
        return -10;///minimizar
    if (!ExistenMovimientos())
        return 0;

    if (profundidad < profStatic && profStatic <= 4) {
        return 0;
    }

 

    if (MinMax) {
        mejorValor = -32500;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                if (tablero[i][j] == -1) { ///FREE
                    tablero[i][j] = 0;
                    mejorValor = max(mejorValor, MiniMax(profStatic, profundidad + 1, !MinMax));
                    tablero[i][j] = -1;
                }
          

        }
        return mejorValor;
    }
    else {
        mejorValor = 32500;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                if (tablero[i][j] == -1) { ///FREE
                    tablero[i][j] = 1;
                    mejorValor = min(mejorValor, MiniMax(profStatic, profundidad + 1, !MinMax));
                    tablero[i][j] = -1;
                }
            
        }
        return mejorValor;
    }
}


void MejorJugada(int profStatic) {
    int mejorValor = -1000;
    int mejorTmp;
    coodernadas corr(-1,-1);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == -1) { ///FREE
                tablero[i][j] = 0;
                mejorTmp = MiniMax(profStatic, 0, false);
                tablero[i][j] = -1;

                if (mejorTmp > mejorValor) {
                    mejorValor = mejorTmp;
                    corr.x = i;
                    corr.y = j;
                }
            }

        }
    }
    tablero[corr.x][corr.y] = 0;
}


void print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}
