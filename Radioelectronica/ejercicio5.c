#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int leerBatimetriaMensual(FILE *f, float medidas[][10])
{
  char* buffer;
  char* pch;
  unsigned incompleteMonth, i = 0, j = 0, counter = 0;
  long lSize;
  size_t result;

  f = fopen("batimetry.txt", "r");
  if(f == NULL) { fputs ("File error", stderr); exit(1);}

  fseek(f, 0, SEEK_END);
  lSize = ftell(f);
  rewind(f);
  buffer = (char*) malloc(sizeof (char)*lSize);
  if(buffer == NULL)  {fputs("Memory error", stderr); exit(2);}

  result = fread(buffer, 1, lSize, f);
  //if(result != lSize) { fputs("Reading error", stderr); exit(3);}

  pch = strtok(buffer, " \n");
  while (pch != NULL)
  {
    medidas[i][j] = atof(pch);
    pch = strtok(NULL, " \n");
    ++j;
    ++counter;
    if(i > 29 && j > 9)
    {
      i = 0;
      break;
    }
    if(j > 9) { j = 0; ++i;}
  }

  if(i < 29 && i > 0)
    incompleteMonth = 0;

  for(i = 0, j = 0; j < 10 && i < 29 && counter > 1; ++j)
  {
    printf("%f\n", medidas[i][j]);
    --counter;
    if(j > 9) { j = 0; ++i;}
  }

  fclose(f);
  free(buffer);

  return incompleteMonth;
}

void dailyData(float measures[][10])
{
  FILE *f;
  float max = 0, min = 99999, average = 0;
  unsigned i, j;

  f = fopen("dailyData.txt", "a");
  for(i = 0; i < 29; ++i)
  {
    for(j = 0; j < 9; ++j)
    {
      if(measures[i][j] < min)
        min = measures[i][j];
      if(measures[i][j] > max)
        max = measures[i][j];
      average += measures[i][j];
    }

    average /= 10;
    printf("Maximum: %f\nMinimun: %f\nAverage: %f\n", max, min, average);
    fprintf(f, "Maximum: %f\nMinimun: %f\nAverage: %f", max, min, average );
    average = 0;
    max = 0;
    min = 9999;
  }
  fclose(f);
}

void batimetryForLocation(float measures[][10])
{
  FILE *f;
  unsigned i, j;
  float max = 0, min = 9999, average = 0;

  f = fopen("batimetryForLocation.txt", "a");

  for(j = 0; j < 9; ++j)
  {
    for(i = 0; i < 29; ++i)
    {
      if(measures[i][j] > max)
        max = measures[i][j];
      if(measures[i][j] < min)
        min = measures[i][j];
      average+= measures[i][j];
    }

    average /= 30;
    printf("Maximum: %f\nMinimun: %f\nAverage: %f\n", max, min, average);
    fprintf(f, "Maximum: %f\nMinimun: %f\nAverage: %f", max, min, average );
    average = 0;
    max = 0;
    min = 9999;
  }

  fclose(f);
}

void batimetryForYears(float measures[][30][10], unsigned k)
{
  FILE *f;
  unsigned i, j, n;
  float max = 0, min = 9999, average = 0;

  f = fopen("batimetryForYears.txt", "a");

  for(j = 0; j < 9; ++j)
  {
    for(n = 0; n < k; ++n)
    {
      for(i = 0; i < 29; ++i)
      {
        if(measures[n][i][j] > max)
          max = measures[n][i][j];
        if(measures[n][i][j] < min)
          min = measures[n][i][j];
        average+= measures[n][i][j];
      }
    }

    average /= (k*30);
    printf("Maximum: %f\nMinimun: %f\nAverage: %f\n", max, min, average);
    fprintf(f, "Maximum: %f\nMinimun: %f\nAverage: %f", max, min, average );
    average = 0;
    max = 0;
    min = 9999;
  }


  fclose(f);
}

int main()
{
  FILE *f;
  float measures[30][10];
  float measuresForYears[10][30][10];
  unsigned monthlyData = 1, i = 0, j = 0, k = 0;

  while(monthlyData)
  {
    monthlyData = leerBatimetriaMensual(f, measures);
    printf("Data for days: \n");
    dailyData(measures);
    printf("\nDatas for locations:\n\n");
    batimetryForLocation(measures);
    for(i = 0; i < 29; ++i)
      for(j = 0; j < 9; ++j)
        measuresForYears[k][i][j] = measures[i][j];

    ++k;
  }

  printf("\nDatas for years:\n\n");
  batimetryForYears(measuresForYears, k);


  return 0;
}
