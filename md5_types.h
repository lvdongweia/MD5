/*
 */

#ifndef MD5_TYPES_H_
#define MD5_TYPES_H_

/* platform configuration */
#ifndef LINUX
#define LINUX
#endif

#ifdef LINUX /* PAD board */
#include <unistd.h>
typedef uint32_t    MD5_uint32_t;
typedef uint16_t    MD5_uint16_t;
typedef uint8_t     MD5_uint8_t;
typedef size_t      MD5_size_t;

typedef int32_t     MD5_int32_t;
typedef int16_t     MD5_int16_t;
typedef int8_t      MD5_int8_t;
typedef ssize_t     MD5_ssize_t;
#elif defined STM32 /* power/face board */
#include <ucos_ii.h>
typedef INT32U      MD5_uint32_t;
typedef INT16U      MD5_uint16_t;
typedef INT8U       MD5_uint8_t;
typedef INT32U      MD5_size_t;

typedef INT32S      MD5_int32_t;
typedef INT16S      MD5_int16_t;
typedef INT8S       MD5_int8_t;
typedef INT32S      MD5_ssize_t;
#elif defined BIOS_DSP /* servo/movement control board */
#include <xdc/std.h>
typedef UInt32      MD5_uint32_t;
typedef UInt16      MD5_uint16_t;
typedef UInt8       MD5_uint8_t;

#ifdef xdc__INT64__
typedef UInt64      MD5_size_t;
typedef Int64       MD5_ssize_t;
#else
typedef UInt32      MD5_size_t;
typedef Int32       MD5_ssize_t;
#endif /* xdc__INT64__ */

typedef Int32       MD5_int32_t;
typedef Int16       MD5_int16_t;
typedef Int8        MD5_int8_t;
#endif /* LINUX */

#endif /* MD5_TYPES_H_ */
