#include <stdio.h>
#include <stdlib.h>

struct n {
	int x;
	n * next;
};

typedef n node;

int main () {
	//a pointer that will point to the first node
	node * root;
	  
	//create a node
	root = (node *)malloc(sizeof(node));
	root -> x = 10;
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 20;
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> x = 30;
	
	//iterator is for to point any node
	node * iter;
	iter = root;
	printf("%d",iter->x);
	iter = iter -> next;
	printf("\n%d",iter->x);
	
	
}
