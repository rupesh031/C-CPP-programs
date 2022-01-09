#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* link;

};
struct Node* head;
void pop()
{
    if(head)
    {
        printf("%d \n",head->data);
        struct Node* temp=head;
        head=temp->link;
        free(temp);
    }
    else
        printf("under-flow");
    
}
void peek()
{
     if(head)
        printf("%d \n",head->data);
    else
        return;

}
void insert(int a)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->link=head;
    temp->data=a;
    head=temp;

}
void main()
{
    head=NULL;
    int n,c,f=1;
    
    while(f)
    {
    printf("1. insert\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. exit\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("data :");
        scanf("%d",&n);
        insert(n);
        break;
    case 2:
        pop();
        break;
    case 3: 
        peek();
        break;
    
    default:
        f=0;
        break;
    }

    }
    

}