#include <iostream>
#include <stack>
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
bool not_temp(Node* node,Node* temp[10])
{
    int i=0;
    for(i=0;i<9;i++)
    {
        if(node==temp[i])
        return true;
    }
    return false;
}
void inorder_l(Node* root)
{
   stack<Node*> s;
   Node* curr=root;
   
   while(s.empty()==false || curr!=NULL)
   {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        cout<<curr->data<<" ";
        s.pop();
       
        curr=curr->right;
   }

}
void inorder_morris(Node* root)
{
   Node* curr;
   Node* pre;
   curr=root;
   while(curr)
   {
    if(curr->left==NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    else
    {
        pre=curr->left;
        while(pre)
        {
            if(pre->right && pre->right!=curr)
            {
                pre=pre->right;
            }
            else
            {
                if(pre->right==curr) 
                {
                    cout<<curr->data<<" ";
                    pre->right=NULL;
                    curr=curr->right;
                }
                else 
                {
                    pre->right=curr;
                    curr=curr->left;
                }
                break;
            }
        }
    }
   }
}
int main()
{
    Node* root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    root->left->right->left=create(6);
    cout<<endl;
    inorder_l(root);
    cout<<endl;
    inorder_morris(root);
    return 0;
}