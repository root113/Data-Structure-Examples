#include <stdio.h>
#include <stdlib.h>

int *array;
int size = 2;
int top = 0;

int pop(){
	if(top<=size/4){
		int *array2 = (int*)malloc(sizeof(int)*size/2);
		for(int i=0; i<size; i++){
			array2[i] = array[i];
		}
		free(array);
		array = array2;
		size /= 2;
	}
	return array[--top];
}

void push(int a){
	if(top>=size){
		int *array2 = (int*)malloc(sizeof(int)*size*2);
		for(int i=0; i<size; i++){
			array2[i] = array[i];
		}
		free(array);
		array = array2;
		size *= 2;
	}
	array[top++] = a;
}

void print(){
	printf("\nSize: %d",size);
	for(int i=0; i<top; i++){
		printf("\n%d",array[i]);
	}
}

int main() {
	array = (int*)malloc(sizeof(int)*2);
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	print();
	printf("\nPopped: %d",pop());
	printf("\nPopped: %d",pop());
	printf("\nPopped: %d",pop());
	printf("\nPopped: %d",pop());
	printf("\nPopped: %d",pop());
	print();
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	print();
}
