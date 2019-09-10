#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n *next;
};
typedef n node;

int pop(node *root){
	if(root == NULL){
		printf("Stack is empty.\n");
		return -1;
	}
	node *iter = root;
	while(iter->next->next != NULL){
		iter = iter->next;
	}
	node *temp = iter->next;
	int rvalue = temp->data;
	free(temp);
	iter->next = NULL;
	return rvalue;
}

node *push(node *root,int a){
	if(root == NULL){
		root = (node *)malloc(sizeof(node));
		root->data = a;
		root->next = NULL;
		return root;
	}
	node *iter = root;
	while(iter->next != NULL){
		iter = iter->next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->data = a;
	temp->next = NULL;
	iter->next = temp;
	return root;
}

int main() {
	node *s = NULL;
	s = push(s,10);
	s = push(s,20);
	
	perror("Passed\n");
	printf("%d -> ",pop(s));
}
