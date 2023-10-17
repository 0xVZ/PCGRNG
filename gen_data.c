#include <stdio.h>
#include <stdlib.h>
#include "pcgrng.h"


int main() {
    pcg_init();

    FILE *gauss_file = fopen("gauss_10mill.txt", "w");
    FILE *rand_file = fopen("rand_10mill.txt", "w");
    FILE *randf_file = fopen("randf_10mill.txt", "w");

    for (int i = 0; i < 10000000; ++i) {
        fprintf(gauss_file, "%f\n", pcg_gauss());
        fprintf(rand_file, "%u\n", pcg_rand());
        fprintf(randf_file, "%f\n", pcg_randf());
    }

    fclose(gauss_file);
    fclose(rand_file);
    fclose(randf_file);
    return 0;
}