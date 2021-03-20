#include "huffman.h"

#include <string.h>

Node *buildHuffmanTree(UInt8 freqs[], UInt32 size) {
    Node *left, *right, *top;
    MinHeap *minHeap;

    minHeap = createAndBuildMinHeap(freqs, size);
    
    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertNode(minHeap, top);
    }

    return extractMin(minHeap);
}

void getCodes(Node* root, UInt8 arr[], UInt8 *codes[MAX_CHARS], UInt32 level) {

    if (isLeaf(root)) {
        codes[root->data] = strdup(arr);
    } else {
        /* Left node */
        arr[level] = '0';
        getCodes(root->left, arr, codes, level + 1);

        /* Right node */
        arr[level] = '1';
        getCodes(root->right, arr, codes, level + 1);
    }
}
