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
  printf("OK, file \"%s\" exists\n", argv[1]);

  return ok;
}

