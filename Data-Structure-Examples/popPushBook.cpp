/*Program implements linked list as a stack*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*Structure containing data part and link part*/
struct node{
	int data;
	struct node *link;
};

/*Prototypes*/
void push(struct node **, int);
int pop(struct node **);
void delStack(struct node **);

int main() {
	struct node *s = NULL;
	int i;
	
	push(&s,10);
	push(&s,19);
	push(&s,1);
	push(&s,20);
	push(&s,32);
	push(&s,15);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	delStack(&s);
	
	getch();
}

/*Adds a new node to the stack as linked list*/
void push(struct node **top, int item){
	struct node *temp;
	temp = (node *)malloc(sizeof(node));
	
	if(temp == NULL){
		printf("\nStack is full!");
	}
	temp->data = item;
	temp->link = *top;
	*top = temp;
}

/*Pops an element from the stack*/
int pop(struct node **top){
	struct node *temp;
	int item;
	
	if(*top == NULL){
		printf("\nStack is empty!");
		return NULL;
	}
	else{
		temp = *top;
		item = temp->data;
		*top = (*top)->link;
		
		free(temp);
		return item;
	}
}

/*Deallocates memory*/
void delStack(struct node **top){
	struct node *temp;
	if(*top == NULL){
		return;
	}
	while(*top != NULL){
		temp = *top;
		*top = (*top)->link;
		free(temp);
	}
}
