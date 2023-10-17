#ifndef __PCGRNG_H__
#define __PCGRNG_H__

#include <inttypes.h>

#define TWO_PI 6.2831853072
#define PCG_RAND_MAX 0xFFFFFFFF


/**
 * @brief Initializes the PCG random number generator with a seed.
 *
 * This function initializes the PCG random number generator with a seed generated
 * using the internal `gen_seed` function. It also calls the `pcg_rand` function to further
 * randomize the generator state.
 */
void pcg_init();


/**
 * @brief Generates a 32-bit pseudo-random integer using the PCG algorithm.
 * 
 * This function generates a pseudo-random integer using the PCG algorithm.
 * 
 * @return 32-bit pseudo-random integer.
 */
uint32_t pcg_rand();


/**
 * @brief Generates a pseudo-random number from a standard normal distribution using the PCG generator.
 * 
 * This function generates a pseudo-random number from a standard normal distribution using the PCG generator.
 * 
 * @return Pseudo-random number from a standard normal distribution.
 */
float pcg_gauss();


/**
 * @brief Generates a pseudo-random float in the range [0, 1) using the PCG algorithm.
 * 
 * This function generates a pseudo-random float in the range [0, 1) using the PCG algorithm.
 * 
 * @return Pseudo-random float in the range [0, 1).
 */
float pcg_randf();


/**
 * @brief Generates a pseudo-random integer in the range [0, bound) using the PCG algorithm.
 * 
 * This function generates a pseudo-random integer in the range [0, bound) using the PCG algorithm.
 * 
 * @param bound Upper bound (exclusive) for the generated random number.
 * @return Pseudo-random integer in the range [0, bound).
 */
uint32_t pcg_brand(uint32_t bound);


#endif /* __PCGRNG_H__ */
