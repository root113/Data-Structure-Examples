#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n * next;
};
typedef n node;

int main () {
	node * root;
	root = (node *)malloc(sizeof(node));
	root -> x = 1;
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 2;
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> x = 3;
	root -> next -> next = NULL;
	node * iter;
	iter = root;
	
	//when out of loop iter points to the last node instead of NULL
	while (iter -> next != NULL) {
		printf("%d\n",iter -> x);
		iter = iter -> next;
	}
	int i;
	for (i=1;i<=5;i++) {
		iter -> next = (node *)malloc(sizeof(node));
		iter = iter -> next;
		iter -> x = i*10;
		iter -> next = NULL;
	} 
}
