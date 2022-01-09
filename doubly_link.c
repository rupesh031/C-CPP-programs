#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

void insert(int a)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = a;
    if (head != NULL)
    {
        struct Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp->prev = temp1;
        temp->next = NULL;
        temp1->next = temp;
    }
    else
    {
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
}
void index_insert(int a, int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = a;
    int f = 1;
    int flag = 1;
    if (n == 1)
    {
        temp->prev = NULL;
        temp->next = head;
        if (head)
        {
            head->prev = temp;
        }
        head = temp;
    }
    else
    {
        struct Node *temp2 = head;
        while (temp2 != NULL)
        {
            if (f == n - 1)
            {
                flag = 0;
                temp->prev = temp2;
                temp->next = temp2->next;
                temp2->next = temp;
                if (temp->next)
                {
                    temp->next->prev = temp;
                }
                
            }
            temp2 = temp2->next;
            f++;
        }
        if (flag)
        {
            printf("invalid index");
            free(temp);
        }
    }
}
void print()
{
    struct Node *temp = head;
    struct Node *bhead;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        bhead = temp;
        temp = temp->next;
    }
    printf("\n");
    while (bhead != NULL)
    {
        printf("%d ", bhead->data);
        bhead = bhead->prev;
    }
    printf("\n");
}
void reverse()
{
    struct Node *temp;
    temp=head;
    while (temp->next!=NULL)
    {
        struct Node *temp2= temp->next;
        temp->next=temp->prev;
        temp->prev=temp2;
        temp=temp2;
    }
    head=temp->prev->prev;
    temp->next=temp->prev;
    temp->prev=NULL;

}
void main()
{
    head = NULL;
    int i = 0;
    int n, a, index;
    printf("how many?\n");
    scanf("%d", &n);
    while (i < n)
    {
        printf("data ");
        scanf("%d", &a);
        printf("index ");
        scanf("%d", &index);
        index_insert(a, index);
        i++;
    }
    print();
    reverse();
    print();
}