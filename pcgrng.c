#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "pcgrng.h"

static uint64_t pcg_state = 0x853c49e6748fea9bULL;
static uint64_t pcg_inc = 0xda3e39cb94b95bdbULL;

static uint64_t gen_seed() {
    uint64_t seed = 0;
    static uint64_t c = 0;
    seed ^= (uint64_t) time(NULL);
    seed ^= (uintptr_t) &memcpy;
    seed ^= c;
    uint64_t v1 = 1;
    seed ^= (uintptr_t) &v1;
    uint64_t *v2 = (uint64_t *) malloc(sizeof(uint64_t));
    if (v2 != NULL) {
        seed ^= (uintptr_t) v2;
        free(v2);
    }
    uint64_t v3 = 69; /* Nice */
    c += (uintptr_t) &malloc + v1;
    c ^= v3;
    return (seed ^ (uintptr_t) &v3) + v3;
}

void pcg_init() {
    pcg_state = 0U;
    pcg_inc = (gen_seed() << 1U) | 1U;
    pcg_rand();
    pcg_state += gen_seed();
    pcg_rand();

}

uint32_t pcg_rand() {
    uint64_t oldstate = pcg_state;
    pcg_state = oldstate * 6364136223846793005ULL + pcg_inc;
    uint32_t xorshifted = oldstate >> 27 ^ oldstate >> 45;
    uint32_t rot = oldstate >> 59U;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

float pcg_gauss() {
    return sqrtf(-2 * logf((float) pcg_rand() / (float) PCG_RAND_MAX)) *
           cosf(TWO_PI * (float) pcg_rand() / (float) PCG_RAND_MAX);
}

float pcg_randf() {
    return (float) pcg_rand() / (float) PCG_RAND_MAX;
}

uint32_t pcg_brand(uint32_t bound) {
    uint32_t threshold = -bound % bound;
    while(1) {
        uint32_t r = pcg_rand();
        if (r >= threshold) {
            return r % bound;
        }
    }
}