#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "huffman.h"

void parse_args(int argc, char **argv) {
    if (argc != 3) {
        show_usage();
        exit(-1);
    }
}

void show_usage() {
    printf("Usage:\n\thuff <input_file> <output_file>\n");
}

int main(int argc, char **argv) {
    int n;
    char *in_filename, *out_filename;
    FILE *in_file, *out_file;
    UInt8 freqs[MAX_CHARS];
    UInt8 *codes[MAX_CHARS];
    UInt8 arr[MAX_CHARS];

    parse_args(argc, argv);

    in_filename = argv[1];
    out_filename = argv[2];

    in_file = fopen(in_filename, "r");
    if (!in_file) {
        fprintf(stderr, "Error opening input file: %s\n", in_filename);
        exit(-1);
    }
    /* Get the frequencies of the text */
    memset(freqs, 0, sizeof(freqs));
    n = getFreqs(in_file, freqs);
    fclose(in_file);

    out_file = fopen(out_filename, "w");
    if (!out_file) {
        fprintf(stderr, "Error opening the output file: %s\n", out_filename);
        exit(-1);
    }
    
    in_file = fopen(in_filename, "r");
    
    Node *root = buildHuffmanTree(freqs, MAX_CHARS);

    getCodes(root, arr, codes, 0);

    compressFile(in_file, out_file, codes);
    

    return 0;
}