#include <stdio.h>

#define N 5
#define ncuad N*N

const int   ejex[8] = {-1,-2,-2,-1,1,2,2,1},
            ejey[8] = {-2,-1,1,2,2,1,-1,-2};


void mover(int tablero[][N], int i, int pos_x, int pos_y, int *q)
{
    int k,u,v;

    k = 0;
    *q = 0;

    do {
        u = pos_x + ejex[k];
        v = pos_y + ejey[k];

        if (u >= 0 && u < N && v >= 0 && v < N) {
            if (tablero[u][v] == 0) {
                tablero[u][v] = i;
                if (i < ncuad) {
                    mover(tablero, i+1, u, v, q);
                    if (!*q) tablero[u][v] = 0; 
                }
                else *q = 1;
            }
        }
        k++;
    } while (!*q & k < 8);
}

int main(void)
{
    int tablero[N][N];
    int i,j,q;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tablero[i][j] = 0;

    tablero[0][0] = 1;
    mover(tablero,2,0,0,&q);

    if (q)
    {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                printf("%3d", tablero[i][j]);
            putchar('\n');
        }
    }
    else 
        printf("\nNo existe solución\n");
    return 0;
}