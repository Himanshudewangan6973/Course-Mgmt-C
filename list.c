#include "list.h"

void insert(node *lhead, queue *qhead, int maxLimit, char name[])
{
    int len = 1;
    // find length;
    node *t = lhead->next;
    if (t == NULL)
        len = 0;
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
            len++;
        }
    }

    if (maxLimit <= len)
    {
        enQueue(qhead, name);
        return;
    }
    else if (t == NULL)
    {
        t = (node *)malloc(sizeof(node));
        strcpy(t->name, name);
        t->next = NULL;
        // printf("Execution!!\n");
    }
    else if (t->next == NULL)
    { // works
        printf("Success17!!\n");
        node *temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        printf("Success7!!\n");
        strcpy(temp->name, name);
        // printf("Success8!! %s %s\n", lhead->name, name);
        if (strcmp(t->name, name) < 0)
        {
            t->next = temp;
            printf("Success11!!\n");
        }
        else
        { // works
            printf("Success9!!\n");
            temp->next = t;
            t = temp;
        }
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        strcpy(temp->name, name);
        temp->next = NULL;
        node  *curr;
        curr = NULL;
        printf("Success3!!\n");
        while (t != NULL && strcmp(t->name, name) < 0)
        {
            printf("Success4!!\n");
            curr = t;
            t = t->next;
            // i = strcmp(t->name, name);
            printf("Success10!!\n");
        }

        printf("Success5!!\n");
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteS(node *lhead, queue *qhead, char name[], int maxLimit)
{
    node *t, *curr;
    curr = lhead->next;
    printf("Exec 4!!\n");
    if (curr == NULL)
        return;
    else if (curr->next == NULL && strcmp(curr->name, name) == 0)
    {
        lhead = NULL;
        printf("Exec 1!!\n");
    }
    else
    {
        t = curr->next;
        if (strcmp(curr->name, name) == 0)
        {
            lhead = curr->next;
        }
        else
        {
            while (strcmp(t->name, name) != 0)
            {
                if (t->next != NULL)
                    curr = t;
                t = t->next;
            }
            curr->next = t->next;
        }
    }
    if (!isEmptyQueue(qhead))
    {
        deQueue(qhead, name);
        insert(lhead, qhead, maxLimit, name);
    }
}

/*
4
cse123 ssl 5 2
csis56 dc 6 3
it7546 os 8 1
go4829 kid 6 2
1
y
harsh 1
y
akash 1
y
himanshu 1
y
tejash 1
y
mohit 2
y
rohit 2
y
swati 3
y
trishant 3
y
ayush 3
n
3


akash harsh himanshu tejash
mohit rohit
swati

*/