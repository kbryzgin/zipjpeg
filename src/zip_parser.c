// zip parser

#include <stdint.h>
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
