// entry point

#include <stdio.h>
#include <stdlib.h>

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
    }

}