#include <stdio.h>
#include <unistd.h>
#include "copy.h"

enum status validate_arguments(int argc, char *argv[])
{
  if(3 != argc){
    printf("Wrong number of arguments\n");
    return fail;
  }

  if(-1 == access(argv[1],F_OK|R_OK)){
    printf("File to be copied \"%s\" does not exist!!!\n", argv[1]);
    return fail;
  }

  return ok;
}

enum status copy(int argc, char *argv[])
{
  FILE * from = fopen(argv[1], "r");
  FILE * to = fopen(argv[2], "w+");
  if(!from || !to)
    return fail;

  int character = 0;
  while(EOF != character){
    character = fgetc(from);
    if(EOF != character){
      fputc(character, to);
    }
  }

  return ok;
}

