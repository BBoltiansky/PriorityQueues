#ifndef PQUEUE_1_H
#define PQUEUE_1_H
#include <pqueue_n.h>
#include "pqueue_n.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>   
#define PQ1_HIGHEST_PRIORITY 0
#define PQ1_LOWEST_PRIORITY 15

struct pqueue_1{
    struct pqueue_n* pqn[PQ1_LOWEST_PRIORITY + 1];
};

struct pqueue_1 *pq1_create(void){
    //Create array of size lowestprio + 1
    struct pqueue_1 *pq = (struct pqueue_1*)malloc(sizeof(struct pqueue_1));
    int i = 0;
    for(i = 0; i <= PQ1_LOWEST_PRIORITY; i++){
        pq->pqn[i] = pqn_create();
    }
    return pq;
}
int pq1_delete(struct pqueue_1 *pq){
    int i = 0;
    for(i = 0; i <= PQ1_LOWEST_PRIORITY; i++){
        if(pq->pqn[i]->size != 0){
            printf("Cannot deleted q1 without it being fully empty/n");
            return -1;
        }
    }
    int tempInt = 0;
    for(i = 0; i <= PQ1_LOWEST_PRIORITY; i++){
        tempInt = pqn_delete(pq->pqn[i]);
        if(tempInt == -1){
            printf("Error deleting queuen at index %d\n", i);
            return -1;
        }
    }
    free(pq->pqn);
    free(pq);
    return 0;
}
void pq1_enqueue(struct pqueue_1 *pq, void *value, unsigned int priority){
    if(priority > PQ1_LOWEST_PRIORITY){
        printf("Invalid priority\n");
        return;
    }else{
        pqn_enqueue(pq->pqn[priority], value, priority);
        return;
    }
}
void* pq1_dequeue(struct pqueue_1 *pq){
    int i = 0;
    for(i = 0; i <= PQ1_LOWEST_PRIORITY; i++){
        if(pq->pqn[i]->size != 0){
            void* value = pqn_dequeue(pq->pqn[i]);
            return value;
        }
    }
    printf("Cannot dequeue with every queuen empty\n");
    return NULL;
}

void pq1_prios(struct pqueue_1 *pq){
    int i = 0;
    for(i = 0; i <= PQ1_LOWEST_PRIORITY; i++){
        printf("Priority %d : ", i);
        pqn_prios(pq->pqn[i]);
    }
    printf("\n\n");
    return;
}

#endif	/* PQUEUE_1_H */
