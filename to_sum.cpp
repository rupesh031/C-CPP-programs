#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
Node* node= new Node();
node->data=data;

node->left=NULL;
node->right=NULL;
return node;
}

//inorder transveral
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

void inorder(Node* root)
{
    if (!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int to_sum(Node* root)
{
    if(!root)
    return 0;
    int a=to_sum(root->left);
    int b=to_sum(root->right);
    int temp=root->data;
    root->data=a+b;
    return temp+root->data;

}
int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,-2);
    inorder(root);
    cout<<endl;
    int a=to_sum(root);
    cout<<endl;
    inorder(root);
    return 0;
}

