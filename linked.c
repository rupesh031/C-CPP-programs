#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head;
void insert(int a)
{
    struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->data = a;
    if (head == NULL)
    {
        head = temp;
        temp->link = NULL;
    }
    else
    {
        struct Node *temp2;
        temp2 = head;
        while (temp2->link != NULL)
        {
            temp2 = temp2->link;
        }
        temp2->link = temp;
        temp->link = NULL;
    }
}
void index_insert(int a, int i)
{
    int f = 0;
    struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->data = a;

    if (i == 1)
    {
        temp->link = head;
        head=temp;
    }
    else
    {
        int f = 1;
        int flag=1;
        struct Node *temp2 = (struct Node*)(malloc(sizeof(struct Node)));
        temp2 = head;
        while (temp2 != NULL)
        {
            if (f == i - 1)
            {
                temp->link = temp2->link;
                temp2->link = temp;
                flag=0;
                break;
            }
            temp2=temp2->link;
            f++;
        }
        if (flag)
        {
            printf("invalid index \n");
        }
    }
}
void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->link;
    }
}
void delete(int n)
{
    struct Node* temp;
    if (n==1)
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    else
    {
        temp=head;
        int f=1;
        int flag=0;
      while (temp!=NULL)
      {
          if (f==n-1)
          {
             struct Node* temp2;
             temp2=temp->link;
             temp->link=temp2->link;
             free(temp2)   ;
            flag=0;
          }
          temp=temp->link;
          f++;
      }
      if (flag)
        printf("invalid del index");
    }
}
void reverse()
{
    struct Node* temp;
    struct Node* temp2;
    struct Node* prev=NULL;
    temp=head;
    while (temp!=NULL)
    {
        temp2=temp->link;
        temp->link=prev;
        prev=temp;
        temp=temp2;
    }
    head=prev;
    printf("while done \n");
    print();
}
void print_rec(struct Node* first)
{
    if (first!=NULL)
    {
        printf("%d ",first->data);
        print_rec(first->link);
        
    }
    else
        return;
} 
void reverse_rec(struct Node* first)
{
    
    if (first->link!=NULL)
    {
        reverse_rec(first->link);
        first->link->link=first;
        first->link=NULL;  
    }
    else
    {
        head=first;
        return;
    }
        

}
int main()
{
    head = NULL;
    int i, n, a,index;
    printf("how many \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("enter data \n");
        scanf("%d", &a);
        insert(a);
    }
    reverse_rec(head);
    print_rec(head);
    reverse_rec(head);
    print_rec(head);
    return 0;
}