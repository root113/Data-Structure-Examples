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
		iter = iter->next;L){
		printf("%d\n",r->data);
		r = r->next;
	}
}

int main() {
	node *root;
	root = NULL;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = x;
	
	return r;
}

void print(node *r){
	while(r != NUL
	
	root = insertSeq(root,16);
	root = insertSeq(root,25);
	root = insertSeq(root,3);
	root = insertSeq(root,8);
	root = insertSeq(root,23);
	
	print(root);
}
