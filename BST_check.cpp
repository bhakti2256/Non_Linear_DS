#include<iostream>
#include <climits>
using namespace std;

struct Node {
	int data;
	Node* left , *right;
	Node(int data): data(data), left(NULL), right(NULL) {}
};



bool isBST(Node* root, int minn, int maxx)
{
	/* An empty tree is also a BST*/
	if (root == NULL)
		return true;

	/* The node data should be in between minn and maxx , other wise just return false*/
	if (root->data < minn || root->data > maxx)
		return false;

	/* Check recursively for the left and right subtree..*/
	return (isBST(root->left, minn, root->data - 1) && isBST(root->right, root->data + 1, maxx));
}


void inorder(Node* root)
{
	if (root == NULL)
		return;


	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{

	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(100);
	root->left->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(7);


	if (isBST(root, INT_MIN, INT_MAX))
		cout << "It is BST";
	else
		cout << "It is not BST";


	return 0;

}