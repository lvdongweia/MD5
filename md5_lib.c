#include "md5_lib.h"
#include <stdio.h>

MD5_CTX init_md5(void)
{
    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);
    return md5_ctx;
}

int update_md5(MD5_CTX *md5_ctx, const void *p, MD5_size_t len)
{
    if (md5_ctx == NULL || p == NULL) return -1;

    MD5_Update(md5_ctx, p, len);

    return 0;
}

/* char md5_str[2*MD5_DIGEST_LENGTH + 1]; */
int final_md5(MD5_CTX *md5_ctx, char *md5_str, MD5_uint8_t len)
{
    int i;
    char *str = md5_str;
    unsigned char md5[MD5_DIGEST_LENGTH];

    if (md5 == NULL || md5_ctx == NULL
            || len < (2 * MD5_DIGEST_LENGTH)) return -1;

    MD5_Final(md5, md5_ctx);

    for (i = 0; i < (int)sizeof(md5); i++)
        snprintf((str + i * 2), 3, "%02x", md5[i]);

    return 0;
}
