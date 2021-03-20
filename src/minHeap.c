#include <stdio.h>
#include <stdlib.h>

#include "minHeap.h"


/*
* Creates and allocates a new node
* @param data Input UInt8acter
* @param freq Frequency of the UInt8acter
*/
Node* createNode(UInt8 data, UInt32 freq) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

/*
* Creates a MinHeap of given capacity
* @param capacity Capacity of the MinHeap
*/
MinHeap* createMinHeap(UInt32 capacity) {
    MinHeap *minHeap = (MinHeap *) malloc(sizeof(MinHeap));

    minHeap->size = 0; /* Initial size is 0 */

    minHeap->capacity = capacity;
    minHeap->array = (Node **) malloc(capacity * sizeof(Node *));

    return minHeap;
}

/*
* Swaps two min heap nodes
*/
void swapNodes(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int index) {
    int smallest, left, right;

    smallest = index;
    left = LCHILD(index);
    right = RCHILD(index);

    if (left < minHeap->size && 
            minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    
    if (right < minHeap->size &&
            minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    
    if (smallest != index) {
        swapNodes(minHeap->array[smallest], minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

Node *extractMin(MinHeap *minHeap) {
    
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    minHeapify(minHeap, 0);
    return temp;
}

void insertNode(MinHeap *minHeap, Node *node) {
    int i;

    minHeap->size++;
    i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[PARENT(i)]->freq) {
        minHeap->array[i] = minHeap->array[PARENT(i)];
        i = PARENT(i);
    }
    minHeap->array[i] = node;
}

int isSizeOne(MinHeap *minHeap) {
    return minHeap->size == 1;
}

/*
* Checks if the node is leaf, i.e. has not childs
*/
int isLeaf(Node *root) {
    return !(root->left) && !(root->right);
}

void buildMinHeap(MinHeap *minHeap) {
    int n, i;

    n = minHeap->size - 1;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

MinHeap *createAndBuildMinHeap(UInt8 freqs[], int size) {
    
    MinHeap *minHeap = createMinHeap(size);
    for (int i=0; i < size; i++) {
        minHeap->array[i] = createNode(i, freqs[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;    
}

