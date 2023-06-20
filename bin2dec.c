/* Author: Gabriel Proença Alves
 *
 * Year: 2023
 *
 * O objetivo deste programa é a
 * conversão de binários em decimais
 * e vice versa.
 */

/*
 * Adicionar suporte a parâmetros,
 * ex. -btd e dtb.
 */

#include <stdio.h>
#include <string.h>
#define byte_t unsigned char
#define BTD 0
#define DTB 1

void dtb(unsigned long);
void btd(unsigned long);

int main(int argc, char* argv[])
{
  byte_t convtype = DTB; /* Guarda o tipo de conversão */
  unsigned long input; /* guarda o número de entrada */

  /* Verifica se o argumento '-btd'
     foi especificado */
  if (argc == 2)
    if (strcmp(argv[1], "-btd") == 0)
      convtype = BTD;

  puts("Bin2Dec, Gabriel Proença Alves (C) 2023");
  puts("Para sair, digite \"sair\"");

  while (scanf("%lu", &input)) {
    printf("--> ");
    (convtype == DTB) ? dtb(input) : btd(input);
  }

  return 0;
}

void dtb(unsigned long n)
{
  /* Atribui o valor de 2^64 a x, que no C89,
     é o maior valor positivo possível */
  unsigned long x = ~0;

  /* "Empurra" os bits de x uma casa a direita */
  x >>= 1;

  /* Inverte os bits de x */
  x = ~x;

  /* Percorre todas as casas
     até econtrar um bit positivo */
  while ((n & x) == 0)
    x >>= 1;

  /* Após encontrar, a função imprime
     o numero 1 se for positivo, senao,
     imprime 0 */
  do {
    putchar((n & x) ? '1' : '0');
  } while ((x >>= 1) > 0);

  /* Ao final, imprime uma quebra de linha */
  putchar('\n');
}

void btd(unsigned long n)
{
  unsigned long i = 1;
  unsigned long x = 0;

  while (n > 0) {
    x += (n % 10) * i;
    n /= 10;
    i <<= 1;
  }

  return;
}
