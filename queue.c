#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "itemType.h"

#define CHUNKSIZE 20

static int inc(int n,queue q) { return ++n % q->size; }

static void expandQ(queue q) {
itemType *t = malloc(sizeof(itemType)*(q->size+CHUNKSIZE));
for (int i = 0; i < q->size; i++) t[i] = q->data[i];
q->size += CHUNKSIZE;
q->data = t;
}

queue createQueue() {
queue q = malloc(sizeof(struct queueType));
q->data = malloc(sizeof(itemType)*CHUNKSIZE);
q->front = 0; q->back = -1;
q->size = CHUNKSIZE; q->count = 0;
return q;
}

void freeQueue(queue q) { free(q->data); free(q); }

void enqueue(queue q,itemType p) {
if(isFull(q)) expandQ(q);
q->data[q->back=inc(q->back,q)] = p;
q->count++;
}

void dequeue(queue q){
if(isEmpty(q)){

} else {
q->front = inc(q->front,q);
q->count--;
}
}

itemType front(queue q) {
if(isEmpty(q)){

} else {
return q->data[q->front];
}
}

bool isEmpty(queue q) { return q->count == 0; }

bool isFull(queue q) { return q->count == q->size; }

int size(queue q) { return q->count; }
