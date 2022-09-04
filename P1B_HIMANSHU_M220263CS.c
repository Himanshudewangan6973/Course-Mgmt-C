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
        // printf("done 1");
        if (t == NULL)
            printf("None");
        else
        {
            // printf("done 2");
            while (t != NULL)
            {
                // printf("done 5");
                printf("%s ", &t->name);
                t = t->next;
            }
        }
        // printf("done 3");
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
            while (t != NULL)
            {
                printf("%s ", &t->name);
                t = t->next;
            }
        }
        printf("\n");
    }
}

void P1B_WAP()
{
    int noc; // no of course
    printf("No of course?: ");
    scanf("%d", &noc);
    course *courses[noc];
    for (int i = 0; i < noc; i++)
    {
        courses[i] = (course *)malloc(sizeof(course));
    }

    for (int i = 0; i < noc; i++)
    {
        printf(" Course: CODE, NAME, CREDIT, LIMIT %d : ", i + 1);
        scanf("%s %s %d %d", courses[i]->code, courses[i]->name, &courses[i]->credits, &courses[i]->maxLimit);
        courses[i]->regList = (node *)malloc(sizeof(node));
        courses[i]->waitList = (queue *)malloc(sizeof(queue));
        courses[i]->regList->next = NULL;
        courses[i]->waitList->next = NULL;
    }

    int n, cno;
    char name[20];
    node *lhead;
    queue *qhead;
    while (1)
    {
        printf("\nRegister 1, Delete 2, Print student 3, Exit: 4-9,0 ");
        scanf("%d", &n);
        char yn[2];
        switch (n)
        {
        case 1:
            printf("name? , course no? ");
            scanf(" %s %d", name, &cno);
            lhead = courses[cno - 1]->regList;
            qhead = courses[cno - 1]->waitList;
            insert(lhead, qhead, courses[cno - 1]->maxLimit, name);
            break;
        case 2:
            printf("\nDelete => student name? course number?: ");
            scanf("%s %d", name, &cno);
            lhead = courses[cno - 1]->regList;
            qhead = courses[cno - 1]->waitList;
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
}

//--------------------------------------------------------------
int main()
{
    P1B_WAP();
    return 0;
}