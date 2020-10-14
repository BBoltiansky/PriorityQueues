#ifndef RING_H
#define RING_H
struct ring* rb_create(size_t num_items);
int rb_isempty(struct ring *rb);
int rb_isfull(struct ring *rb);
int rb_delete(struct ring *rb);
int rb_enqueue(struct ring *rb, void *value);
void* rb_dequeue(struct ring *rb);
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>  



struct ring{
    void** arr;
    int arrSize;
    int numEle;
    int head;
    int tail;
};

struct ring* rb_create(size_t num_items){
    struct ring *rb = (struct ring*)malloc(sizeof(struct ring));
    if(rb == NULL){
        printf("No memory available for ring buffer\n");
        return NULL;
    }
    rb->arr = (void**)malloc(sizeof(void*) * num_items);
    if(rb->arr == NULL){
        printf("No memory available for ring buffer array\n");
        return NULL;
    }
    rb->arrSize = num_items;
    printf("Ring buffer of size %d created\n", rb->arrSize);
    rb->numEle = 0;
    //head should point to empty or full space, depending on if numEle == 0 or is >= 1
    rb->head = 0;
    //tail should point to empty space
    rb->tail = 1;
    return rb;
}
int rb_delete(struct ring *rb){
    if(rb_isempty(rb) == 1){
        printf("Ring buffer of size %d deleted\n", rb->arrSize);
        free(rb->arr);
        free(rb);
        return 0;
    }else{
        printf("Cannot delete a non-empty ring buffer\n");
        return -1;
    }
}
int rb_isempty(struct ring *rb){
    if(rb->numEle == 0){
        return 1;
    }else{
        return 0;
    }
}
int rb_isfull(struct ring *rb){
    if(rb->arrSize == rb->numEle){
        return 1;
    }else{
        return 0;
    }
}
int rb_enqueue(struct ring *rb, void *value){
    if(rb_isempty(rb)){
        //If empty, insert value at head, increase numEle by 1. No pointer arithmatetic needed
        rb->arr[rb->head] = value;
        rb->numEle = rb->numEle + 1;
        return 0;
    }else if(rb_isfull(rb)){
        return -1;
    }else{
        //1 or more elements, place at tail, check if full (if not increment tail by one)
        rb->arr[rb->tail] = value;
        rb->numEle = rb->numEle + 1;
        if(rb_isfull(rb)){
            return 0;
        }else{
            rb->tail = (rb->tail + 1) % (rb->arrSize);
            return 0;
        }
    }
}
void* rb_dequeue(struct ring *rb){
    if(rb_isempty(rb)){
        //If empty return NULL
        return NULL;
    }else if(rb_isfull(rb)){
        //If full, get value from head, decrease numEle by one, increase head and tail pointer by one.
        void* value = rb->arr[rb->head];
        rb->numEle = rb->numEle - 1;
        rb->head = (rb->head + 1) % (rb->arrSize);
        rb->tail = (rb->tail + 1) % (rb->arrSize);
        return value;
    }else{
        if(rb->numEle == 1){
            //if there is only one element, grab value from head, don't change position of pointers
            void* value = rb->arr[rb->head];
            rb->numEle = rb->numEle - 1;
            return value;
        }else{
            //Otherwise, grab value from head, increment head pointer by one. 
            void* value = rb->arr[rb->head];
            rb->head = (rb->head + 1) % (rb->arrSize);
            rb->numEle = rb->numEle - 1;
            return value;
        }
    }
}
/* RING_H */
