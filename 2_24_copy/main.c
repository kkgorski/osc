#include "copy.h"

int main(int argc, char *argv[]) {
  if(ok == validate_arguments(argc, argv)){
    copy(argc, argv);
  }
  return 0;
}
