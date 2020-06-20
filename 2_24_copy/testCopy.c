#include <stdio.h>
#include <unistd.h>
#include "minunit.h"
#include "copy.h"

#define DATA_FILE_SIZE 1000
int tests_run = 0;
char * from = "file1";
char * to = "file2";

static void prepare_from() {
  if(-1 != access(from,F_OK|R_OK)){
    return;
  }else{
    char data[DATA_FILE_SIZE];
    for(unsigned i = 0; i < DATA_FILE_SIZE; ++i){
      data[i] = 'a' + i % 26;
    }
    FILE * file = fopen(from, "w+");

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

static enum status compare_files() {
  if((-1 == access(from,F_OK|R_OK)) || (-1 == access(to,F_OK|R_OK))){
    return fail;
  }
  FILE * source = fopen(from, "r");
  FILE * destination = fopen(to, "w+");
  if(!source || !destination)
    return fail;

  int character_source = 0;
  int character_destination = 0;
  while((EOF != character_source) || (EOF != character_destination)){
    character_source = fgetc(source);
    character_destination = fgetc(destination);
    if(character_source != character_destination){
      return fail;
    }
  }

  return ok;
}

static char * test_validate_arguments() {
  int argc = 3;
  char *argv[3];
  argv[0] = "a.out";
  argv[1] = from;
  argv[2] = to;
  prepare_from();
  mu_assert("error, copy doesn't work", validate_arguments(argc, argv));
  remove(from);
  return 0;
}

static char * test_copy() {
  int argc = 3;
  char *argv[3];
  argv[0] = "a.out";
  argv[1] = from;
  argv[2] = to;
  prepare_from();
  mu_assert("error, copy doesn't work", copy(argc, argv));
  mu_assert("error, compared files are not equal", compare_files);
  remove(from);
  remove(to);
  return 0;
}

static char * all_tests() {
  mu_run_test(test_validate_arguments);
  mu_run_test(test_copy);
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
