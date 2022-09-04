#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// doubly linked list implementation

void enQueue(queue *qhead, char name[])
{
    // printf("Work 11\n");
    queue *t = qhead->next;
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->next = NULL;
    strcpy(temp->name, name);
    if (t == NULL)
    {
        // printf("Work 12\n");
        qhead->next = temp;
        // printf("Work 13\n");
    }
    else
    {
        // printf("Work 16\n");
        while (t->next != NULL)
        {
            t = t->next;
        }
        temp->prev = t;
        t->next = temp;
        // printf("Work 17\n");
    }
}

int isEmptyQueue(queue *qhead)
{
    if (qhead->next == NULL)
        return 1;
    return 0;
}

void deQueue(queue *qhead, char *name)
{
    queue *t = qhead->next;
    if (!isEmptyQueue(qhead))
    {
        strcpy(name, t->name);
        qhead->next = t->next;
    }
}