#include <iostream>
#include <unordered_map>

using namespace std;
static int preIndex = 0;
unordered_map<char,int> map;
struct Node
{
    char data;
    Node* left;
    Node* right;
};
Node* create(char data)
{
    Node* node=new Node();
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return node;
}

int search(char key,char in[],int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(key==in[i])
        return i;
    }

}
Node* cons(char in[],char pre[],int end,int start)
{
    if (start>end)
    {
        return NULL;
    }
    Node* node=create(pre[preIndex++]);
    cout<<preIndex<<endl;
    if (start==end)
    {
        return node;
    }
    int index=search(node->data,in,start,end);
    cout<<index<<endl;
    node->left=cons(in,pre,index-1,start);
    node->right=cons(in,pre,end,index+1);
    return node;
    
}
Node* cons1(char in[],char pre[],int end,int start)
{
    if(start>end)
    return NULL;
    Node* node=create(pre[preIndex++]);
    if(start==end)
    return node;
    int index=map[node->data];
    node->left=cons1(in,pre,index-1,start);
    node->right=cons1(in,pre,end,index+1);
    return node;
}
void inorder(Node* root)
{
    if (!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void ha(char in[],int len)
{
    for(int i=0;i<=len;i++)
    {
        map[in[i]]=i;
    }
    return;
}

int main()
{
    
    char in[]={ 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[]={ 'A', 'B', 'D', 'E', 'C', 'F' };
    int len=sizeof(in)/sizeof(in[0]);
    ha(in,len);
    Node* root=cons1(in,pre,len-1,0);
    inorder(root);
    return 0;
    

}