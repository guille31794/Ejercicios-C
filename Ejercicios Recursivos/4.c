#include <stdio.h>

void llenar_vr(int [], int, int);
int suma_pareja(int [], int, int, int);

int main(){
int num, in=0, con=0;
printf("Introduzca un cuantos numeros tendrá el vector: ");
scanf("%d", &num);
int vec[num];
llenar_vr(vec, num, in);
if (suma_pareja(vec, num, in, con)== 1)
  printf("\nLa suma de parejas es identica");
else
  printf("\nLa suma de parejas no es identica");
return 0;
}

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

int suma_pareja(int v[], int n, int i, int a){
if((v[i]+v[i+1]) == (v[i+2]+v[i+3]))
  return a+1;
else
  if(i+3>n)
    return a;
  else
    return suma_pareja(v, n, i+1, a);
}
