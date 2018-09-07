#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void carga(FILE *f, char nombrecito[], int m[][3]);
void showMatrix(int m[][3]);

int main()
{
  FILE *f;
  char matriz[3][3];
  char nombrecito[50];

  carga(f, nombrecito, matriz);

  showMatrix(matriz);

  return 0;
}

void carga(FILE *f, char nombrecito[], int m[][3])
{
  char v[30];
  int i, j;

  i = 0;
  j = 0;

  printf("\rIntroduzca nombre del ficherito: " );
  scanf("%s", nombrecito);

  f = fopen(nombrecito, "r");

  if(f == NULL)
  {
    printf("\nError en la apertura del ficherito. Hasta lueguito =)" );
    exit(1);
  }

  while (i < 3)
  {
    while (j < 3)
    {

      m[i][j] = fgetc(f);
      printf("%d", m[i][j]);
      ++j;

      if(feof(f))
        break;
    }

      ++i;
  }

  for(i = 0; i < 3; ++i)
    for (j = 0; j < 3; i++)
    {
        printf("%d", m[i][j]);
    }

  fclose(f);
}

void showMatrix(int m[][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
    putchar('|');

    for(j = 0; j < 3; j++)
    {
      printf("%d", m[i][j] );
    }

    printf("\b|\n" );
  }
}
