#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "md5_lib.h"

static int usage()
{
    fprintf(stderr,"md5 file ...\n");
    return -1;
}

static int do_md5(const char *path)
{
    int fd;

    /* ##### Step 1 ##### */
    MD5_CTX md5_ctx;

    char md5[2 * MD5_DIGEST_LENGTH + 1];

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr,"could not open %s, %s\n", path, strerror(errno));
        return -1;
    }

    /* ##### Step 2 ##### */
    md5_ctx = init_md5();

    while (1) {
        char buf[4096];
        ssize_t rlen;
        rlen = read(fd, buf, sizeof(buf));
        if (rlen == 0)
            break;
        else if (rlen < 0) {
            (void)close(fd);
            fprintf(stderr,"could not read %s, %s\n", path, strerror(errno));
            return -1;
        }

        /* ##### Step 3 ##### */
        update_md5(&md5_ctx, buf, rlen);
    }
    if (close(fd)) {
        fprintf(stderr,"could not close %s, %s\n", path, strerror(errno));
        return -1;
    }

    /* ##### Step 4 ##### */
    final_md5(&md5_ctx, md5, sizeof(md5));

    printf("%s\n", md5);

    return 0;
}

int main(int argc, char *argv[])
{
    int i, ret = 0;

    if (argc < 2)
        return usage();

    /* loop over the file args */
    for (i = 1; i < argc; i++) {
        if (do_md5(argv[i]))
            ret = 1;
    }

    return ret;
}
