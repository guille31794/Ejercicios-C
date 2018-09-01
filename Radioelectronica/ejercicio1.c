#include "stdio.h"
#include "stdlib.h"

typedef struct Employees
{
  unsigned salary, hours, extraHours, total;
} Employee;

void initEmployees(Employee *e)
{
  e[0].salary = 15;
  e[0].hours = 10;
  e[0].total = 0;
  e[1].salary = 20;
  e[1].hours = 50;
  e[1].total = 0;
  e[2].salary = 25;
  e[2].hours = 35;
  e[2].total = 0;
}

void accounting(Employee *e, unsigned companySize)
{
  FILE *accounting;
  unsigned total = 0;

  accounting = fopen("accounting.txt", "w");

  for(unsigned i = 0; i < companySize; ++i)
  {
    if(e[i].hours > 40)
    {
      e[i].extraHours = e[i].hours - 40;
      e[i].hours -= e[i].extraHours;
      e[i].total = ((e[i].salary * 0.5) + e[i].salary) * e[i].extraHours;
      fprintf(accounting, "Employee %d earn %d for extra hours\n", i+1, e[i].total);
    }

    e[i].total += e[i].salary * e[i].hours;
    fprintf(accounting, "Employee %d earn %d in total\n", i+1, e[i].total);
    total += e[i].total;
  }

  fprintf(accounting, "The company expend %d in total\n", total);
  fclose(accounting);
}

int main(int argc, char const *argv[])
{
  Employee e[3];
  unsigned companySize = sizeof(e)/(sizeof(unsigned)*4);

  initEmployees(e);
  accounting(e, companySize);

  return 0;
}
