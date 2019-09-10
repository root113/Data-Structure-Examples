#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
	struct n *prev;
};
typedef n node;

void print(node *r){
	while(r != NULL){
		printf("%d\n",r->data);
		r = r->next;
	}
}

node *insertSeq(node *r,int x){
	if(r== NULL){
		r = (node *)malloc(sizeof(node));
		r->data = x;
		r->next = NULL;
		r->prev = NULL;
		return r;
	}
	if(r->data > x){
		node *temp = (node *)malloc(sizeof(node));
		temp->next = r;
		r->prev = temp;
		temp->data = x;
		return temp;
	}
	node *iter = r;
	while(iter->next != NULL && iter->next->data < x){
		iter = iter->next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;
	if(temp->next != NULL){
		temp->next->prev = temp;
	}
	temp->data = x;
	return r;
}

node *deleteF(node *r,int y){
	node *temp;
	node *iter = r;
	if(r->data == y){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while(iter->next != NULL && iter->next->data != y){
		iter = iter->next;
	}
	if(iter->next == NULL){
		printf("Data doesn't exist!\n");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	if(iter->next != NULL){
		iter->next->prev = iter;
	}
	free(temp);
	return r;
}

int main() {
	node *root;
	root = NULL;
	
	root = insertSeq(root,16);
	root = insertSeq(root,25);
	root = insertSeq(root,8);
	root = insertSeq(root,23);
	root = insertSeq(root,3);
	
	print(root);
	
	root = deleteF(root,10);
	root = deleteF(root,23);
	
	print(root);
}
