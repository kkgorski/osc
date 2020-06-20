#include <stdio.h>
#include "minunit.h"
#include "copy.h"

int tests_run = 0;

static char * test_validate_arguments() {
  int argc = 3;
  char *argv[3];
  argv[0] = "a.out";
  argv[1] = "file1";
  argv[2] = "file2";
  mu_assert("error, copy doesn't work", validate_arguments(argc, argv));
  return 0;
}

static char * all_tests() {
  mu_run_test(test_validate_arguments);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if(result != 0){
    printf("%s\n", result);
  }
  else{
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
