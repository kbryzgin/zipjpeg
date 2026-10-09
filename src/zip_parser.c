// zip parser

#include <stdint.h>
#include <stdlib.h>

#include "zip_parser.h"

long find_eocd(FILE *file, EOCD *eocd) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    
    long start = file_size - 22;
    long end = start - 65535;

    if (end < 0)
        end = 0;

    uint32_t sig;

    for (long i = start; i >= end; i--) {
        fseek(file, i, SEEK_SET);
        fread(&sig, sizeof(uint32_t), 1, file);

        if (sig == 0x06054B50) {
            fseek(file, i, SEEK_SET);
            fread(eocd, sizeof(EOCD), 1, file);
            return i;
        }
    }

    return -1;
}

int print_zip_files(FILE *file, long archive_offset,
                    uint32_t cd_offset, uint16_t total_entries) {
    fseek(file, archive_offset + cd_offset, SEEK_SET);
    
    for (int i = 0; i < total_entries; i ++) {
        CDFH cdfh;
        fread(&cdfh, sizeof(CDFH), 1, file);
        char *filename = malloc(cdfh.filename_length + 1);

        fread(filename, 1, cdfh.filename_length, file);
        filename[cdfh.filename_length] = '\0';
        printf(" - %s\n", filename);

        free(filename);

        fseek(file, cdfh.extra_field_length + cdfh.comment_length, SEEK_CUR);
    }
    
    return 0;
}

