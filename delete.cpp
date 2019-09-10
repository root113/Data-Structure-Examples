#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
};
typedef n node;

node *insertSeq(node *r,int x){
	
	//if linked list is empty create one
	if(r == NULL){
		r = (node *)malloc(sizeof(node));
		r->data = x;
		r->next = NULL;
		return r;
	}
	
	//if 1 node alraedy exists, change root
	if(r->data > x){
		node *temp = (node *)malloc(sizeof(node));
		temp->next = r;
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
	temp->data = x;
	
	return r;
}

void print(node *r){
	while(r != NULL){
		printf("%d\n",r->data);
		r = r->next;
	}
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
	while(iter->next != NULL && iter->next->data != y) {
		iter = iter->next;
	}
	if(iter->next == NULL){
		printf("Data doesn't exist!\n");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main() {
	node *root;
	root = NULL;
	
	root = insertSeq(root,16);
	root = insertSeq(root,25);
	root = insertSeq(root,3);
	root = insertSeq(root,8);
	root = insertSeq(root,23);
	
	print(root);
	
	root = deleteF(root,10);
	root = deleteF(root,23);
	
	print(root);
}
