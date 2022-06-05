#include <iostream>

typedef struct Node {
	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
} Node;

typedef struct BST {
	Node *root = nullptr;

	Node* search(int k) {
		Node *p = this->root;
		while (p->value != k) {
			if (k < p->value) {
				if (p->left) p = p->left;
				else return nullptr;
			} else {
				if (p->right) p = p->right;
				else return nullptr;
			}
		}
		return p;
	}

	Node* insert(int k) {
		Node *n = new Node;
		n->value = k;
		if (!this->root) {
			this->root = n;
			return n;
		}
		Node *p = this->root;
		while (p) {
			if (k < p->value) {
				if (p->left) p = p->left;
				else break;
			} else {
				if (p->right) p = p->right;
				else break;
			}
		}
		if (k < p->value)
			p->left = n;
		else
			p->right = n;
		return n;
	}

	Node* minVal(Node *n) {
		Node *cur = n;
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	Node* del(Node *root, int k) {
		if (!root)
			return root;
		if (k < root->value) {
			root->left = del(root->left, k);
		} else if (k > root->value) {
			root->right = del(root->right, k);
		} else {
			if (!root->left) {
				Node *temp = root->right;
				delete root;
				return temp;
			} else if (!root->right) {
				Node *temp = root->left;
				delete root;
				return temp;
			}
		Node *temp = minVal(root->right);
		root->value = temp->value;
		root->right = del(root->right, temp->value);
		}
		return root;
	}
} BST;

int main() {
	BST *tree = new BST;
	tree->insert(10);
	tree->insert(9);
	tree->insert(8);
	tree->insert(11);
	tree->insert(12);
	tree->del(tree->root, 9);
	std::cout << "8: "  << (tree->search(8) == nullptr ? "tidak ketemu" : "ketemu") << std::endl;
	std::cout << "9: "  << (tree->search(9) == nullptr ? "tidak ketemu" : "ketemu") << std::endl;
	std::cout << "10: " << (tree->search(10) == nullptr ? "tidak ketemu" : "ketemu") << std::endl;
	std::cout << "11: " << (tree->search(11) == nullptr ? "tidak ketemu" : "ketemu") << std::endl;
	std::cout << "12: " << (tree->search(12) == nullptr ? "tidak ketemu" : "ketemu") << std::endl;
}
