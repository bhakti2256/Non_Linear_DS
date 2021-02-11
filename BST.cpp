//Binary Tree 
//Operations included:
//  create tree
//  search a number
//  find min number
//  find max number
//  find height

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *GetNewNode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int data)
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

bool search(node *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
//iterative solution
/*
int Findmin(node * root){
    if(root == NULL){
        cout<<"Error: Tree is empty";
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}*/

//Recursive method:
int Findmin(node *root)
{
    if (root == NULL)
    {
        cout << "Error";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return Findmin(root->left);
}

int Findmax(node *root)
{
    if (root == NULL)
    {
        cout << "Error";
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return Findmax(root->right);
}

int FindHeight(node *root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
        return -1; //for counting number of nodes do return 0
    leftHeight = FindHeight(root->left);
    rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    int min, max, height;
    node *root = NULL; //creating a tree
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 10);
    int num;
    cout << "Enter number to be searched: ";
    cin >> num;
    if (search(root, num) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";
    min = Findmin(root);
    max = Findmax(root);

    cout << "\nMinimum number is: " << min << endl;
    cout << "Maximum number is: " << max << endl;

    height = FindHeight(root);
    cout << "Heigth of BST: " << height << endl;

    return 0;
}