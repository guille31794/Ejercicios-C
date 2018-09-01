#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define dartBoardX 2.0
#define dartBoardY 1.7
#define dartBoardXLimitRight 2.14
#define dartBoardXLimitLeft 1.86
#define dartBoardYLimitUp 1.84
#define dartBoardYLimitDown 1.56
#define firstCrownXRignt 2.112
#define firstCrownXLeft 1.888
#define firstCrownYUp 1.812
#define firstCrownYDown 1.588
#define secondCrownXRight 2.084
#define secondCrownXLeft  1.916
#define secondCrownYUp 1.784
#define secondCrownYDown 1.616
#define thirdCrownXRight 2.056
#define thirdCrownXLeft 1.944
#define thirdCrownYUp 1,756
#define thirdCrownYDown 1,644
#define fourthCrownXRight 2.028
#define fourthCrownXLeft 1.972
#define fourthCrownYUp 1.728
#define fourthCrownYDown 1.672

typedef struct Players
{
  char name[20];
  unsigned roundMarks;
  unsigned dartPoints[3];
  unsigned roundsWon;
} Player;

void initPlayers(Player *p1, Player *p2)
{
  printf("Set player 1 name: ");
  fflush(stdin);
  gets(p1 -> name);
  printf("Set player 2 name:");
  fflush(stdin);
  gets(p2 -> name);
  p1 -> roundsWon = 0;
  p2 -> roundsWon = 0;
}

void playerTurn(Player *p)
{
  unsigned i = 0;
  float coordinateX, coordinateY, epsilon = 0.0001;
  printf("%s your turn\n", p -> name);
  p -> roundMarks = 0;
  while(i < 3)
  {
    printf("Point your dart: ");
    scanf("%f", &coordinateX);
    printf("Adjust your dart height: ");
    scanf("%f", &coordinateY);
    printf("Shoot!\n");
    fflush(stdin);
    getchar();
    if((coordinateX <= dartBoardXLimitRight && coordinateX >= dartBoardXLimitLeft)
    && (coordinateY <= dartBoardYLimitUp && coordinateY >= dartBoardYLimitDown))
      if((coordinateX <= firstCrownXRignt && coordinateX >= firstCrownXLeft) &&
      (coordinateY <= firstCrownYUp && coordinateY >= firstCrownYDown))
      {
        if((coordinateX <= secondCrownXRight && coordinateX >= secondCrownXLeft) &&
        (coordinateY <= secondCrownYUp && coordinateY >= secondCrownYDown))
        {
          if((coordinateX <= thirdCrownXRight && coordinateX >= thirdCrownXLeft) &&
          (coordinateY <= thirdCrownYUp && coordinateY >= thirdCrownYDown))
          {
            if(((coordinateX <= fourthCrownXRight || fabs(fourthCrownXRight - coordinateX) < epsilon)
              && ((coordinateX >= fourthCrownXLeft) || fabs(coordinateX - fourthCrownXLeft) < epsilon)
              && ((coordinateY <= fourthCrownYUp || fabs(fourthCrownYUp - coordinateY) < epsilon)
              && (coordinateY >= fourthCrownYDown) || fabs(coordinateY - fourthCrownYDown) < epsilon)))
            {
              if((fabs(dartBoardX - coordinateX) < 0.009 && fabs(dartBoardY - coordinateY) < 0.009))
                p -> dartPoints[i] = 5;
              else
                p -> dartPoints[i] = 4;
            }
            else
              p->dartPoints[i] = 3;
          }
          else
            p->dartPoints[i] = 2;
        }
        else
          p->dartPoints[i] = 1;
      }
      else
        p->dartPoints[i] = 0;
    else
      p->dartPoints[i] = 0;

    printf("You've earned %d points\n", p->dartPoints[i]);

    p -> roundMarks += p -> dartPoints[i];

    ++i;
  }
}

void game(Player *p1, Player *p2)
{
  while(p1 -> roundsWon < 5 && p2 -> roundsWon < 5)
  {
    playerTurn(&*p1);
    playerTurn(&*p2);
    if(p1 -> roundMarks != p2 ->roundMarks)
      if(p1 -> roundMarks > p2 -> roundMarks)
      {
        ++p1 -> roundsWon;
        printf("Player 1 won this round. %d in total\n", p1 -> roundsWon);
      }
      else
      {
        ++p2 -> roundsWon;
        printf("Player 2 won this round. %d in total\n", p2 -> roundsWon);
      }
  }

  if(p1 -> roundsWon == 5)
    printf("Congratulations, %s, you win!\n", p1 -> name);
  else
    printf("Congratulations, %s, you win!\n", p2 -> name);
}

void darts()
{
  Player p1, p2;
  initPlayers(&p1, &p2);
  game(&p1, &p2);
}

int main()
{
  darts();
  return 0;
}
