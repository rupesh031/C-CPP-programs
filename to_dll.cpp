#include <iostream>
using namespace std;

  
struct Node
{
    int data;
    Node* left;
    Node* right;
};
struct dll
{
    int data;
    dll* next;
    dll* prev;
};
Node* create(int data)
{
    Node* node=new Node();
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return node;
}
dll* dll_node()
{
    dll* node=new dll();
    node->next=NULL;
    node->prev=NULL;
    return node;
}
void insert(Node* root,int data)
{
    int i=0;
    Node* arr[20];
    arr[0]=root;
    int f=0;
    while(1)
    {
        if(arr[i]->left!=NULL)
            {
                f++;
                arr[f]=arr[i]->left;
                if(arr[i]->right!=NULL)
                {
                    f++;
                    arr[f]=arr[i]->right;
                }
                else
                {
                    arr[i]->right=create(data);
                  
                    break;
                }
            }
        else
        {
            arr[i]->left=create(data);
           
            break;
        }
        i++;
    }
    return;
}

void insert_dll(int data,dll* head)
{
    if(!(head->data))
    {
        head->data=data;
        return;
    }
    while(head->next)
    {
        head=head->next;
    }
    dll* node=new dll();
    head->next=node;
    node->prev=head;
    node->data=data;
    return;
}

void to_dll(Node* node,dll* head)
{

    if(!node)
    return;
    to_dll(node->left,head);
    insert_dll(node->data,head);
    to_dll(node->right,head);
}
dll* head=dll_node();
int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    
    to_dll(root,head);
    cout<<endl;
    while(head)
    {
        cout<<head->data;
        head=head->next;
    }

    return 0;
}

