#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// doubly linked list implementation

void enQueue(queue *qhead, char name[])
{
    printf("Work 11\n");
    if (qhead == NULL)
    {
        printf("Work 12\n");
        qhead = (queue *)malloc(sizeof(queue));
        qhead->next = NULL;
        qhead->prev = qhead;
        strcpy(qhead->name, name);
        printf("Work 13\n");
    }
    else if (qhead->next == NULL)
    {
        printf("Work 14\n");
        qhead->next = (queue *)malloc(sizeof(queue));
        qhead->next->next = NULL;
        qhead->next->prev = qhead;
        strcpy(qhead->next->name, name);
        printf("Work 15\n");
    }
    else
    {
        printf("Work 16\n");
        queue *t = qhead->next;
        while (t->next != NULL)
        {
            t = t->next;
        }
        queue *temp = (queue *)malloc(sizeof(queue));
        temp->next = NULL;
        strcpy(temp->name, name);
        temp->prev = t;
        t->next = temp;
        printf("Work 17\n");
    }
}

int isEmptyQueue(queue *qhead)
{
    if (qhead == NULL)
        return 1;
    return 0;
}

void deQueue(queue *qhead, char *name)
{
    if (!isEmptyQueue(qhead))
    {
        strcpy(name, qhead->name);
        qhead = qhead->next;
    }
}