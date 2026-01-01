#include <stdio.h>
#include <string.h>

#include <asm-generic/errno-base.h>

#include <dav1d/dav1d.h>

int main(int argc, char **argv) {

    printf("Starting Program\n");
    // printf("DEBUG: %d\n", DAV1D_ERR(EAGAIN));

    Dav1dContext *dav1d_ctx = NULL;
    Dav1dSettings dav1d_set;

    dav1d_default_settings(&dav1d_set);

    int res = 0;
    int err = 0;

    //TODO open input stream in demuxer

    if ((err = dav1d_open(&dav1d_ctx, &dav1d_set)) < 0) {
        fprintf(stderr, "\nFailed to open dav1d decoder (Err: %d)\n", DAV1D_ERR(err));
        fprintf(stderr, "%s\n", strerror(DAV1D_ERR(err)));
        res = 1;
        goto cleanup;
    }

    //TODO read input from demuxer

    while (1) {
        // decode frame from demuxer input and add to a queue to be played
        break;
    }

cleanup:
    if (dav1d_ctx)
        dav1d_close(&dav1d_ctx);

    return res;
}
