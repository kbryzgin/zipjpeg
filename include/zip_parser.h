// zip parser header

#pragma once

#include <stdio.h>
#include <stdint.h>

#pragma pack(push, 1)

typedef struct {
    uint32_t signature;
    uint16_t disk_number;
    uint16_t disk_with_cd;
    uint16_t disk_entries;
    uint16_t total_entries;
    uint32_t cd_size;
    uint32_t cd_offset;
    uint16_t comment_length;
} EOCD;

typedef struct {
    uint32_t signature;
    uint16_t version_made;
    uint16_t version_needed;
    uint16_t flags;
    uint16_t compression_method;
    uint16_t last_mod_time;
    uint16_t last_mod_date;
    uint32_t crc32;
    uint32_t compressed_size;
    uint32_t uncompressed_size;
    uint16_t filename_length;
    uint16_t extra_field_length;
    uint16_t comment_length;
    uint16_t disk_number_start;
    uint16_t internal_attrs;
    uint32_t external_attrs;
    uint32_t local_header_offset;
} CDFH;

#pragma pack(pop)

long find_eocd(FILE *file, EOCD *eocd);

int print_zip_files(FILE *file, long offset, 
                    long archive_offset, uint32_t cd_offset, uint16_t total_entries);
