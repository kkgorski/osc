#include <stdio.h>
#include <unistd.h>
#include "minunit.h"
#include "copy.h"

#define DATA_FILE_SIZE 1000
int tests_run = 0;
char * file_to_be_copied = "file1";

static void prepare_file_to_be_copied() {
  if(-1 != access(file_to_be_copied,F_OK|R_OK)){
    return;
  }else{
    char data[DATA_FILE_SIZE];
    for(unsigned i = 0; i < DATA_FILE_SIZE; ++i){
      data[i] = 'a' + i % 26;
    }
    FILE * file = fopen(file_to_be_copied, "w+");

    if(file == NULL)
    {
      perror("fopen");
      return;
    }
    fputs(data, file);
    fclose(file);
    printf("File created and saved successfully. :) \n");
  }
}

static char * test_validate_arguments() {
  int argc = 3;
  char *argv[3];
  argv[0] = "a.out";
  argv[1] = file_to_be_copied;
  argv[2] = "file2";
  prepare_file_to_be_copied();
  mu_assert("error, copy doesn't work", validate_arguments(argc, argv));
  remove(file_to_be_copied);
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
