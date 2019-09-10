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
node * insertSeq(node *r,int x){
	if (r==NULL){
		r = (node *)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	else if (r->next == NULL){
		if(r->next > x){
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			temp->next = root;
			r = temp;
			return temp;
		}
		else {
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			temp->next = NULL;
			r->next = temp
			return r;
		}
	}
}

int main () {
	node * root;
	root = NULL;
	root = insertSeq(root,400);
	root = insertSeq(root,40);
	root = insertSeq(root,4);
	root = insertSeq(root,450);
	root = insertSeq(root,50);
	root = (node *)malloc(sizeof(node));
	root -> next = NULL;
	root -> x = 500;
	int i=0;
	
	print(root);
	node * iter;
	iter = root;
	
	for(i=0;i<3;i++){
		iter = iter->next;
		node * temp = (node *)malloc(sizeof(node));
		temp->next = iter->next;
		iter->next = temp;
		temp->x = 100;
		print(root);
	}
}
