#include "Queue2.h"

static uint8 QueueFull(Queue_t *Object)
{
    return (Object->Q_CountElement == Object->Q_MaxSize);
}

static uint8 QueueEmpty(Queue_t *Object)
{
    return (0 == Object->Q_CountElement);
}

Queue_t *CreateQueu(uint32 MaxSize, QueueStatus_t *ret_status)
{
    Queue_t *MyQueue = NULL;
    if(!ret_status)
    {
        *ret_status = Q_NULL_PTR;
        MyQueue = NULL;
    }
    else
    {
        MyQueue = (Queue_t *)malloc(sizeof(Queue_t));
        if(!MyQueue)
        {
            *ret_status = Q_NOK;
            MyQueue = NULL;
        }
        else
        {
            MyQueue->Q_Array = (void **)calloc(MyQueue->Q_MaxSize, sizeof(void *));
            if(!MyQueue)
            {
                *ret_status = Q_NOK;
                MyQueue = NULL;
            }
            else
            {
                MyQueue->Q_CountElement = 0;
                MyQueue->Q_Front = -1;
                MyQueue->Q_Rear = -1;
                MyQueue->Q_MaxSize = MaxSize;
                *ret_status = Q_OK;
            }
        }
    }
    return (MyQueue);
}
QueueStatus_t DestroyQueue(Queue_t *Object, QueueStatus_t *ret_status)
{
    if((!Object) || (!ret_status))
    {
        *ret_status = Q_NULL_PTR;
    }
    else
    {
        free(Object->Q_Array);
        free(Object);
        *ret_status = Q_OK;
    }
    return (*ret_status);
}
QueueStatus_t EnQueue(Queue_t *Object, void *Itemval)
{
    QueueStatus_t ret_status = Q_NOK;
    if((!Object) || (!Itemval))
    {
        ret_status = Q_NULL_PTR;
    }
    else
    {
        if(QueueFull(Object))
        {
            ret_status = Q_FULL;
        }
        else
        {
            (Object->Q_Rear)++;
            if(Object->Q_Rear == Object->Q_MaxSize)
            {
                Object->Q_Rear = 0;
            }
            else{}
            Object->Q_Array[Object->Q_Rear] = Itemval;
            if(Object->Q_CountElement == 0)
            {
                Object->Q_Front = 0;
                Object->Q_CountElement = 1;
            }
            else
            {
                (Object->Q_CountElement)++;
            }
            ret_status = Q_OK;
        }
    }
    return (ret_status);
}
void *DeQueue(Queue_t *Object, QueueStatus_t *ret_status)
{
    void *OutPutVal = NULL;
    if((!Object) || (!ret_status))
    {
        *ret_status = Q_NULL_PTR;
        OutPutVal = NULL;
    }
    else
    {
        if(QueueEmpty(Object))
        {
            *ret_status = Q_EMPTY;
            OutPutVal = NULL;
        }
        else
        {
            OutPutVal = Object->Q_Array[Object->Q_Front];
            (Object->Q_Front)++;
            if(Object->Q_Front == Object->Q_MaxSize)
            {
                Object->Q_Front = 0;
            }
            else{}
            if(1 == Object->Q_CountElement)
            {
                Object->Q_Front = -1;
                Object->Q_Rear = -1;
            }
            else{}

            (Object->Q_CountElement)--;
            *ret_status = Q_OK;

        }
    }
    return (OutPutVal);
}
void *QueueFront(Queue_t *Object, QueueStatus_t *ret_status)
{
    void *OutPutVal = NULL;
    if((!Object) || (!ret_status))
    {
        *ret_status = Q_NULL_PTR;
        OutPutVal = NULL;
    }
    else
    {
        if(QueueEmpty(Object))
        {
            *ret_status = Q_EMPTY;
            OutPutVal = NULL;
        }
        else
        {
            OutPutVal = Object->Q_Array[Object->Q_Front];
            *ret_status = Q_OK;
        }
    }
    return (OutPutVal);
}
void *QueueRear(Queue_t *Object, QueueStatus_t *ret_status)
{
    void *OutPutVal = NULL;
    if((!Object) || (ret_status))
    {
        *ret_status = Q_NULL_PTR;
        OutPutVal = NULL;
    }
    else
    {
        if(QueueEmpty(Object))
        {
            *ret_status = Q_EMPTY;
            OutPutVal = NULL;
        }
        else
        {
            OutPutVal = Object->Q_Array[Object->Q_Rear];
            *ret_status = Q_OK;
        }
    }
    return (OutPutVal);
}
QueueStatus_t QueueCount(Queue_t *Object, uint32 *Counter)
{
    QueueStatus_t ret_status = Q_NOK;
    if((!Object) || (!Counter))
    {
        ret_status = Q_NULL_PTR;
    }
    else
    {
        if(QueueEmpty(Object))
        {
            *Counter = 0;
            ret_status = Q_EMPTY;
        }
        else
        {
            *Counter = Object->Q_CountElement;
            ret_status = Q_OK;
        }
    }
    return (*Counter);
}
