#include <iostream>
#include <queue>
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
int is_height_bal(Node* node)
{
    int a,b;
    if(node)
    {
    Node* n1=node->left;
    Node* n2=node->right;
     a=is_height_bal(n1);
     b=is_height_bal(n2);
    if(a<0 || b<0)
    {
        return -1;
    }
    else
    {
        if(abs(a-b)<=1)
             return 1+max(a,b);
        else
            return -1; 
    } 
    }
    else
        return 0;
    
}

int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    root->left->right=create(7);
    cout<<endl;
    inorder(root);
    cout<<endl;
    int f=is_height_bal(root);
    if (f==-1) cout<<"not height balanced binary";
    else cout<<"height balanced binary";
    return 0;
}