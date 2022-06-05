#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node(int d){
			data = d;
			left = right = NULL;
		}
};

class BST{
	public:
		Node* insert(Node *root, int value){
			if(root==NULL)return new Node(value);
			
			Node *tmp;
			if(root->data>value){
				tmp = insert(root->left, value);
				root->left = tmp;
			}else{
				tmp = insert(root->right, value);
				root->right = tmp;
			}
			return root;
		}
		
		void inOrder(Node *root){
			if(root==NULL)return;
			inOrder(root->left);
			cout<<root->data<<" ";
			inOrder(root->right);
		}
		
		//k = nilai yang dicari
		bool search(Node *root, int k){
			//data tidak ditemukan
			if(root==NULL)return false;
//			if(!root)
			
			//data ditemukan
			if(root->data==k)return true;
			
			if(root->data>k){
				return search(root->left, k);
			}else if(root->data<k){
				return search(root->right, k);
			}
		}
		
		//k = nilai yang mau dihapus
		Node* deleteNode(Node *root, int k){
			//pembatalan
			if(root==NULL)return root;
			
			//pencarian
			if(root->data>k){
				root->left = deleteNode(root->left, k);
				return root;
			}else if(root->data<k){
				root->right = deleteNode(root->right, k);
				return root;
			}
			
			//pengahapusan
			if(root->left==NULL){ 
				//jika node yang mau dihapus tidak memiliki anak sebelah kiri
				//maka yang menggantikan node sebelah kanan
				Node *tmp = root->right;
				delete root;
				return tmp;
			}else if(root->right==NULL){
				//jika node yang mau dihapus tidak memiliki anak sebelah kanan
				//maka yang menggantikan node sebelah kiri
				Node *tmp = root->left;
				delete root;
				return tmp;
			}else{ //jika node dihapus memliki dua anak 
				Node *parent_pengganti = root;
				Node *pengganti = root->right;
				
				//successor
				//root paling kiri dari root sebelah kanan yang mau dihapus
				while(pengganti->left!=NULL){
					parent_pengganti = pengganti;
					pengganti = pengganti->left;
				}
				
				//jika punya successor
				if(pengganti->right!=root){ 
					//jika root paling kiri punya anak sebelah kanan
					parent_pengganti->left = pengganti->right;
				}else{  
					parent_pengganti->right = pengganti->right;
				}
				
				//data dihapus diganti data dari successor
				root->data = pengganti->data;
				
				//successor dihapus
				delete pengganti;
				return root;
			}
			
			
		}
		
		
};

int main(){
	int arr[] = {45, 24, 90, 57, 12};
	Node *root = NULL;
	BST bst;
		
	for(int i=0;i<5;i++){
		root = bst.insert(root, arr[i]);
	}
	
	bst.inOrder(root);
	cout<<endl;

	root = bst.deleteNode(root, 90);
	
	bst.inOrder(root);
	
	return 0;
}

