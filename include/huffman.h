#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include "minHeap.h"
#include "types.h"

#define MAX_CHARS 256

Node *buildHuffmanTree(UInt8 freqs[], UInt32 size);

void getCodes(Node* root, UInt8 arr[], UInt8 *codes[MAX_CHARS], UInt32 level);

#endif
