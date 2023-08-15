#include "Queue2.h"

Queue_t *Queue1 = NULL;
QueueStatus_t Queue1Status = Q_NOK;
uint32 MaxSize = 0;
uint32 Num1 = 11, Num2 = 22, Num3 = 44, Num4 = 55;
uint32 QueueCounter = 0;

void *OutPut = NULL;

int main()
{
    printf("Enter Number Of Elements: ");
    scanf("%i", &MaxSize);
    Queue1 = CreateQueu(MaxSize, &Queue1Status); printf("Status: %i\n", Queue1Status);

    Queue1Status = EnQueue(Queue1, &Num1); printf("Status: %i\n", Queue1Status);
    Queue1Status = EnQueue(Queue1, &Num2); printf("Status: %i\n", Queue1Status);
    Queue1Status = EnQueue(Queue1, &Num3); printf("Status: %i\n", Queue1Status);
    Queue1Status = EnQueue(Queue1, &Num4); printf("Status: %i\n", Queue1Status);
    Queue1Status = EnQueue(Queue1, &Num4); printf("Status: %i\n", Queue1Status);

    Queue1Status = QueueCount(Queue1, &QueueCounter); printf("Status: %i\n", Queue1Status);
    printf("Queue Count = %i\n", QueueCounter);

    printf("#############################################\n");
    OutPut = QueueFront(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("QueueFront Value: %i\n", *((uint32 *)OutPut)); //(QueueFront 11)
    }
    printf("#############################################\n");

    OutPut = DeQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("DeQueue Value: %i\n", *((uint32 *)OutPut)); //(DeQueue 11)
    }
    printf("#############################################\n");
    OutPut = QueueFront(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("QueueFront Value: %i\n", *((uint32 *)OutPut)); //(QueueFront 22)
    }
    printf("#############################################\n");
    OutPut = DeQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("DeQueue Value: %i\n", *((uint32 *)OutPut)); //(DeQueue 22)
    }
    printf("#############################################\n");
    OutPut = QueueFront(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("QueueFront Value: %i\n", *((uint32 *)OutPut)); //(QueueFront 44)
    }
    printf("#############################################\n");
    OutPut = DeQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("DeQueue Value: %i\n", *((uint32 *)OutPut)); //(DeQueue 44)
    }
    printf("#############################################\n");
    OutPut = QueueFront(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("QueueFront Value: %i\n", *((uint32 *)OutPut)); //(QueueFront 55)
    }
    printf("#############################################\n");

    OutPut = DeQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("DeQueue Value: %i\n", *((uint32 *)OutPut)); //(DeQueue 55)
    }
    printf("#############################################\n");
    OutPut = QueueFront(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("QueueFront Value: %i\n", *((uint32 *)OutPut)); //(QueueFront 55)
    }
    printf("#############################################\n");

    Queue1Status = QueueCount(Queue1, &QueueCounter); printf("Status: %i\n", Queue1Status);
    printf("Queue Count = %i\n", QueueCounter);

    OutPut = DeQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(OutPut)
    {
        printf("DeQueue Value: %i\n", *((uint32 *)OutPut)); //(DeQueue 55)
    }


    Queue1Status = DestroyQueue(Queue1, &Queue1Status); printf("Status: %i\n", Queue1Status);
    if(Queue1Status)
    {
        printf("Queue Destroyed\n");
    }
    return 0;
}
