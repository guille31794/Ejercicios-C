//
//  examen.c
//  Examen
//
//  Created by Guillermo Girón García on 15/6/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "cajero.h"

int leeDatos(int *v)
{
  srand(time(NULL));
  int l = -1, i;

  while(l < 0)
  {
      printf("Introduzca tamaño de la cola: ");
      scanf("%d", &l);
  }

    v = (int*)malloc(l);

    for(i = 0; i < l; ++i)
      v[i] = rand()%5+1;

  return l;
}

int simulacion(int l, int v[])
{
    int t = 0;

    for(int i = 0; i < l; ++i)
        t+= *v+i;

    return (t/2);
}

void escribeTiempo(int t)
{
    printf("El tiempo total que tarda en despejarse la cola es %d\n", t);
}

void cajero()
{
    int l, t;
    int v[2];

    l = leeDatos(v);
    t = simulacion(l, v);
    escribeTiempo(t);
}

int main()
{
    cajero();
    return 0;
}
