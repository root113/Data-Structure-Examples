#include <stdio.h>
#include <stdlib.h>

int *array = NULL;
int line = 0;
int fLine = 0;
int size = 2;

int dequeue(){
	if(line == fLine){
		printf("Array is empty!\n");
		return -1;
	}
	if(size-fLine <= size/4){
		int * array2 = (int*)malloc(sizeof(int)/2);
		for(int i=0; i<line-fLine; i++)
			array2[i] = array[line+i];
		line -= fLine;
		fLine = 0;
		free(array);
		size /= 2;
		array = array2;

	}
	return array[fLine++];
}

void clear(){
	if(fLine == 0)
		return ;
	for(int i=0; i<size; i++)
		array[i] = array[i+fLine];
	line -= fLine;
	fLine = 0;
}

void enqueue(int a){
	if(array == NULL)
		array = (int*)malloc(sizeof(int)*2);
	if(line >= size){
		size *= 2;
		int *array2 = (int*)malloc(sizeof(int)*size);
		for(int i=0; i<size/2; i++)
			array2[i] = array[i];
		free(array);
		array = array2;
	}
	array[line++] = a;
}

int main(){
	for(int i=0; i<20; i++)
		enqueue(i*10);
	for(int i=0; i<10; i++)
		printf("%d ",dequeue());
	clear();
	puts("");
}
