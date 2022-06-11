#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* root;
Node* create(int data)
{
Node* node= new Node();
node->data=data;
cout<<node->data;
node->left=NULL;
node->right=NULL;
return node;
}

//inorder transveral
void insert(int data)
{
    int i=0;
    Node* arr[20];
    arr[0]=root;
    int f=0;
    cout<<arr[0]->data;
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
                    cout<<endl<<arr[i]->left->data;
                    break;
                }
            }
        else
        {
            arr[i]->left=create(data);
            cout<<"right"<<endl;
            break;
        }
        i++;
    }
    return;
}
int main()
{
    cout<<"start"<<endl;
    root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->right->left=create(6);
    insert(5);
    return 0;
}