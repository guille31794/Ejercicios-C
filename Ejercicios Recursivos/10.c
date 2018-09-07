//Ejercicio 10

#include <stdio.h>

//Cabecera: vector n de max enteros
//precondicion: max inicializado
//Postcondicion: devuelve el vector lleno recursivamente

void llenar_vr(int [], int , int);

//Cabecera: int [], int, int
//Precondicion: vector con datos
//Postcondicion: devuelve A[a]=A[n-a+1]

void funcion_r(int [], int, int);

int main(){

//Declaracion del vector y su tamaño por parte del usuario

int max, aux=0;
printf("Introduzca el tamaño del vector: ");
scanf("%d", &max);
int vec[max];

//Llenado del vector

llenar_vr(vec, max, aux);

//Resolucion del problema
if(max%2==0)
    aux=max/2;
else
    aux=(max/2)+1;
funcion_r(vec, max, aux);
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

//Funcion que resuelve el problema

void funcion_r(int A[], int n, int a){
if(a<=1)
    if(A[a]==A[n-a+1])
        printf("\nPara a = %d, se cumple la igualdad", a);
    else
        printf("\nPara a = %d, no se cumple la igualdad", a);
else
    {if(A[a]==A[n-a+1])
        printf("\nPara a = %d, se cumple la igualdad", a);
    else
        printf("\nPara a = %d, no se cumple la igualdad", a);
    return funcion_r(A, n, a-1);
    }
}
