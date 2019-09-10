#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
};
typedef n node;

void print(node *r){
	while(r != NULL){
		printf("%d\n",r->data);
		r = r->next;
	}
}

void insert(node *r,int x){
	while (r->next != NULL){
		r = r->next;
	}
	r->next = (node *)malloc(sizeof(node));
	r->next->data = x;
	r->next->next = NULL;
}

int main () {
	node *root;
	root = (node *)malloc(sizeof(node));
	root->data = 10;
	root->next = NULL;
	
	for (int i=2;i<=10;i++){
		insert(root,i*10);
	}
	
	node *iter = root;
	
	for(int j=0;j<5;j++){
		iter = iter->next;
	}

	node *temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = 65;
	
	print(root);
}
