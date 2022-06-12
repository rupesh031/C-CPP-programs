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

bool is_full(Node* node)
{
    bool a,b;
    Node* n1=node->left;
    Node* n2=node->right;
    if( (n1&&n2) || ((!n1)&&(!n2)))
    {
        if(n1&&n2)
        {
             a=is_full(n1);
             b=is_full(n2);
        } 
        else
        {
            return true;
        }
    
    }
    else
    {
        return false;
    }
    return a&&b;
}

int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    cout<<endl;
    inorder(root);
    cout<<endl;
    cout<<"f";
    bool f=is_full(root);
    cout<<endl;
    if (f) cout<<"full binary";
    else cout<<"not full binary";
    return 0;
}