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
        x=q->a(q->front);
        q->front=(q->front+1)%N;
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

int main()
{
    int ch;
    student x;
    queue q;

    q.front=0;
    q.rear=-1;
    q.count=0;

    while(1)
    {
        printf("\n===== MENU =====");
        printf("\n1-REGISTER STUDENT");
        printf("\n2-REMOVE STUDENT");
        printf("\n3-DISPLAY STUDENTS");
        printf("\n4-EXIT");
        printf("\nEnter Choice = ");
        scanf("%d",&ch);

        if(ch==4)
            break;

        switch(ch)
        {
            case 1:
            {
                printf("\nEnter Student ID = ");
                scanf("%d",&x.id);

                printf("Enter Student Name = ");
                scanf(" %[^\n]",x.name);

                enqueue(&q,x);
            }
            break;

            case 2:
            {
                x=dequeue(&q);

                if(x.id==-1)
                    printf("\nNo Registration Found...");
                else
                    printf("\nRemoved Student: %s (ID = %d)",x.name,x.id);
            }
            break;

            case 3:
            {
                display(&q);
            }
            break;

            default:
            {
                printf("\nInvalid Choice...");
            }
        }
    }

    return 0;
}
