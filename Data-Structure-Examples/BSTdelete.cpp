#include  <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *left;
	struct n *right;
};
typedef n node;

node *insert(node *tree,int x){
	if(tree == NULL){
		tree = (node *)malloc(sizeof(node));
		tree->data = x;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	if(tree->data < x){
		tree->right = insert(tree->right,x);
		return tree;
	}
	tree->left = insert(tree->left,x);
	return tree;
}

void traversal(node *tree){
	if(tree == NULL){
		return;
	}
	traversal(tree->left);
	printf("%d\n",tree->data);
	traversal(tree->right);
}

int max(node *tree){
	while(tree->right != NULL){
		tree = tree->right;
	}
	return tree->data;
}

int min(node *tree){
	while(tree->left != NULL){
		tree = tree->left;
	}
	return tree->data;
}

node *deleteF(node *tree,int y){
	if(tree == NULL){
		return NULL;
	}
	if(tree->data == y){
		if(tree->left == NULL && tree->right == NULL){
			return NULL;
		}
		if(tree->right != NULL){
			tree->data = min(tree->right);
			tree->right = deleteF(tree->right,min(tree->right));
			return tree;
		}
		tree->data = max(tree->left);
		tree->left = deleteF(tree->left,max(tree->left));
		return tree;
	}
	if(tree->data < y){
		tree->right = deleteF(tree->right,y);
		return tree;
	}
	tree->left = deleteF(tree->left,y);
	return tree;
}

int main() {
	node *tree = NULL;
	
	tree = insert(tree,12);
	tree = insert(tree,200);
	tree = insert(tree,190);
	tree = insert(tree,213);
	tree = insert(tree,56);
	tree = insert(tree,24);
	tree = insert(tree,18);
	tree = insert(tree,27);
	tree = insert(tree,28);
	
	traversal(tree);
	
	tree = deleteF(tree,27);
	puts(" ");
	traversal(tree);
}
