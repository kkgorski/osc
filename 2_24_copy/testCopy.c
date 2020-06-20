#include <stdio.h>
#include "minunit.h"

int tests_run = 0;

static char * test_copy() {
    mu_assert("error, copy doesn't work", 0);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_copy);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
