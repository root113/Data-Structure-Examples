#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *left;
	struct n *right;
};
typedef n node;

node *insert(node *tree,int x){
	if(tree == NULL){
		node *r = (node *)malloc(sizeof(node));
		r->left = NULL;
		r->right = NULL;
		r->data = x;
		return r;
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

int find(node *tree,int f){
	if(tree == NULL){
		return -1;
	}
	if(tree->data == f){
		return 1;
	}
	if(find(tree->left,f) == 1){
		return 1;
	}
	if(find(tree->right,f) == 1){
		return 1;
	}
	return -1;
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
	
	printf("\nResponse: %d",find(tree,100));
	printf("\nResponse: %d",find(tree,27));
	
	printf("\n\nMax data: %d",max(tree));
	printf("\nMin data: %d",min(tree));
}
