#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    char* value;
    struct QueueNode* next;
} queue_node_t;

typedef struct Queue {
    queue_node_t *first, *last;
} queue_t;

queue_t* init_queue();
queue_node_t* create_node();
void add_node(queue_t* queue, char* value);
void assing_value_to_initial_node(queue_node_t* node, char* value);
void dequeue(queue_t*);
void enqueue(queue_t* queue, char* value);
void print_elements(queue_t* queue);
uint8_t is_empty(queue_t queue);

int main() {
    queue_t* queue = init_queue();

    enqueue(queue, "Prvi");
    enqueue(queue, "Drugi");
    enqueue(queue, "Treći");
    print_elements(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    print_elements(queue);

    enqueue(queue, "Prvi");
    print_elements(queue);
    return 0;
}

queue_t* init_queue() {
    queue_t* new_q = (queue_t*)malloc(sizeof(queue_t));
    printf("Initialized queue\n");
    return new_q;
}
void enqueue(queue_t* queue, char* value) {
    if (queue == NULL) {
        printf("You did not initialize the queue.\n");
    } else if (queue->last == NULL) {
        printf("Queue is empty, add the node as first and last\n");
        queue->last = create_node();
        queue->first = queue->last;
        assing_value_to_initial_node(queue->last, value);
        printf("Enqueued value: %s\n", queue->last->value);
    } else {
        add_node(queue, value);
        printf("Enqueued value: %s\n", queue->last->value);
    }
}
queue_node_t* create_node() {
    return (queue_node_t*)malloc(sizeof(queue_node_t));
}

void assing_value_to_initial_node(queue_node_t* node, char* value) {
    node->value = value;
    node->next = NULL;
}
void add_node(queue_t* queue, char* value) {
    queue->last->next = create_node();
    queue->last->next->value = value;
    queue->last = queue->last->next;
}
void print_elements(queue_t* queue) {
    printf("\nIterate values: \n");
    if (queue->first == NULL) {
        printf("Empty\n");
    } else {
        queue_node_t* temp = queue->first;
        while (temp != NULL) {
            printf("Value: %s \n", temp->value);
            temp = temp->next;
        }
    }
}
void dequeue(queue_t* queue) {
    if (queue == NULL) return;
    if (queue->first == queue->last) {
        queue->first = NULL;
        queue->last = NULL;
    } else {
        queue->first = queue->first->next;
    }
}
