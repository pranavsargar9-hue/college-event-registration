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
int isempty(queue*q)
{
    if(q->count==0)
        return 1;
    else
        return 0;
}
student dequeue(queue*q)
{
    student x;
    x.id=-1;
    if(isempty(q))
        return x;
    else
    {
        q->count--;
        x=q->a[q->front];
        q->front=[q->front+1]%N;
        return x;
    }
}

void display(queue *q)
{
    int i;
    if(isempty(q))
    {
        printf("\nNo students registered....");
    }
    else
    {
        printf("\nregistered students:\n");
        i=q->front;
        while(1)
        {
            printf("\nlD=%d",q->a[i].id);
            printf("\nName=%s\n",q->a[i].name);
            if(i==q->rear)
            {
                break;
            }
            else
            {
                i=(i+1)%N;
            }
        }
    }
}
