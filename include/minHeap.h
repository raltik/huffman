#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

#include "types.h"

#define PARENT(x) (x-1) / 2
#define LCHILD(x) 2 * x + 1;
#define RCHILD(x) 2 * x + 2;

/* Node of the huffman tree */
typedef struct node {
    UInt8 data;
    UInt32 freq;
    
    struct node *left, *right;
} Node;

typedef struct minHeap {
    UInt32 size;
    UInt32 capacity;

    Node **array;
} MinHeap;

Node* createNode(UInt8 data, UInt32 freq);
Node *extractMin(MinHeap *minHeap);

MinHeap* createMinHeap(UInt32 capacity);
MinHeap *createAndBuildMinHeap(UInt8 freqs[], int size);

void swapNodes(Node *a, Node *b);
void minHeapify(MinHeap *minHeap, int index);
void insertNode(MinHeap *minHeap, Node *node);
void buildMinHeap(MinHeap *minHeap);

int isSizeOne(MinHeap *minHeap);
int isLeaf(Node *root);

#endif