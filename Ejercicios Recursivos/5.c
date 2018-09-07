#include <stdio.h>

int conjunto(int, int, int);

int main(){
int num, conj, cont=0;
printf("Introduzca numero de personas: ");
scanf("%d", &num);
printf("\nIntroduzca peronas por conjunto: ");
scanf("%d", &conj);
printf("\nEl numero de conjuntos que se pueden formar es %d", conjunto(num, conj, cont));
return 0;
}

int conjunto(int n, int k, int c){
if (n == k || k == 0)
  return c+1;
else
  return conjunto(n-1, k, c)+ conjunto(n-1, k-1, c);
}
