//Ejercicio 12

#include <stdio.h>

//Cabecera: vector n de max enteros
//precondicion: max inicializado
//Postcondicion: devuelve el vector lleno recursivamente

void llenar_vr(int [], int , int);

//Cabecera: int [], int, int
//Precondicion: vector con datos
//Postcondicion: devuelve A[a]=A[n-a+1]

int parejas_r(int [], int, int, int, int, int, int, int);

int main(){

//Declaracion del vector y su tamaño por parte del usuario

int max, aux=0, cor_j=1, cor_k=1, aux1=0, aux2=0, cont=0;
printf("Introduzca el tamaño del vector: ");
scanf("%d", &max);
int vec[max];

//Llenado del vector

llenar_vr(vec, max, aux);

//Resolucion del problema
aux=1;
printf("\nEl numero de parejas es %d", parejas_r(vec, max, aux, cor_j, cor_k, aux1, aux2, cont));
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

int parejas_r(int A[], int n, int i, int j, int k, int aux_j, int aux_k, int c){
if(j>n)
    return c;
else
    {
    aux_j=aux_j+A[i];
    if(i<j)
        return parejas_r(A, n, i+1, j, k, aux_j, aux_k, c);
    i=1;
    if(k<n){
        aux_k=aux_k+A[k];
        if(aux_j==aux_k){
        c++;
        printf("\nEl par (%d,%d) es pareja", j,k);
        }
       return parejas_r(A, n, i, j, k+1, aux_j, aux_k, c);
    }
return parejas_r(A, n, i, j+1, k=1, aux_j=0, aux_k=0, c);
}
}
