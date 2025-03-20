
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 128  // Max size of each buffer
#define QUEUE_SIZE 10    // Number of buffers in queue

typedef struct {
    uint8_t length;  // Stores actual data length
    char data[BUFFER_SIZE];  // Data buffer
} Buffer;

typedef struct {
    Buffer buff[QUEUE_SIZE];  // Array of buffers
    uint8_t head;  // Points to the next item to dequeue
    uint8_t tail;  // Points to the next free slot for enqueue
    uint8_t count;  // Current buffer count
} Queue_t;


Queue_t lw_q = {
    .buff = {0},
    .count = 0,
    .head = 0,
    .tail = 0
};

Queue_t *q = &lw_q;

int enqueue(const char *data, int len) {
    if (q->count >= QUEUE_SIZE) {
        printf("Queue is full!\n");
        return -1;  // Queue is full
    }

    if (len > BUFFER_SIZE) {
        printf("Data too large for buffer!\n");
        return -1;  // Data exceeds buffer size
    }

    // Store data in the buffer
    q->buff[q->tail].length = len;
    memcpy(q->buff[q->tail].data, data, len);

    // Move tail forward (circular buffer)
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->count++;

    return 0;  // Success
}

int dequeue(char *buffer, int *len) {
    if (q->count == 0) {
        printf("Queue is empty!\n");
        return -1;  // Queue is empty
    }

    // Get the data length
    *len = q->buff[q->head].length;
    
    // Copy the data out
    memcpy(buffer, q->buff[q->head].data, *len);

    // Move head forward (circular buffer)
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;

    return 0;  // Success
}

int main()
{
    char data1[] = "hello-lorawan";
    char data2[] = "lora-mac-v0.1.3!";

    // Enqueue messages
    enqueue(data1, strlen(data1));
    enqueue(data2, strlen(data2));

    char buffer[BUFFER_SIZE];
    int len;
    
    if (dequeue(buffer, &len) == 0) {
        buffer[len] = '\0';  // Null-terminate for printing
        printf("Dequeued (%d bytes): %s\n", len, buffer);
    }

    if (dequeue(buffer, &len) == 0) {
        buffer[len] = '\0';
        printf("Dequeued (%d bytes): %s\n", len, buffer);
    }
}

