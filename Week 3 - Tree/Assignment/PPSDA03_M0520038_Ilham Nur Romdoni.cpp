#include<iostream>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void postorder(struct node *root) {
   if (root != NULL) {
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
int main() {
   struct node *root = NULL;
   root = insertNode(root, 57);
   insertNode(root, 78);
   insertNode(root, 85);
   insertNode(root, 96);
   insertNode(root, 90);
   insertNode(root, 81);
   insertNode(root, 32);
   insertNode(root, 48);
   insertNode(root, 39);
   insertNode(root, 43);
   insertNode(root, 35);
   insertNode(root, 24);
   cout<<"Post-Order traversal of the Binary Search Tree is: ";
   postorder(root);
   return 0;
}
