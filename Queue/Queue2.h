#ifndef _QUEUE2_H_
#define _QUEUE2_H_
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct{
    void **Q_Array;
    uint32 Q_MaxSize;
    sint32 Q_CountElement;
    sint32 Q_Front;
    sint32 Q_Rear;
}Queue_t;

typedef enum{
    Q_NOK,
    Q_OK,
    Q_FULL,
    Q_EMPTY,
    Q_NULL_PTR
}QueueStatus_t;

Queue_t *CreateQueu(uint32 MaxSize, QueueStatus_t *ret_status);
QueueStatus_t DestroyQueue(Queue_t *Object, QueueStatus_t *ret_status);
QueueStatus_t EnQueue(Queue_t *Object, void *Itemval);
void *DeQueue(Queue_t *Object, QueueStatus_t *ret_status);
void *QueueFront(Queue_t *Object, QueueStatus_t *ret_status);
void *QueueRear(Queue_t *Object, QueueStatus_t *ret_status);
QueueStatus_t QueueCount(Queue_t *Object, uint32 *Counter);

#endif // _QUEUE2_H_
