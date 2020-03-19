#ifndef _MRMR_MURMUR3_H
#define _MRMR_MURMUR3_H

#include <stdint.h>
#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define murmur3_sum _mrmr_murmur3_sum
#define murmur3_tweak _mrmr_murmur3_tweak

uint32_t
murmur3_sum(const uint8_t *data, size_t len, uint32_t seed);

uint32_t
murmur3_tweak(const uint8_t *data, size_t len, uint32_t n, uint32_t tweak);

#if defined(__cplusplus)
}
#endif

#endif
