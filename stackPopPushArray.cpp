#include <stdio.h>
#define ARR 10

struct stack{
	int a[ARR];
	int top;
};

/*Prototypes*/
void initStack(struct stack*);
void push(struct stack*, int item);
int pop(struct stack*);

int main(){
	struct stack s;
	int i;
	
	initStack(&s);
	
	push(&s,8);
	push(&s,20);
	push(&s,-4);
	push(&s,15);
	push(&s,18);
	push(&s,12);
	push(&s,16);
	push(&s,25);
	push(&s,0);
	push(&s,10);
	push(&s,5);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	
	i = pop(&s);
	printf("\nItem popped: %d",i);
	puts("");
}

/*Initializes the stack*/
void initStack(struct stack *s){
	s->top = -1;
}

/*Adds an element to the stack*/
void push(struct stack *s, int item){
	if(s->top == ARR - 1){
		printf("\nStack is full!");
		return;
	}
	s->top++;
	s->a[s->top] = item;
}

/*Removes an element from the stack*/
int pop(struct stack *s){
	int data;
	if(s->top == -1){
		printf("\nStack is empty!");
		return -1;
	}
	data = s->a[s->top];
	s->top--;
	return data;
}
