# ZIPJPEG detector
A simple CLI-utility written in C to detect "zipjpeg" files (images with a ZIP archive appended to the end) and list their contents.

## Core Features
* Detects standard image files (without embedded archives).
* Identifies standalone, regular ZIP archives.
* Recognizes appended files (zipjpeg) and computes the exact size of the source image.
* Parses the ZIP Central Directory and prints a list of all embedded files without using any third-party libraries.

## Prerequisites
* `gcc` compiler
* `make` build automation tool

## Building the Project
To compile the utility using strict compliance flags (`-Wall -Wextra -Wpedantic -std=c11`), run the following command in the root directory:
```bash
make
```

To clean the repository by removing the generated executable, use:
```bash
make clean
```

## Usage
Run the program by passing the target file path as a CLI-argument:
```bash
./zipjpeg <file_path>
```

### Execution Examples:
```bash
./zipjpeg tests/non-zipjpeg1.jpg  # Testing a regular image
./zipjpeg tests/zipjpeg1.jpg      # Testing a combined Rarjpeg file
```
