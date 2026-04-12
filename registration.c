#include <stdio.h>
#include <string.h>
#define N 10
typedef struct student
{
    int id;
    char name[50];
}student;

typedef struct queue
{
    student a[N];
    int front,rear,count;
}queue;

void enqueue(queue * q,student x)
{
    if(q->count == N)
    {
        printf("\nRegistrations are full!!\n");
    }
    else
    {
        q->count++;
        q->rear = (q->rear + 1) % N;
        q->a[q->rear] = x;
        printf("\nRegistration Successful...\n");
    }
}
