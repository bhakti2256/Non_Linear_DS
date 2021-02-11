#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node * GetNewNode(int data){
    node * newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


node * insert(node * root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }

    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    int num;
    while(num != 0)
    {
    cout<< "Enter the number to be added(enter 0 to quit): ";
    cin>>num;
    root = insert(root,num);
    }
    return 0;
}