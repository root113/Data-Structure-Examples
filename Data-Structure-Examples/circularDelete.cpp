#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
};
typedef n node;

node *insertSeq(node *r,int x){
	if(r == NULL){
		r = (node*)malloc(sizeof(node));
		r->data = x;
		r->next = r;
		return r;
	}
	if(r->data > x){
		node *temp = (node *)malloc(sizeof(node));
		temp->next = r;
		temp->data = x;
		node *iter = r;
		while(iter->next != r){
			iter = iter->next;
		}
		iter->next = temp;
		return temp;
	}
	node *iter = r;
	while(iter->next != r && iter->next->data < x){
		iter = iter->next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = x;
	return r;
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

node *deleteF(node *r,int y){
	node *temp;
	node *iter = r;
	if(r->data == y){
		while(iter->next != r){
			iter = iter->next;
		}
		iter->next = r->next;
		free(r);
		return iter->next;
	}
	while(iter->next != r && iter->next->data != y){
		iter = iter->next;
	}
	if(iter->next == r){
		printf("Data doesn't exist!\n");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main () {
	node *root;
	root = NULL;
	
	root = insertSeq(root,16);
	root = insertSeq(root,25);
	root = insertSeq(root,3);
	root = insertSeq(root,23);
	root = insertSeq(root,8);
	
	print(root);
	
	root = deleteF(root,10);
	root = deleteF(root,23);
	
	print(root);
}
