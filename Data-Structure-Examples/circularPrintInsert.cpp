#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
};
typedef n node;

void insert(node *r,int x){
	node *iter = r;
	while(iter->next != r){
		iter = iter->next;
	}
	iter->next = (node *)malloc(sizeof(node));
	iter->next->data = x;
	iter->next->next = r;
}

void print(node *r){
	node *iter = r;
	printf("%d\n",iter->data);
	iter = iter->next;
	while(iter != r){
		printf("%d\n",iter->data);
		iter = iter->next;
	}
}

int main () {
	node *root = (node *)malloc(sizeof(node));
	root->data = 10;
	node *iter = root;
	iter->next = root;
	
	for(int i=2;i<=10;i++){
		insert(iter,i*10);
	}
	
	print(root);
}
