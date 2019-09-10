#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n * next;
};
typedef n node;

void print(node * r){
	while (r != NULL){
		printf("%d\n",r->x);
		r = r->next;
	}
}
void insert(node *r,int x){
	while(r->next != NULL){
		r = r->next;
	}
	r->next = (node *)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

int main () {
	node * root;
	root = (node *)malloc(sizeof(node));
	root -> next = NULL;
	root -> x = 500;
	node * iter;
	iter = root;
	
	int i;
	for (i=1;i<=5;i++) {
		insert(iter,i*10);
	}
	print(root);
}
