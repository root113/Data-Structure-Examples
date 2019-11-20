#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n * next;
} node;

node * root = NULL;
node * last = NULL;

void enqueue(int x){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
		last = root;
	}
	else{
		last->next = (node*)malloc(sizeof(node));
		last->next->data = x;
		last = last->next;
		last->next = NULL;
	}
}

int dequeue(){
	if(root == NULL){
		printf("Linked list is empty!\n");
		return -1;
	}
	int rvalue = root->data;
	node * temp = root;
	root = root->next;
	free(temp);
	return rvalue;
}

int main(){
	for (int i=1; i<=10; i++)
		enqueue(i*10);
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
}
