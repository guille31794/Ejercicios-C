//Ejercicio 6

#include <stdio.h>

//Cabecera: vector n de max enteros
//Precondicion: max inicializado
//Postcondicion: devuelve el vector lleno recursivamente

void llenar_vr(int [], int , int);

//Cabecera: vector, tamaño e indice
//Precondicion: variables inicializadas y vector lleno
//Postcondicion: devuelve la escalera mas larga

int escalera(int [], int, int, int);

int main(){

//Declaracion de variables y del vector

int max, aux=0, lng;
printf("Introduzca tamaño para el vector: ");
scanf("%d", &max);
int vec[max];
printf("\nIntroduzca los elementos del vector de manera creciente");
llenar_vr(vec, max, aux);

//Solucion del problema

printf("\nLa longitud de la escalera mas larga es: %d", escalera(vec, max, aux, lng));
return 0;
}

//LLenado del vector de forma recursiva

void llenar_vr(int v[], int n, int i){
if(i==n-1){
    printf("\nIntroduzca un valor para el vector: ");
    scanf("%d", &v[i]);}
else{
    printf("\nIntroduzca un valor para el vector: ");
    scanf("%d", &v[i]);
    return llenar_vr(v, n, i+1);
    }
}

//Calculo de la escalera mas larga

int escalera(int A[], int n, int i, int l){
if(n==0){
    if(i<l)
        return l+1;
}
else
        if(A[n]==A[n-1]+1){
            i++;
            if(i>l)
            l=i;
        }
        else{
            i=0;
        }
        return escalera(A, n-1, i, l);
}
