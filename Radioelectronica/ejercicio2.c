#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void engineController()
{
  srand(time(NULL));
  FILE *engineLog;
  char turnOff = 's';
  int e1 = 100, e2 = 100, e3 = 100, msec;
  unsigned maxE1 = 0, maxE2 = 0, maxE3 = 0, shutDown = 0;
  time_t ts1, ts2, ts3, enLog;
  clock_t start, diff;

  engineLog = fopen("engineLog.txt", "a");

  printf("Started engined. All systems checked.\n");
  start = clock();

  while(turnOff != 'o' && turnOff != 'O')
  {
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;

    if(msec >= 120000)
    {
      fprintf(engineLog, "Engine 1 load is %d rpm\nEngine 2 load is %d rpm", e1, e2);
      fprintf(engineLog, "Engine 3 load is %d rpm\n", e3);
      engineLog = time(NULL);
      fprintf(engineLog, "Log-date: %s", ctime(&enLog));
      start = clock();
    }

    switch (turnOff)
    {
      case 't': e1+= (rand()%500 + 350); e2+= (rand()%500 + 350);
      e3+= (rand()%500 + 350);  break;
      case 'T': e1+= (rand()%500 + 350); e2+= (rand()%500 + 350);
      e3+= (rand()%500 + 350);  break;
      case 'b': e1-= (rand()%500 + 350); e2-= (rand()%500 + 350);
      e3-= (rand()%500 + 350); break;
      case 'B': e1-= (rand()%500 + 350); e2-= (rand()%500 + 350);
      e3-= (rand()%500 + 350); break;
      default: break;
    }

    if(e1 < 0)
      e1 = 0;
    if(e2 < 0)
      e2 = 0;
    if(e3 < 0)
      e3 = 0;

    if(e1 > maxE1)
    {
      maxE1 = e1;
      ts1 = time(NULL);
    }
    if(e2 > maxE2)
    {
       maxE2 = e2;
       ts2 = time(NULL);
    }
    if(e3 > maxE3)
    {
      maxE3 = e3;
      ts3 = time(NULL);
    }

    if(e1 <= 1500)
      printf("Engine 1 " ANSI_COLOR_BLUE "%d "  ANSI_COLOR_RESET "rpm\n", e1);
    if(e1 > 1500 && e1 <= 3000)
      printf("Engine 1 " ANSI_COLOR_GREEN "%d "  ANSI_COLOR_RESET "rpm\n", e1);
    if(e1 > 3000 && e1 <= 3500)
      printf("Engine 1 " ANSI_COLOR_YELLOW "%d "  ANSI_COLOR_RESET "rpm\n", e1);
    if(e1 > 3500)
      printf("Engine 1 " ANSI_COLOR_RED "%d "  ANSI_COLOR_RESET "rpm\n", e1);
    if(e2 <= 1500)
      printf("Engine 2 " ANSI_COLOR_BLUE "%d "  ANSI_COLOR_RESET "rpm\n", e2);
    if(e2 > 1500 && e2 <= 3000)
      printf("Engine 2 " ANSI_COLOR_GREEN "%d "  ANSI_COLOR_RESET "rpm\n", e2);
    if(e2 > 3000 && e2 <= 3500)
      printf("Engine 2 " ANSI_COLOR_YELLOW "%d "  ANSI_COLOR_RESET "rpm\n", e2);
    if(e2 > 3500)
      printf("Engine 2 " ANSI_COLOR_RED "%d "  ANSI_COLOR_RESET "rpm\n", e2);
    if(e3 <= 1500)
      printf("Engine 3 " ANSI_COLOR_BLUE "%d "  ANSI_COLOR_RESET "rpm\n", e3);
    if(e3 > 1500 && e3 <= 3000)
      printf("Engine 3 " ANSI_COLOR_GREEN "%d "  ANSI_COLOR_RESET "rpm\n", e3);
    if(e3 > 3000 && e3 <= 3500)
      printf("Engine 3 " ANSI_COLOR_YELLOW "%d "  ANSI_COLOR_RESET "rpm\n", e3);
    if(e3 > 3500)
      printf("Engine 3 " ANSI_COLOR_RED "%d "  ANSI_COLOR_RESET "rpm\n", e3);
    if(e1 > 4000)
    {
      printf(ANSI_COLOR_RED "DANGER! Engine 1 overheating. It will turnOff for security\n"
      ANSI_COLOR_RESET);
      e1 = 0;
    }
    if(e2 > 4000)
    {
      printf(ANSI_COLOR_RED "DANGER! Engine 2 overheating. It will turnOff for security\n"
      ANSI_COLOR_RESET);
      e2 = 0;
    }
    if(e3 > 4000)
    {
      printf(ANSI_COLOR_RED "DANGER! Engine 3 overheating. It will turnOff for security\n"
      ANSI_COLOR_RESET);
      e3 = 0;
    }
    if(!e1 && !e2 && !e3)
      break;

    printf("Throtle -> T\nBreak -> B\nTurn-off -> O\nMaintain speed -> Whatever other key\n");
    fflush(stdin);
    turnOff = getchar();
  }

  fprintf(engineLog, "Engine 1 max load was %d rpm at %s", maxE1, ctime(&ts1));
  fprintf(engineLog, "Engine 2 max load was %d rpm at %s", maxE3, ctime(&ts2));
  fprintf(engineLog, "Engine 3 max load was %d rpm at %s", maxE3, ctime(&ts3));
  fclose(engineLog);
  printf("Shutting down\n");
}

int main()
{
  engineController();
  return 0;
}
