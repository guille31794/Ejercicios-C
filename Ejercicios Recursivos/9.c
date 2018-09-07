//Ejercicio 9

#include <stdio.h>

//Cabecera: vector n de max enteros
//precondicion: max inicializado
//Postcondicion: devuelve el vector lleno recursivamente

void llenar_vr(int [], int , int);

//Cabecera: int [], int, int
//Precondicion: vector con datos
//Postcondicion: devuelve sumatorio condicionado

void sum_r(int [], int, int);

int main(){

//Declaracion del vector y su tamaño por parte del usuario

int max, aux=0;
printf("Introduzca el tamaño del vector: ");
scanf("%d", &max);
int vec[max];

//Llenado del vector

llenar_vr(vec, max, aux);

//Resolucion del problema

sum_r(vec, max, aux);

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

//Calculo de las sumas

void sum_r(int v[], int n, int i){
if(i>(n/2)+1)
    printf("\n");
else
    switch(v[i]){
    case v[i]>v[2*i]: printf("\n%d + %d = %d", v[i], v[2*i], v[i]+v[2*i]);
    sum_r(v, n, i+1);
    break;
    case v[i]>v[(2*i)+1]: printf("\n%d +%d = %d", v[i], v[(2*i)+1]);
    sum_r(v, n, i+1);
    break;
    default;
    }
sum_r(v, n, i+1);
}
