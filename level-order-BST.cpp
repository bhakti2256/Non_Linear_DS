#include <iostream>
#include <queue>
using namespace std;
struct node
{
    char data;
    node *left;
    node *right;
};

node *GetNewNode(char data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, char data)
{
    if (root == NULL)
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

void levelorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        node *current = Q.front();
        Q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
    //root = insert(root, 'E');

    levelorder(root);

    return 0;
}