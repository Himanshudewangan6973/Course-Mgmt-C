#include "list.h"

void insert(node *lhead, queue *qhead, int maxLimit, char name[])
{
    int len = 1;
    //                               find length;
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
    // printf("Execution 00!!\n");
    t = lhead->next;
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    strcpy(temp->name, name);

    if (maxLimit <= len)
    {
        enQueue(qhead, name);
        return;
    }
    else if (t == NULL)
    {
        lhead->next = temp;
        // printf("Execution!!\n");
    }
    else
    {
        node *curr = lhead;
        // printf("Success3!!\n");
        while (t != NULL && strcmp(t->name, name) < 0)
        {
            // printf("Success4!!\n");
            curr = t;
            t = t->next;
            // i = strcmp(t->name, name);
            // printf("Success10!!\n");
        }

        // printf("Success 5!!\n");
        temp->next = curr->next;
        // printf("Success 09!!\n");
        curr->next = temp;
    }
}

void deleteS(node *lhead, queue *qhead, char name[], int maxLimit)
{
    node *t, *curr;
    t = lhead->next;
    curr = t;
    // printf("Exec 4!!\n");
    if (t == NULL)
        return;
    else
    {
        // t = t->next;
        // printf("Exec 1!!\n");
        if (strcmp(t->name, name) == 0)
        {
            lhead->next = t->next;
            // printf("Exec 2!!\n");
        }
        else
        {
            // printf("Exec 3!!\n");
            while (strcmp(t->name, name) != 0)
            {
                // printf("Exec 08!!\n");
                if (t->next != NULL)
                    curr = t;
                // printf("Exec 06!!\n");
                t = t->next;
            }
            // printf("Exec 07!!\n");
            curr->next = t->next;
        }
    }
    if (!isEmptyQueue(qhead))
    {
        // printf("queue 1 %s\n", name);
        deQueue(qhead, name);
        // printf("queue 2 %s\n", name);
        insert(lhead, qhead, maxLimit, name);
        // printf("queue 3");
    }
}

/*
4
cse123 ssl 5 3
csis56 dc 6 3
it7546 os 8 1
go4829 kid 6 2
1
harsh 1
1
akash 1
1
himanshu 1
1
tejash 1
1
rohit 2
1
mohit 2
1
swati 3
1
trishant 3
1
ayush 3
3


akash harsh himanshu tejash
mohit rohit
swati

*/