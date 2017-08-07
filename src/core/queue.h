#ifndef __QUEUE__H
#define __QUEUE__H

#include<stdlib.h>
#include "graph.h"

#define NUM         10
  
typedef      vertex_t     type;
typedef enum{false,true}boolean;

typedef struct _queue{
    
        int tail;
        int head;
        int size;
        type *array;
}queue_t;


void init_queue(queue_t *queue){
        
        queue->array=(type *)malloc(sizeof(type)*NUM);
        if(queue->array==NULL){return ;}
        queue->head=0;
        queue->tail=0;
}

boolean isempty(queue_t *queue){
     if((queue->tail==queue->head)){
         return true;
     }
     return false;
}
boolean isfull(queue_t *queue){
     if((queue->tail-queue->head)==NUM-1){
         return true;
     }
     return false;
}


void enqueue(queue_t *queue,type m){
         if(!isfull(queue)){
             queue->array[queue->tail++]=m;
         }
}

void outqueue(queue_t *queue,type *m){
      if(!isempty(queue)){
          *m=queue->array[queue->head++];
      }
}

#endif