// entry point

#include <stdio.h>
#include <stdlib.h>

#include "zip_parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./zipjpeg <file>\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: File opening error\n");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    
    long file_size = ftell(file);
    if (file_size < 22) {
        printf("The file is not a zipjpeg\n");
        fclose(file);
        return EXIT_SUCCESS;
    }

    EOCD eocd;

    long eocd_pos = find_eocd(file, &eocd);
    if (eocd_pos == -1) {
        printf("The file is not a zipjpeg\n");
        fclose(file);
        return EXIT_SUCCESS;
    }

    clearerr(file);

    uint32_t expected_pos = eocd.cd_offset + eocd.cd_size;
    long archive_offset = eocd_pos - expected_pos;

    if (archive_offset == 0) {
        printf("The file is a regular ZIP archive\n");
    } else if (archive_offset > 0 ) {
        printf("Zipjpeg detected, jpeg size: %ld\n", archive_offset);
    }

    print_zip_files(file, archive_offset, eocd.cd_offset, eocd.total_entries);
    fclose(file);
    
    return EXIT_SUCCESS;
}