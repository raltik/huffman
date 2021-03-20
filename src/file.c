#include "file.h"

#define MAX_CHARS 256

int current_byte;
int nbits;
int nbytes;

UInt8 *getFreqs(FILE *input, UInt8 freqs[]) {
    int n;
    UInt8 ch;
    
    for (n=0;;n++) {
        ch = fgetc(input);

        if (feof(input)) break;

        freqs[ch]++;
    }
    return n;
}

void bitout(FILE *f, char b) {
    current_byte <<= 1;

    if (b == '1') current_byte |= 1;
    nbits++;

    if (nbits == 8) {
        fputc(current_byte, f);
        nbytes++;
        nbits = 0;
        current_byte = 0;
    }
}

void compressFile(FILE *input, FILE *output, UInt8 *codes[]) {
    UInt8 ch;
    UInt8 *s;

    current_byte = nbits = nbytes = 0;

    for (;;) {
        ch = fgetc(input);

        if (feof(input)) break;

        for (s = codes[ch]; *s; s++) {
            bitout(output, s);
        }
    }

    //while (nbits) bitout(output, '0');
}