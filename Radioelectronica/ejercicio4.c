#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct Products
{
  char name[50];
  unsigned stock;
  double price;
} Product;

typedef struct Coins
{
  double value;
  unsigned stock;
} Coin;

void refillProducts(Product *p)
{
  strcpy(p[0].name, "Coke");
  p[0].stock = 10;
  p[0].price = 1.0;
  strcpy(p[1].name, "Seven Up");
  p[1].stock = 8;
  p[1].price = 1.0;
  strcpy(p[2].name, "Ice tea");
  p[2].stock = 4;
  p[2].price = 0.95;
  strcpy(p[3].name, "Water");
  p[3].stock = 1;
  p[3].price = 0.5;
  strcpy(p[4].name, "Beer");
  p[4].stock = 2;
  p[4].price = 0.8;
  strcpy(p[5].name, "Coffe");
  p[5].stock = 0;
  p[5].price = 0.65;
  strcpy(p[6].name, "Vegetale Sandwich");
  p[6].stock = 3;
  p[6].price = 2.25;
  strcpy(p[7].name, "Spanish omelete Sandwich");
  p[7].stock = 4;
  p[7].price = 2.1;
  strcpy(p[8].name, "Hamburguer");
  p[8].stock = 1;
  p[8].price = 3.0;
  strcpy(p[9].name, "Margarita pizza slice");
  p[9].stock = 8;
  p[9].price = 3.25;
  strcpy(p[10].name, "Chicken steak baguette");
  p[10].stock = 0;
  p[10].price = 3.5;
  strcpy(p[11].name, "Energetic Bar");
  p[11].stock = 2;
  p[11].price = 1.5;
}

void refillExchange(Coin *c)
{
  c[0].value = 2.0;
  c[0].stock = 2;
  c[1].value = 1.0;
  c[1].stock = 4;
  c[2].value = 0.5;
  c[2].stock = 5;
  c[3].value = 0.2;
  c[3].stock = 2;
  c[4].value = 0.1;
  c[4].stock = 1;
  c[5].value = 0.05;
  c[5].stock = 6;
  c[6].value = 0.02;
  c[6].stock = 10;
  c[7].value = 0.01;
  c[7].stock = 20;
}

void Menu(Product *p)
{
  printf("\n24h. Food&Drinks\nSelect product to see conditions:\n");
  printf("1.- %s\n2.- %s\n3.- %s\n4.- %s\n5.- %s\n6.- %s\n",
  p[0].name, p[1].name, p[2].name, p[3].name, p[4].name, p[5].name);
  printf("7.- %s\n8.- %s\n9.- %s\n10.- %s\n11.- %s\n12.- %s\n", p[6].name,
  p[7].name, p[8].name, p[9].name, p[10].name, p[11].name);
  printf("Select: ");
}

int payment(Product *p, unsigned option, Coin *c, double price)
{
  double coin;
  unsigned i = 0, possible;
  unsigned coinVector[8] = {0, 0, 0, 0, 0, 0, 0, 0};


  while(price > 0.01)
  {
    printf("\nOnly coins accepted: 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01\n");
    printf("\nPrice: %f\nInsert coin: ", price);
    fflush(stdin);
    scanf("%lf", &coin);

    if(coin == 2.0) price -= 2.0;
    if(coin == 1.0) price -= 1.0;
    if(coin == 0.50) price -= 0.50;
    if(coin == 0.20) {price -= 0.20;}
    if(coin == 0.10) price -= 0.10;
    if(coin == 0.05) price -= 0.05;
    if(coin == 0.02) price -= 0.02;
    if(coin == 0.01) price -= 0.01;
  }

  price*=(-1);

  while(i < 8 && c[i].stock != 0 && price != 0.00)
  {
    if(fabs(price - c[i].value) < 0.00001 || price >= c[i].value)
    {
      ++coinVector[i];
      price -= c[i].value;
    }
    else
      ++i;
  }

  i = 0;

  if(price <= 0.00)
  {
    possible = 1;
    while(i < 8)
    {
      if(coinVector[i] > 0)
      {
        printf("Returning %d coins of %f\n", coinVector[i], c[i].value);
        coinVector[i] = 0;
      }

      ++i;
    }
  }
  else
    possible = 0;

  fflush(stdin);
  getchar();
  return possible;
}

void Order(Product *p, unsigned option, Coin *c, FILE *incidents)
{
  unsigned possible;

  --option;
  if(p[option].stock > 0)
  {
    printf("Selected %s", p[option].name );
    possible = payment(p, option, c, p[option].price);
  }
  else
  {
    printf("Run out of stock\n");
    fprintf(incidents, "%s without stock\n", p[option].name );
    fflush(stdin);
    getchar();
  }

  if(possible)
  {
    --p[option].stock;
    printf("Don't forget your %s\n", p[option].name);
  }

}

void vendingMachine()
{
  unsigned option = 1;
  Product p[12];
  Coin c[8];
  FILE *incidents;

  incidents = fopen("incidents.txt", "a");
  refillProducts(p);
  refillExchange(c);

  while(option)
  {
    Menu(p);
    scanf("%d", &option);
    if(option > 0 && option < 13)
      Order(p, option, c, incidents);
    else
    {
      printf("See you soon\n");
      fclose(incidents);
      exit(0);
    }
  }

  fclose(incidents);

}

int main(int argc, char const *argv[])
{
  vendingMachine();

  return 0;
}
