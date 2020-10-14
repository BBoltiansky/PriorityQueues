#include "pqueue_n.h"
#include "pqueue_1.h"
#include "ring.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void testE(struct ring *rb);
void testD(struct ring *rb);


int main(void){
    //used variables for testing
    struct ring *ring;
    int size = 500;

    //create ring
    ring = rb_create(size);

    int i;
    //automatic testing
    for(i = 1; i <= size; i++){
        testE(ring);
        testE(ring);
        testE(ring);
        if(i % 2 == 0){
            testD(ring);
            testD(ring);
            testD(ring);
        }else{
            testD(ring);
        }
    }

    for(i = 1; i <= size; i++){
        testD(ring);
    }

    //Can we delete?
    rb_delete(ring);


}

void testE(struct ring *rb){
    int a = 1;
    if(rb_enqueue(rb, &a) == 0){
        printf("Enqueue successful : (H=%d, T=%d)\n", rb->head, rb->tail);
    }else{
        printf("Cannot enqueue\n");
    }
}
void testD(struct ring *rb){
    if(rb_dequeue(rb) != NULL){
        printf("Dequeue successful : (H=%d, T=%d)\n", rb->head, rb->tail);
    }else{
        printf("Cannot dequeue\n");
    }
}










    //OLD TEST CODE
/*
    struct pqueue_1 *pq = pq1_create();
    printf("Stress test!\n");
    pq1_enqueue(pq, &one, 0);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 0);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 5);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 12);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 15);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 3);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 2);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 6);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 5);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 6);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 11);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 2);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 3);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 14);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 9);
    pq1_prios(pq);
    pq1_enqueue(pq, &one, 8);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);
    pq1_prios(pq);
    pq1_dequeue(pq);

    pq1_delete(pq);
    */




    //test that enqueue accepts valid priority only
    //pqn_enqueue(pq, &zero, 16);
    /*
    //test that dequeue doesn't work in an empty queue
    printf("\nTest that dequeue doesn't work in an empty queue\n");
    pqn_dequeue(pq);
    printf("\n\n");


    //test enqueue and dequeue of empty queue
    printf("Test enqueue and dequeue of empty queue\n");
    pqn_enqueue(pq, &zero, 0);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    printf("\n\n");
    

    //test enqueue and dequeue of queue size 1, higher prio, equal prio, then lower prio.
    
    printf("Test enqueue and dequeue of size 1, Higher prio.\n");
    pqn_enqueue(pq, &one, 1);
    pqn_prios(pq);
    pqn_enqueue(pq, &zero, 0);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    printf("\n\n");

    printf("Test enqueue and dequeue of size 1, Lower prio.\n");
    pqn_enqueue(pq, &one, 1);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 1);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    printf("\n\n");

    printf("Test enqueue and dequeue of size 1, equal prio.\n");
    pqn_enqueue(pq, &one, 1);
    pqn_prios(pq);
    pqn_enqueue(pq, &two, 2);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    printf("\n\n");

    printf("Test enqueue and dequeue (size > 1), head insert\n");
    pqn_enqueue(pq, &one, 1);
    pqn_enqueue(pq, &two, 2);
    pqn_enqueue(pq, &three, 3);
    pqn_prios(pq);
    pqn_enqueue(pq, &zero, 0);
    pqn_prios(pq);
    printf("\n\n");

    printf("Test enqueue and dequeue (size > 1), tail insert\n");
    pqn_prios(pq);
    pqn_enqueue(pq, &three, 4);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_dequeue(pq);
    pqn_dequeue(pq);
    pqn_dequeue(pq);
    pqn_dequeue(pq);
    */

   /*
    printf("Stress test!\n");
    pqn_enqueue(pq, &one, 0);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 0);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 5);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 12);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 15);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 3);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 2);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 6);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 5);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 6);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 11);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 2);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 3);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 14);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 9);
    pqn_prios(pq);
    pqn_enqueue(pq, &one, 8);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);
    pqn_prios(pq);
    pqn_dequeue(pq);

    */