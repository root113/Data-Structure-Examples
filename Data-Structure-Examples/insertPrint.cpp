#include <stdio.h>
#include <stdlib.h>

struct n {
	int x;
	struct n *next;
};
typedef n node;

void print(node *r){
	while(r!=NULL){
		printf("%d\n",r->x);
		r = r->next;
	}
}

void insert(node *r,int y){
	while(r->next != NULL){
		r = r->next;
	}
	r->next = (node *)malloc(sizeof(node));
	r->next->x = y;
	r->next->next = NULL;
}

int main () {
	node *root;
	root = (node *)malloc(sizeof(node));
	root->x = 1;
	root->next = NULL;
	
	for (int i=1; i<10; i++){
		insert(root,i+1);
	}
	
	print(root);
}
