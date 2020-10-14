#ifndef PQUEUE_N_H
#define PQUEUE_N_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define PQN_HIGHEST_PRIORITY 0
#define PQN_LOWEST_PRIORITY 15

struct pqnNode{
	void *value;
    unsigned int prio;
	struct pqnNode *next;
};	
struct pqueue_n{
	struct pqnNode *head;
    struct pqnNode *tail;
	int size;
};


struct pqueue_n *pqn_create(void){
    struct pqueue_n *pq = (struct pqueue_n*) malloc(sizeof(struct pqueue_n));
    if (pq == NULL) {
        printf("No memory available for queue.\n");
        return NULL;
    }
    pq->head = NULL;
    pq->tail = NULL;
    pq->size = 0;
    printf("Queue created\n");
    return pq;
}
int pqn_delete(struct pqueue_n *pq){
    if(pq->size == 0){
        free(pq);
        printf("Queue deleted.\n");
        return 0;
    }else{
        printf("Could not delete queue\n");
        return -1;
    }
}
void pqn_enqueue(struct pqueue_n *pq, void *value, unsigned int priority){
    if(priority > PQN_LOWEST_PRIORITY){
        printf("Invalid Priority\n");
        return;
    }
    struct pqnNode *node = (struct pqnNode*)malloc(sizeof(struct pqnNode));
    node->value = value;
    node->prio = priority;
    node->next = NULL;
    if(pq->size == 0){
        //if nothing is in the queue, node is head and tail.
        pq->head = node;
        pq->tail = node;
        pq->size = 1;
        //printf("Successfully inputted node with empty queue\n");
        return;
    }else if(pq->size == 1){
        if(pq->head->prio <= priority){
            //if current node prio is less than or equal to new node, place new node at back
            pq->tail = node;
            pq->head->next = node;
            //printf("Successfully inputted node into 1 size queue with lower or equal priority\n");
        }else{
            //current node has higher priority than new node
            pq->head = node;
            node->next = pq->tail;
            //printf("Successfully inputted node into 1 size queue with higher priority\n");
        }
        pq->size = 2;
        return;
    }else{
        if(pq->tail->prio <= priority){
            //quick check to see if end of queue is less than or equal to new node prio, new node goes to back
            pq->tail->next = node;
            pq->tail = node;
            pq->size = pq->size + 1;
            //printf("Successfully inputted node to end of queue\n");
            return;
        }else if(pq->head->prio > priority){
            //fencepost loop, must check case before head
            //This case is when new node has higher priority than any other node, goes to front of queue
            node->next = pq->head;
            pq->head = node;
            pq->size = pq->size + 1;
            //printf("Successfully inputted node to front of queue\n");
            return;
        }
        struct pqnNode *temp = pq->head;
        //since we already calculated our edge cases, we only check to see if the next node is greater than
        //our new priority. If it is, place our new node there and move everything over one.
        while(temp->next != NULL){
            if(temp->next->prio > priority){
                node->next = temp->next;
                temp->next = node;
                pq->size = pq->size + 1;
                //printf("Successfully inputted node somewhere in the middle of the queue\n");
                return;
            }else{
                temp = temp->next;
            }
        }
        printf("Something went wrong, next node is NULL and we didn't do any pointer arithmathtic.\n");
        return;
    }
}
void* pqn_dequeue(struct pqueue_n *pq){
    //first check if there is a node to remove
	if(pq->size != 0){
        struct pqnNode *node = pq->head;
        if(pq->size == 1){
            //if there is only one node. save value so that we can free the node, decrease size, and return value
            void *retval = node->value;
            free(node);
            pq->size = 0;
            pq->head = NULL;
            pq->tail = NULL;
            //printf("Successfully dequeued node from a queue of size 1\n");
            return retval;
        }else if(pq->size == 2){
            void *retval = node->value;
            free(node);
            pq->size = 1;
            pq->head = pq->tail;
            //printf("Successfully dequeued node from a queue of size 2\n");
            return retval;    
        }else{
            //Otherwise, we need to set the second node as the first, and repeat the process of saving value to return it.
            pq->head = node->next;
            void *retval = node->value;
            free(node);
            pq->size = pq->size - 1;
            //printf("Successfully dequeued node from queue\n");
            return retval;
        }
    }else{
        printf("Cannot dequeue with empty queue\n");
        return NULL;
    }
}

void pqn_prios(struct pqueue_n *pq){
    if(pq->size != 0){
        struct pqnNode *node = pq->head;
        int i = 0;
        for(i = 1; i < pq->size; i++){
            printf("%d, ", node->prio);
            node = node->next;
        }
        printf("%d\n", node->prio);
    }else{
        printf("Queue size is 0\n");
    }
    return;

}

#endif /* PQUEUE_N_H */
