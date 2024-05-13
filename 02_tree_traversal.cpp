#include <iostream>
using namespace std;

struct node {
  int item;
  node* left;
  node* right;
};

// Inorder traversal
void inorderTraversal(node* root) {
  if (root == nullptr) return;
  inorderTraversal(root->left);
  cout << root->item << " -> ";
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(node* root) {
  if (root == nullptr) return;
  cout << root->item << " -> ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(node* root) {
  if (root == nullptr) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->item << " -> ";
}

// Create a new Node
node* createNode(int value) {
  node* newNode = new node;
  newNode->item = value;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

// Insert on the left of the node
node* insertLeft(node* root, int value) {
  root->left = createNode(value);
  cout << "Left Node inserted with value : " << value << endl;
  return root->left;
}

// Insert on the right of the node
node* insertRight(node* root, int value) {
  root->right = createNode(value);
  cout << "Right Node inserted with value : " << value << endl;
  return root->right;
}

int main() {
  int rootNode = 1;
  node* root = createNode(rootNode);
  cout << "Started tree with root : " << rootNode << endl;
  insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);

  cout << "\nInorder traversal \n";
  inorderTraversal(root);
  cout << endl;

  cout << "\nPreorder traversal \n";
  preorderTraversal(root);
  cout << endl;

  cout << "\nPostorder traversal \n";
  postorderTraversal(root);
  cout << endl;

  return 0;
}
