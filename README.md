# get_next_line-gmoreira
A function to print the first line of a file and forth.

O objetivo desse projeto é tornar possível a extração de linha por linha de um arquivo qualquer, usando o bônus podemos abrir mais um arquivo por vez com o limite de 253 arquivos

Para compilar é necessário chamar os .c respectivos de cada parte juntamente com a main.c <br>
Exemplo:
```
#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main()
{
  char *path;
  char *result
  int fd;
  
  path = "./shrek";
  fd = open(path, O_RDONLY);
  while((result = get_next_line(fd)) != NULL)
  {
    printf("%s", result);
    free(result);
  }
}
```
Para compilar é necessário digitar no bash

```
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```
