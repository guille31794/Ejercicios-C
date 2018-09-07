//
//  matriz.c
//  Examen
//
//  Created by Guillermo Girón García on 31/5/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include <stdio.h>

/*
 Cabecera: int compruebaMatriz(int*)
 Precondicion: Matriz inicializada
 Postcondicion: devuelve 1 si tiene punto de silla o 0 sino
*/

int compruebaMatriz(double[5][5]);

/*
 Cabecera: void rellenaMatriz(double*)
 Precondicion: recibe una matriz de reales como parametros
 Postcondicion: solicita al usuario que introduzca numeros en la matriz
 */

void rellenaMatriz(double[5][5]);

/*
 Cabecera: int puntoSilla(int mat[5][5], int posFila, int posColumna)
 Precondicion: recibe una posición de la matriz
 Postcondicion:  comprueba si es punto de silla
 */

int puntoSilla(double[5][5], int, int);

int main()
{
    double Matriz[5][5];
    int comprobador;
    
    rellenaMatriz(&Matriz[5]);
    comprobador = compruebaMatriz(&Matriz[5]);
    
    if(comprobador)
        printf("\nLa matriz tiene un punto de silla");
    else
        printf("\nLa matriz no tiene un punto de silla");
    
    return 0;
}

void rellenaMatriz(double M[5][5])
{
    for(int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            printf("\nIntroduzca el elmento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &M[5][5]);
        }
}

int compruebaMatriz(double M[5][5])
{
    int comprobador = 1;
    
    // comparo todas las posiciones del array para ver si son punto de silla
    for (int posFila = 0; posFila < 5; posFila++)
        for (int posColumna = 0; posColumna < 5; posColumna++)
            if(puntoSilla(&M[5], posFila, posColumna))
                return comprobador;
    
    comprobador = 0;
    
    return comprobador;
}

int puntoSilla(double mat[5][5], int posFila, int posColumna)
{
    int i, j, noenc=1;
    
    for(i = 0; i < 6 && noenc; i++)
        for(j = 0; j < 6 && noenc; j++)
            if(mat[posFila][posColumna] > mat[posFila][j] ||
               mat[posFila][posColumna] < mat[i][posColumna])
                noenc=0;
    
    return noenc;
}
