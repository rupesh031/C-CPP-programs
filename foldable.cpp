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
void mirror(Node* node)
{
    if(!node)
    return;
    mirror(node->left);
    mirror(node->right);

    Node* temp;
    temp=node->left;
    node->left=node->right;
    node->right=temp;
}
int foldable(Node* node)
{
    if(!node)
    return 1;
    mirror(node->left);
    cout<<endl;
    inorder(node);
    cout<<endl;
    Node* qu[20];
    int i=0;
    int f=1;
    qu[0]=(node->left);
    qu[1]=(node->right);
    while(i<f)
    {
        Node* n1=qu[i];
        Node* n2=qu[i+1];
        if((n1!=NULL&&n2!=NULL) ||(n1==NULL&&n2==NULL))
        {
            if(n1->left||n2->left)
            {
            qu[++f]=n1->left;
            qu[++f]=n2->left;
            }
            if(n1->right||n2->right)
            {
            qu[++f]=n1->right;
            qu[++f]=(n2->right);
            }
        }
        else
        {
            return 0;
        }
        i+=2;
    }
    return 1;
}


int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    root->right->right=create(5);
    cout<<endl;
    inorder(root);
    cout<<endl;
    cout<<"f";
    int f=foldable(root);
    cout<<endl;
    if (f) cout<<"foldable";
    else cout<<"not";
    return 0;
}