//Ejercicio 8

#include <stdio.h>

//Cabecera: vector n de max enteros
//precondicion: max inicializado
//Postcondicion: devuelve el vector lleno recursivamente

void llenar_vr(int [], int , int);

//Cabecera: vector, tamaño del vector, k, y variable auxiliar
//Precondicion: vector y variables inicializadas
//Postcondicion: intercambia los k primeros elementos del vector con los k ultimos

void intercambio(int [], int, int, int);

//Cabecera: vector, tamaño maximo, indice
//Precondicion: vector inicializado y con datos
//Postcondicion: imprime por pantalla los elementos del vector

void print_vr(int [], int, int);

int main(){
//Declaración del vector y su tamaño por parte del usuario
int max, k, aux=0;
printf("Introduzca el tamaño maximo del vector: ");
scanf("%d", &max);
int n[max];
//Llenado del vector
llenar_vr(n, max, aux);
//Solicitud para valor de k
printf("\nIntroduzca cuantos elementos desea intercambiar: ");
scanf("%d", &k);
//Representacion del resultado del programa
intercambio(n, max, k, aux);
print_vr(n, max, aux);
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

//Procedimiento que resuelve el problema
void intercambio(int v[], int n, int k, int aux){
if(k == 0){
   printf("\nCambio realizado con exito");
  }
else{
  aux=v[n-k];
  v[n-k]=v[k-1];
  v[k-1]=aux;
  intercambio(v, n, k-1, aux);
}
}

//Representacion por pantalla del cambio realizado
void print_vr(int v[], int n, int i){
if(i==n-1)
    printf("\n %d ", v[i]);
else{
    printf("\n %d ", v[i]);
    return print_vr(v, n, i+1);
    }
}
