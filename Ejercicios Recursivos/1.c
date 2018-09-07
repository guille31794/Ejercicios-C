#include <stdio.h>

int mcdr(int , int, int);

int main(){
int a, b, aux;
printf("Introduzca dos numeros enteros: ");
scanf("%d %d", &a, &b);
printf("El mcd de %d y %d es %d", a, b, mcdr(a,b, aux));
return 0;
}

int mcdr( int n1, int n2, int aux){
if (n1<n2){
 aux = n1;
 n1 = n2;
 n2 = aux;
}
if(n1%n2 == 0)
    return n2;
else
    return mcdr(n2, n1%n2, aux);
}
