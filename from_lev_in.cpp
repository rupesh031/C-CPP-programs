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

Node* build(int lev[],int in,int start,int end)
{
   if (start>end)
   return NULL;
   Node* node=create(lev[levIndex++])

}

int main
{


}