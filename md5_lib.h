/*
 */

#ifndef MD5_LIB_H_
#define MD5_LIB_H_

#include "md5.h"

#ifndef MD5_DIGEST_LENGTH
#define MD5_DIGEST_LENGTH 16
#endif

MD5_CTX init_md5(void);

/* update $md5_ctx with new data */
int update_md5(MD5_CTX *md5_ctx, const void *p, MD5_size_t len);

/* char md5_str[MD5_DIGEST_LENGTH * 2 + 1] */
int final_md5(MD5_CTX *md5_ctx, char *md5_str, MD5_uint8_t len);

#endif /* MD5_LIB_H */
