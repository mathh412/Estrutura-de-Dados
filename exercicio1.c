/*
Implemente, em linguagem C, um programa que:
(a) Solicite ao usuário as dimensões x, y e z para uma matriz
tridimensional (matriz 3D) de inteiros.
(b) Aloque dinamicamente a memória para a matriz 3D utilizando
ponteiro de ponteiro de ponteiro (int ***).
(c) Preencha a matriz 3D com valores fornecidos pelo usuário.
(d) Imprima a matriz 3D, exibindo os valores de cada camada, linha
por linha, para cada uma das camadas da matriz.
(e) Libere (desaloque) a memória alocada dinamicamente ao final.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, y, z,value;

    printf("z: ");
    scanf_s("%d", &z);
    printf("y: ");
    scanf_s("%d", &y);
    printf("x: ");
    scanf_s("%d", &x);
    int*** matriz;
    //matrix definition
    matriz = malloc(z * sizeof(int**));
    for (int i = 0;i < z;i++)
    {
        matriz[i] = malloc(y * sizeof(int*));
        for (int j = 0;j < y;j++)
        {
            matriz[i][j] = malloc(x * sizeof(int));
        }
    }

    //matrix populate
    for (int i = 0;i < z;i++)
    {
        for (int j = 0;j < y;j++)
        {
            for (int k = 0;k < x;k++)
            {
                printf("[%d] [%d] [%d]", i, j, k);
                scanf_s("%d", &value);
                matriz[i][j][k] = value;
            }
        }
    }
    for (int i = 0;i < z;i++)
    {
        printf("\n\ncamada %d:\n\n",i);
        for (int j = 0;j < y;j++)
        {
            for (int k = 0;k < x;k++)
            {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
    }

    for (int i = 0;i < z;i++)
    {
        for (int j = 0;j < y;j++)
        {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
