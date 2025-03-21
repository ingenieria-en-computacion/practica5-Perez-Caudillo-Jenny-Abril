#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    
    q->head = NULL;
    q->tail = NULL;
    
    return q;
}

void queue_enqueue(Queue* q, Data d){
    if (q == NULL) {
        return;
    }
    
    Node* new = new_node(d);
    if (new == NULL) {
        return;
    }
    
    if (q->tail == NULL) {
        q->head = new;
        q->tail = new;
    } else {
        q->tail->next = new;
        q->tail = new;
    }
}

Data queue_dequeue(Queue* q){
    if (q == NULL || q->head == NULL) {
        return -1; 
    }
    
    Node* temp = q->head;
    Data data = temp->data;
    
    q->head = q->head->next;
    
    if (q->head == NULL) {
        q->tail = NULL;
    }

    temp->next = NULL;
    delete_node(temp);

    return data;
}

bool queue_is_empty(Queue* q){
    return (q == NULL || q->head == NULL);
}

Data queue_front(Queue* q){
    if (q == NULL || q->head == NULL) {
        return -1; 
    }
    
    return q->head->data;
}

void queue_empty(Queue* q){
    if (q == NULL) {
        return;
    }
    
    while (q->head != NULL) {
        Node* temp = q->head;
        q->head = q->head->next;
        
        temp->next = NULL;
        delete_node(temp);
    }

    q->tail = NULL;
}

void queue_delete(Queue* q){
    if (q == NULL) {
        return;
    }
    
    queue_empty(q);
    free(q);
}