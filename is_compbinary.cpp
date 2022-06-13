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
int level(Node* node)
{
    
    if(node)
    {
    Node* n1=node->left;
    Node* n2=node->right;
    return 1+max(level(n1),level(n2));
    }
    else
    {
        return 0;
    }
    
}

bool is_comp(Node* node,int level,bool &fur)
{
    Node* n1=node->left;
    Node* n2=node->right;
    if(level==2)
    {
        if(n1&&n2)
        return true;
        else if((!n1)&&n2)
        return false;
        else
        {
            return true||fur;
            fur=false;
        }

    }
    else if(n1&&n2)
    {
        bool a =is_comp(n1,level-1,fur);
        bool b=is_comp(n2,level-1,fur);
        return a&&b;
    }
    else
    {
        return false;
    }

    
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
    cout<<"f";
    bool fur=true;
    bool f=is_comp(root,level(root),fur);
    cout<<endl<<level(root);
    if (f) cout<<"comp binary";
    else cout<<"not comp binary";
    return 0;
}