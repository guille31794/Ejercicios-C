#include <stdio.h>

void llenar_vr(int [], int, int);
int moda(int [], int, int, m);

int main(){
int num, i=0, mod=0;
printf("Introduzca un valor para n: ");
scanf("%d", num);
int vec[num];
llenar_vr(vec, num, i);
printf("\nLa moda es %d", moda(vec, num, i, mod));
return 0;}

void llenar_vr(int v[], int n, int i){
if(i=n)
    printf("\nIntroduzca un valor para el vector");
    printf("\nmayor o igual que el anterior");
    scanf("%d", v[i]);
else{
    printf("\nIntroduzca un valor para el vector");
    printf("\nmayor o igual al anterior: ");
    scanf("%d", &v[i]);
    return llenar_vr(v, n, i++);
    }
}

int moda(int v[], int n, int i, m){
if(i>=n)
    return m;
else
    if(v)

}
