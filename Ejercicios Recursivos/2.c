#include <stdio.h>

int cifras(int, int);

int main(){
int num, con=1;
do{
    printf("Introduzca numero en base 10: ");
    scanf("%d", &num);}
while(num%10 != 0);
printf("\nEl numero de cifras de %d es %d", num, cifras(num, con));
return 0;
}

int cifras(int n, int c){
if(n/10 == 1 && n>=10)
    return c+1;
else
    return c + cifras(n/10, c);
}
