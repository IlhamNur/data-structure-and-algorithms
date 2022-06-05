#include <iostream>
#include <algorithm>

class Node {
public:
	int data;
	int height = 1;
	Node *left = nullptr;
	Node *right = nullptr;

	Node(int d) {
		data = d;
	}
};

class AVL {
public:
	Node* insert(Node *root, int key) {
		// Pengisian
		if (!root)
			return new Node(key);
		// Pencarian
		if (key < root->data)
			root->left = insert(root->left, key);
		else if (key >= root->data)
			root->right = insert(root->right, key);

		// Penyeimbangan //
		// Hitung tinggi awal
		root->height = 1 + std::max(height(root->left), height(root->right));

		/*
		 * -1, 0, 1 : seimbang
		 *   < -1   : kiri terlalu tinggi
		 *   > 1    : kanan terlalu tinggi
		 */
		int balance = getBalance(root);
		// Kanan terlalu tinggi & (node kiri seimbang/berat sebelah kanan)
		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);
		// Kiri terlalu tinggi & (node kanan seimbang/berat sebelah kiri)
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);
		// Kanan terlalu tinggi & (node kiri berat sebelah kiri)
		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		// Kiri terlalu tinggi & (node kanan berat sebelah kanan)
		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* deleteNode(Node* root, int key){
		// Pohon sudah kosong
		if (!root)
			return root;
		// Pencarian
		if (key < root->data) {
			root->left = deleteNode(root->left, key);
		} else if (key > root->data) {
			root->right = deleteNode(root->right, key);
		// Penghapusan
		} else {
			if (!root->left) {
				root = root->right;
			} else if (!root->right) {
				root = root->left;
			} else {
				Node *parrentSuc = root;
				Node *successor = root->right;
				while (successor->left) {
					parrentSuc = successor;
					successor = successor->left;
				}
				if (parrentSuc != root)
					parrentSuc->left = successor->right;
				else
					parrentSuc->right = successor->right;
				root->data = successor->data;
				delete successor;
			}
		}
		if (!root)
			return root;

		// Penyeimbangan //
		root->height = 1 + std::max(height(root->left), height(root->right));
		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);
		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	void inOrder(Node *root){
		if (!root)
			return;
		inOrder(root->left);
		std::cout << root->data << " ";
		inOrder(root->right);
	}

private:
	// Fungsi untuk mengecek keseimbangan
	int getBalance(Node *n) {
		if (!n)
			return 0;
		// Tinggi node kiri dikurangi tinggi node kanan
		return height(n->left) - height(n->right);
	}

	// Fungsi untuk mendaparkan tinggi node
	int height(Node *n) {
		if (!n)
			return 0;
		return n->height;
	}

	Node* rightRotate(Node *root) {
		Node *lChild = root->left;
		Node *tmp = lChild->right;
		lChild->right = root;
		root->left = tmp;
		root->height = std::max(height(root->left), height(root->right)) + 1;
		lChild->height = std::max(height(lChild->left), height(lChild->right)) + 1;
		return lChild;
	}

	Node* leftRotate(Node *root){
		Node *rChild = root->right;
		Node *tmp = rChild->left;
		rChild->left = root;
		root->right = tmp;
		root->height = std::max(height(root->left), height(root->right)) + 1;
		rChild->height = std::max(height(rChild->left), height(rChild->right)) + 1;
		return rChild;
	}
};

int main() {
	Node *root = nullptr;
	AVL avl;

	int arr[] = {10, 20, 30, 10, 40, 50, 25};
	for (int o : arr)
		root = avl.insert(root, o);
	avl.inOrder(root);
	std::cout << std::endl;

	avl.deleteNode(root, 30);
	avl.inOrder(root);
	std::cout << std::endl;

	return 0;
}
