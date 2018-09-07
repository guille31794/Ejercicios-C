//
//  main.c
//  Examen
//
//  Created by Guillermo Girón García on 31/5/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

/*
    Cabecera: int primitiva(int [])
    Precondicion: se le pasa un vector de tamaño 7
    Postcondicion: te devuelve el número de premio que has ganado o 0 si no toca nada
*/

int primitiva(int []);

/*
    Cabecera:   void hacerApuesta(int [])
    Precondición:   Necesita un vector de tamaño 6
    Postcondición:  Llena el vector con las apuestas indicadas por el usuario
*/

void hacerApuesta(int []);

/*
    Cabecera: void sorteo(int* v)
    Precondicion: recibe el vector de apuestas
    Postcondición: devuelve el premio ganado
*/

int sorteo(int*, int* );

/*
    Cabecera: void imprimePremio(int)
    Precondición: recibe el premio como parametro
    Postcondicion: imprime por pantalla el resultado
*/

void imprimePremio(int);


 /*int main()
{
    int apuestas[6];
    int premio;
    
    hacerApuesta(apuestas);
    premio = primitiva(apuestas);
    
    imprimePremio(premio);
    
    return 0;
}*/


void hacerApuesta(int v[])
{
    int i = 0;
    
    while(i < 6)
    {
        printf("\nIntroduzca apuesta %d: ", i+1 );
        scanf("%d", &v[i]);
        
        /*
            Condiciones que comprueban que no se repitan las apuestas
        */
        
        for (int j = 0; j < i; ++j)
        {
            if (v[j] == v[i])
            {
                printf("\nError, apuesta repetida, repetir.");
                v[i] = -1;
            }
        }
        
        if(v[i] < 50 && v[i] > (-1))
            ++i;
    }
    
}

int primitiva(int apuesta[])
{
    int bolasSorteo[7];
    int premio;
    
    premio = sorteo(bolasSorteo, apuesta);
    
    return premio;
}

int sorteo(int* bolasSorteo, int* apuesta)
{
    int premio = 0;
    int cont = 0;
    
    /*
        El complementario será la septima bola del vecotr bolasSorteo
    */
    
    int complementario = 0;
    
    /*
        Genero numeros pseudoaleatorios entre 0 y 49
    */
    
    srand(time(NULL));
    
    int i = 0;
    
    while(i < 7)
    {
        bolasSorteo[i] = rand() % 50;
        
    /*
        Condiciones que comprueban que no se repiten apuestas
    */
        
        for (int j = 0; j < i; ++j)
        {
            if (bolasSorteo[j] == bolasSorteo[i])
                bolasSorteo[i] = -1;
        }
        
        if(*(bolasSorteo+i) < 50 && *(bolasSorteo+i) > -1)
            ++i;
    }
    
    printf("\nSus apuestas son: ");
    
    for (int i = 0; i < 6; ++i)
    {
        printf(" %d", apuesta[i]);
    }
    
    printf("\nEl numero premiado es el: ");
    
    for (int i = 0; i < 7; ++i)
    {
        printf(" %d", bolasSorteo[i]);
    }
    
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < 7; ++j)
        {
            if (apuesta[i] == bolasSorteo[j] && cont < 6)
                ++cont;
            if(cont == 5 && j == 7 && apuesta[i] == bolasSorteo[j])
                ++complementario;
        }
    
    /*
        Condiciones que adaptan el resultado del sorteo a nuestra escala de premios
    */
    
    if(complementario && cont == 6)
        premio = 6;
    else if(cont >= 6)
            premio = 7;
        else
            premio = cont;
    
    return premio;
}


//Cambia aqui los numeros de los premios

void imprimePremio(int premio)
{
    /*
        No cuenta el complementario para premio, por lo tanto
        el primer premio serian 7 bolas en lugar de 6 y el segundo las 6, haciendo un simil a 5 bolas + complementario
     */
    
    switch (premio)
    {
        case 7: printf("\nEnhorabuena, te ha tocado el gordo\n");
            break;
        case 6: printf("\nEnhorabuena, te ha tocado el segundo premio\n");
            break;
        case 5: printf("\nEnhorabuena, te ha tocado un tercer premio\n");
            break;
        case 4: printf("\nEnhorabuena, te ha tocado un cuarto premio\n");
            break;
        case 3: printf("\nEnhorabuena, te ha tocado un quinto premio\n");
            
        default: printf("\nResguardo no premiado\n");
            break;
    }
}
