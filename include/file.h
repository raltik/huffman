#ifndef _FILE_H
#define _FILE_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"


UInt8 *getFreqs(FILE *input, UInt8 freqs[]);

void compressFile(FILE *input, FILE *output, UInt8 *codes[]);

#endif