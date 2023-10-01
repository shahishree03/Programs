#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of characters
#define MAX_CHARS 256

// Define a structure to represent a node in the Huffman tree
struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Define a structure to represent a priority queue node
struct MinHeapNode {
    struct HuffmanNode* node;
    struct MinHeapNode* next;
};

// Function to create a new Huffman tree node
struct HuffmanNode* newNode(char data, unsigned frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new priority queue node
struct MinHeapNode* newMinHeapNode(struct HuffmanNode* node) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->node = node;
    minHeapNode->next = NULL;
    return minHeapNode;
}

// Function to create a priority queue and initialize it with given Huffman nodes
struct MinHeapNode* createMinHeap(struct HuffmanNode* node) {
    struct MinHeapNode* minHeapNode = newMinHeapNode(node);
    return minHeapNode;
}

// Function to merge two min-heap nodes into a single node
struct HuffmanNode* mergeMinHeapNodes(struct HuffmanNode* a, struct HuffmanNode* b) {
    struct HuffmanNode* mergedNode = newNode('$', a->frequency + b->frequency);
    mergedNode->left = a;
    mergedNode->right = b;
    return mergedNode;
}

// Function to insert a min-heap node into the priority queue
void insertMinHeap(struct MinHeapNode** head, struct MinHeapNode* node) {
    if (!(*head) || node->node->frequency < (*head)->node->frequency) {
        node->next = *head;
        *head = node;
    } else {
        struct MinHeapNode* current = *head;
        while (current->next && current->next->node->frequency < node->node->frequency) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// Function to build the Huffman tree and return the root
struct HuffmanNode* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeapNode *minHeapHead = NULL;

    // Create a priority queue and insert all characters and their frequencies into it
    for (int i = 0; i < size; ++i) {
        insertMinHeap(&minHeapHead, newMinHeapNode(newNode(data[i], frequency[i])));
    }

    // Build the Huffman tree
    while (minHeapHead && minHeapHead->next) {
        left = minHeapHead->node;
        minHeapHead = minHeapHead->next;
        right = minHeapHead->node;
        minHeapHead = minHeapHead->next;
        top = mergeMinHeapNodes(left, right);
        insertMinHeap(&minHeapHead, newMinHeapNode(top));
    }
    return minHeapHead->node;
}

// Function to print Huffman codes from the root of the Huffman tree
void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);

    int huffmanCode[MAX_CHARS];
    int top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, huffmanCode, top);

    return 0;
}
