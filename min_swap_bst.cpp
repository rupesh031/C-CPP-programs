#include <iostream>
#include <unordered_map>
using namespace std;

int min_swap(int a[], int n)
{
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        mp1[a[i]] = i;
    }
    int i = 0;
    int swap = 0;
    while (i < n)
    {
        if (!mp2[b[i]])
        {
            mp2[b[i]] = 1;
            if (i != mp1[b[i]])
            {
                int c = mp1[b[i]];
                int temp = b[i];
                b[i] = b[c];
                b[c] = temp;
                i = min(i, c);
                swap++;
                continue;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return swap;
}
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

void inorder(Node* root,int a[10],int* i)
{
    if (!root)
    return;
    inorder(root->left,a,i);
    a[(*i)++]=root->data;
    cout<<root->data<<" ";
    inorder(root->right,a,i);
}
int min_bst(Node* root)
{
    int a[10];
    int i=0;
    inorder(root,a,&i);
    cout<<endl;
    cout<<i<<endl;
    cout<<a[i-1];
    return min_swap(a,i);

}
int main()
{
    Node* root=create(5);
    insert(root,6);
    insert(root,7);
    insert(root,8);
    insert(root,9);
    insert(root,10);
    insert(root,11);
    int n=min_bst(root);
    cout<<endl<<"number of swaps "<<n;
    return 0;
}