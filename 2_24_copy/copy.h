#ifndef COPY_H
#define COPY_H

enum status{
  fail,
  ok
};

extern enum status validate_arguments(int argc, char *argv[]);
extern enum status copy(int argc, char *argv[]);
#endif
