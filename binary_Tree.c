#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* new(int data)
{
    struct Node* temp=(struct Node*)(malloc(sizeof(struct Node)));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}
void inorder(struct Node* node)
{
    if(node==NULL)
    return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}
void preorder(struct Node* node)
{
    if (!node)
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
   

}
void postorder(struct Node* node)
{
    if(node==NULL)
    return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}
int main()
{
    struct Node* root=new(1);
    root->left=new(2);
    root->right=new(3);
    root->left->left=new(4);
    root->left->right=new(5);
    printf("in-order \n");
    inorder(root);
     printf("\npre-order \n");
    preorder(root);
    printf("\npost-order \n");
    postorder(root);
    return 0;
}