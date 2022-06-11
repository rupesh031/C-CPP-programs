#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *root;
Node* deepest_node;
Node* create(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(int data)
{
    int i = 0;
    Node *arr[20];
    arr[0] = root;
    int f = 0;
    while (1)
    {
        if (arr[i]->left != NULL)
        {
            f++;
            arr[f] = arr[i]->left;
            if (arr[i]->right != NULL)
            {
                f++;
                arr[f] = arr[i]->right;
            }
            else
            {
                arr[i]->right = create(data);
                break;
            }
        }
        else
        {
            arr[i]->left = create(data);
            break;
        }
        i++;
    }
    return;
}
// deepest node
int deepest(Node *node, int lev)
{
    if (lev == 1 && node)
    {
        cout<<"level reached"<<node->data<<endl;
        deepest_node=node;
        return 1;
    }
    if (!node)
    {
        return 0;
    }

    if (lev > 1)
    {
        if(deepest(node->right, lev - 1))  {node->right=NULL;return 0;}
        if(deepest(node->left, lev - 1)) {node->left=NULL; return 0;}
       
    }
}
// deepeset level
int level(Node *node)
{
    if (!node)
        return 0;
    int left_h = level(node->left);
    int right_h = level(node->right);
    return max(left_h, right_h) + 1;
}
void inorder(Node *node)
{
    if (!node)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void del(Node* node,int key)
{
    if (!node)
        return;
    del(node->left,key);
    cout << node->data << " ";
    if (node->data==key)
    {
        cout<<node->data<<endl;
        node->data=deepest_node->data;
    }
    del(node->right,key);


}
int main()
{
    cout << "start" << endl;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->right->left = create(6);
    insert(5);
    insert(9);
    insert(10);
    inorder(root);
    deepest(root, level(root));
    cout << "level " << level(root) << endl;
    cout << deepest_node->data << endl;
    del(root,3);
    delete(deepest_node);
    cout<<"after del"<<endl;
    inorder(root);
    return 0;
}