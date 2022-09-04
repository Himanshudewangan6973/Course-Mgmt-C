#include "list.c"

//                      Global Course structure
struct Course
{
    char code[8];
    char name[3];
    int credits;
    int maxLimit;
    node *regList;
    queue *waitList;
};
typedef struct Course course;

void printregList(course *cdetails[], int noc)
{
    for (int i = 0; i < noc; i++)
    {
        node *t = cdetails[i]->regList->next;
        if (t == NULL)
            printf("None");
        else
        {
            printf("%s ", &t->name);
            // t = t->next;
            while (t->next != NULL)
            {
                t = t->next;
                printf("%s ", &t->name);
                // printf(" Name ");
            }
        }
        printf("\n");
    }
}

void printwaitList(course *cdetails[], int noc)
{
    for (int i = 0; i < noc; i++)
    {
        queue *t = cdetails[i]->waitList->next;
        if (t == NULL)
            printf("None");
        else
        {
            printf("%s ", &t->name);
            while (t->next != NULL)
            {
                t = t->next;
                printf("%s ", &t->name);
            }
        }
        printf("\n");
    }
}

//--------------------------------------------------------------
int main()
{
    int noc; // no of course
    printf("No of course?: ");
    scanf("%d", &noc);
    course *courses[noc];
    for (int i = 0; i < noc; i++)
    {
        courses[i] = (course *)malloc(sizeof(course));
    }

    node *lhead = (node *)malloc(sizeof(node));
    queue *qhead = (queue *)malloc(sizeof(queue));

    for (int i = 0; i < noc; i++)
    {
        printf(" Course: CODE, NAME, CREDIT, LIMIT %d : ", i + 1);
        scanf("%s %s %d %d", courses[i]->code, courses[i]->name, &courses[i]->credits, &courses[i]->maxLimit);
        courses[i]->regList = lhead;
        lhead = NULL;
        courses[i]->waitList = qhead;
        qhead = NULL;
    }

    int n, cno;
    char name[20];
    while (1)
    {
        printf("Register 1, Delete 2, Print student 3, Exit: any key ");
        scanf("%d", &n);
        char yn[2];
        switch (n)
        {
        case 1:
            printf("register student? (y/n): ");
            scanf("%s", yn);
            while (strcmp(yn, "y") == 0)
            {

                printf("name? , course no? ");
                scanf(" %s %d", name, &cno);
                lhead = courses[cno - 1]->regList;
                qhead = courses[cno - 1]->waitList;
                lhead->next = NULL;
                qhead->next = NULL;
                insert(lhead, qhead, courses[cno - 1]->maxLimit, name);
                printf("New student? (y/n): ");
                scanf("%s", yn);
            }
            break;
        case 2:
            printf("Delete => student name? course number?: ");
            scanf("%s %d", name, &cno);
            lhead = courses[cno - 1]->regList;
            qhead = courses[cno - 1]->waitList;
            lhead->next = NULL;
            qhead->next = NULL;
            deleteS(lhead, qhead, name, courses[cno - 1]->maxLimit);
            break;
        case 3:
            printf("\nRegistration List\n");
            printregList(courses, noc);
            printf("\nWait List\n");
            printwaitList(courses, noc);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}