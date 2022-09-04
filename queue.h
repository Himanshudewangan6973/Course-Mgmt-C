struct Queue
{
    char name[20];
    struct Queue *prev;
    struct Queue *next;
};
typedef struct Queue queue;

void enQueue(queue*, char *);
void mydeQueue(queue*, char *);
int isEmptyQueue(queue *);