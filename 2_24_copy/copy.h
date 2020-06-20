#ifndef COPY_H
#define COPY_H

enum status{
  fail,
  ok
};

extern enum status validate_arguments(int argc, char *argv[]);
#endif
