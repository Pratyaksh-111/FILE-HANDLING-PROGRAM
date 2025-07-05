#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the text using Run-Length Encoding (RLE)
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char current, previous;
    int count = 1;

    previous = fgetc(in);

    while ((current = fgetc(in)) != EOF) {
        if (current == previous) {
            count++;
        } else {
            // Write compressed format: <count><character>
            fprintf(out, "%d%c", count, previous);
            count = 1;
        }
        previous = current;
    }

    // Write the last set
    if (feof(in)) {
        fprintf(out, "%d%c", count, previous);
    }

    fclose(in);
    fclose(out);

    printf("Compression completed.\n");
}

// Function to decompress the RLE compressed file
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int count;
    char ch;

    // Read count and character alternately
    while (fscanf(in, "%d%c", &count, &ch) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("Decompression completed.\n");
}

// Main function to call compression and decompression
int main() {
    char inputFile[100] = "original.txt";
    char compressedFile[100] = "compressed.txt";
    char decompressedFile[100] = "decompressed.txt";

    // Call compression
    compressFile(inputFile, compressedFile);

    // Call decompression
    decompressFile(compressedFile, decompressedFile);

    return 0;
}
