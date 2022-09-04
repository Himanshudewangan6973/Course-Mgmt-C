#include "queue.c"

struct Node
{
    char name[20];
    struct Node *next;
};
typedef struct Node node;

void insert(node *, queue *, int, char[]);
void deleteS(node *, queue *, char [], int );