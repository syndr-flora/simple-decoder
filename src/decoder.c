#include <stdio.h>
#include <string.h>

#include <asm-generic/errno-base.h>

#include <dav1d/dav1d.h>

// TODO assign me according to https://videolan.videolan.me/dav1d/structDav1dPicAllocator.html
int alloc_picture(Dav1dPicture *pic, void *cookie) {

    return 0;
}

//TODO assign me to function that releases picture buffer
void release_picture(Dav1dPicture *pic, void *cookie) {

}

void dav1d_default_settings(Dav1dSettings *const s) {
    s->n_threads = 0;
    s->max_frame_delay = 0;
    s->apply_grain = 1;
    s->allocator.cookie = NULL;
    s->allocator.alloc_picture_callback = alloc_picture;
    s->allocator.release_picture_callback = release_picture;
    s->logger.cookie = NULL;
    s->logger.callback = NULL; // https://videolan.videolan.me/dav1d/structDav1dLogger.html
    s->operating_point = 0;
    s->all_layers = 1;
    s->frame_size_limit = 0;
    s->strict_std_compliance = 0;
    s->output_invisible_frames = 0;
    s->inloop_filters = DAV1D_INLOOPFILTER_ALL;
    s->decode_frame_type = DAV1D_DECODEFRAMETYPE_ALL;
}

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
