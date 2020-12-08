#include <stdbool.h>
#include "itemType.h"
#ifndef QUEUE_H
#define QUEUE_H
typedef struct queueType *queue;
struct queueType {
itemType *data;
int front, back,
count, // # of items in queue
size; // size of the data array
};
queue createQueue();
void freeQueue(queue);
void enqueue(queue,itemType);
void dequeue(queue);
itemType front(queue);
bool isEmpty(queue);
bool isFull(queue);
int size(queue);
#endif
