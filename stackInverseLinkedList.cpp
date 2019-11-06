#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	n * next;
	int data;
} node;

void print(node * r){
	while(r != NULL){
		printf("%d -> \n",r->data);
		r = r->next;
	}
}

void pop(node * r){
	if(r == NULL){
		printf("Stack is empty!\n");
	}
	if(r->next == NULL)
		free(r);
	node * iter = r;
	while(iter->next->next != NULL)
		iter = iter->next;
	node * temp = iter->next;
	iter->next = NULL;
	free(temp);
}

node * push(node * r, int a){
	if(r==NULL){
		r = (node*)malloc(sizeof(node));
		r->data = a;
		r->next = NULL;
		return r;
	}
	node * iter = r;
	while(iter->next != NULL)
		iter = iter->next;
	node * temp = (node*)malloc(sizeof(node));
	temp->data = a;
	temp->next = NULL;
	iter->next = temp;
	return r;
}

int main(){
	node * root = NULL;
	root = push(root,10);
	root = push(root,20);
	root = push(root,30);
	pop(root);
	pop(root);
	pop(root);
	print(root);
}
