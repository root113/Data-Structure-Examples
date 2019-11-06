#include <stdio.h>
#include <stdlib.h>

//int *array;
//int size = 2;
//int top = 0;

typedef struct s{
	int top;
	int size;
	int * array;
} stack;

stack * init(){
	stack * s = (stack*)malloc(sizeof(stack));
	s->array = NULL;
	s->size = 2;
	s->top = 0;
	return s;
}

int pop(stack *s){
	if(s->top <= 0 || s->array==NULL){
		printf("Array is empty\n");
		return -1;
	}
	if(s->top <= s->size/2){
		int *array2 = (int*)malloc(sizeof(int)*s->size/2);
		for(int i=0; i<s->size; i++)
			array2[i] = s->array[i];
		free(s->array);
		s->array = array2;
		s->size /= 2;
	}
	return s->array[--s->top];
}

void push(int a,stack *s){
	if(s->array==NULL)
		s->array = (int*)malloc(sizeof(int)*2);
	
	if(s->top >= s->size-1){
		int *array2 = (int*)malloc(sizeof(int)*s->size*2);
		for(int i=0; i<s->size; i++)
			array2[i] = s->array[i];
		free(s->array);
		s->array = array2;
		s->size *= 2;
	}
	s->array[s->top++] = a;
}

void print(stack *s){
	printf("Size: %d\n",s->size);
	for(int i=0; i<s->top; i++)
		printf("%d\n",s->array[i]);
}

int main(){
	stack *s1 = init();
	stack *s2 = init();

	for(int i=0; i<10; i++)
		push(i*10,s1);
	print(s1);
	for(int i=0; i<10; i++)
		push(pop(s1),s2);
	print(s1);
	print(s2);
}
