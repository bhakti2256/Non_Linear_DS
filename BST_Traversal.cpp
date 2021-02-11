#include <iostream>
#include <queue>

using namespace std;

//Creating a node
struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *root, int data); //Declaration of inserting a node
void levelOrder(node *); //Level-Order / Breadth-First Traversal
void Inorder(node *); //Inorder
void Preorder(node *); //Preorder
void Postorder(node *); //Postorder

int main()
{
    node *root = NULL;
    int x, choice, num_of_node;

    cout << "\n---Creation of a Binary Tree---\n";
    cout << "How many nodes/numbers you wish to add in Binary Tree? ";
    cin >> num_of_node;

    for (int i = 0; i < num_of_node; i++) //loop to create tree
    {
        cout << "Enter the Number: ";
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nHow you want to see the tree created?\n";

    cout << "1. Level Order Traversal" << endl;
    cout << "2. Inorder Traversal" << endl;
    cout << "3. Preorder Traversal" << endl;
    cout << "4. Postorder Traversal" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        levelOrder(root);
        break;
    case 2:
        cout << "\n-Inorder Traversal:-\n";
        Inorder(root);
        break;
    case 3:
        cout << "\n-Preorder Traversal:-\n";
        Preorder(root);
        break;
    case 4:
        cout << "\n-Postorder Traversal:-\n";
        Postorder(root);
        break;
    default:
        cout << "Enter a valid option";
        break;
    }

    return 0;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
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

void levelOrder(node *root)
{
    cout << "\n-Level Order Traversal:-\n";
    if (root == NULL)
        return;
    queue<node *> Q;
    Q.push(root);

    //Iteration used
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

void Inorder(node *root)
{
    //Base Condition
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(node *root)
{
    //Base Condition
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node *root)
{
    //Base Condition
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}