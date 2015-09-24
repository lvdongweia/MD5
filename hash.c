#include "hash.h"

MD5_uint32_t
cshift(MD5_uint32_t x, MD5_uint32_t n)
{
    x = CRAYFIX(x);
    return CRAYFIX((x << n) | (x >> (32 - n)));
}
