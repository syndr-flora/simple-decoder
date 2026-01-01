#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <asm-generic/errno-base.h>

#include <dav1d/dav1d.h>

// Sets filename to argv[1]
// Returns: 0 on success, -1 of failure
int parse_args(int argc, char** argv, char* filename) {
    if (argc < 2) {
        return -1;
    }

    if (strlen(argv[1]) > 255) {
        return -1;
    }

    strcpy(filename, argv[1]);

    return 0;
}

// Reads a file name filename to bytes_arr
// Returns: length of bytes_arr or -1 on err
// Notes: Free bytes_arr when done
int read_bin_file(char* filename, char* bytes_arr) {
    long filelen = 0;
    FILE *f = NULL;

    f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }
    if (fseek(f, 0, SEEK_END) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(f);
        return -1;
    };
    if ((filelen = ftell(f)) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(f);
        return -1;
    }
    rewind(f);

    bytes_arr = (char *)malloc(filelen * sizeof(char));
    fread(bytes_arr, 1, filelen, f);
    fclose(f);

    return filelen;
}


int main(int argc, char **argv) {
    char filename[256] = "";
    char* bytes_arr = NULL;
    long bytes_arr_len = 0;
    int res = 0;
    int err = 0;

    Dav1dContext *dav1d_ctx = NULL;
    Dav1dSettings dav1d_set;

    if (parse_args(argc, argv, filename) < 0) {
        printf("Usage: %s <input.mp4>\n", argv[0]);
        return 0;
    }

    printf("Starting Program\n");
    dav1d_default_settings(&dav1d_set);

    if ((bytes_arr_len = read_bin_file(filename, bytes_arr)) < 0) {
        goto cleanup;
    }

    if ((err = dav1d_open(&dav1d_ctx, &dav1d_set)) < 0) {
        fprintf(stderr, "\nFailed to open dav1d decoder (Err: %d)\n", DAV1D_ERR(err));
        fprintf(stderr, "%s\n", strerror(DAV1D_ERR(err)));
        res = 1;
        goto cleanup;
    }

    //TODO open input stream from file in demuxer

    //TODO read input from demuxer

    while (1) {
        // decode frame from demuxer input and add to a queue to be played
        break;
    }

cleanup:
    if (bytes_arr)
        free(bytes_arr);
    if (dav1d_ctx)
        dav1d_close(&dav1d_ctx);

    return res;
}
