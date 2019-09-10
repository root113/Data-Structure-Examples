#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 8

struct node{
	int data;
	struct node *next;
};

int visited[MAX];
void dfs(int,struct node**);
struct node *getNodeWrite(int);
void del(struct node*);

int main(){
	struct node *arr[MAX];
	struct node *v1,*v2,*v3,*v4;
	int i;
	
	v1 = getNodeWrite(2);
	arr[0] = v1;
	v1->next = v2 = getNodeWrite(3);
	v2->next = NULL;
	
	v1 = getNodeWrite(1);
	arr[1] = v1;
	v1->next = v2 = getNodeWrite(4);
	v2->next = v3 = getNodeWrite(5);
	v3->next = NULL;
	
	v1 = getNodeWrite(1);
	arr[2] = v1;
	v1->next = v2 = getNodeWrite(6);
	v2->next = v3 = getNodeWrite(7);
	v3->next = NULL;
	
	v1 = getNodeWrite(2);
	arr[3] = v1;
	v1->next = v2 = getNodeWrite(8);
	v2->next = NULL;
	
	v1 = getNodeWrite(2);
	arr[4] = v1;
	v1->next = v2 = getNodeWrite(8);
	v2->next = NULL;
	
	v1 = getNodeWrite(3);
	arr[5] = v1;
	v1->next = v2 = getNodeWrite(8);
	v2->next = NULL;
	
	v1 = getNodeWrite(3);
	arr[6] = v1;
	v1->next = v2 = getNodeWrite(8);
	v2->next = NULL;
	
	v1 = getNodeWrite(4);
	arr[7] = v1;
	v1->next = v2 = getNodeWrite(5);
	v2->next = v3 = getNodeWrite(6);
	v3->next = v4 = getNodeWrite(7);
	v4->next = NULL;
	
	dfs(1,arr);
	for(i=0; i<MAX; i++)
		del(arr[i]);
}

void dfs(int v,struct node **p){
	struct node *q;
	visited[v-1] = TRUE;
	printf("%d\t",v);
	
	q = *(p + v -1);
	
	while(q != NULL){
		if(visited[q->data-1] == FALSE)
			dfs(q->data,p);
		else
			q = q->next;
	}
}

struct node *getNodeWrite(int val){
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	
	return newNode;
}

void del(struct node *n){
	struct node *temp;
	while(n != NULL){
		temp = n->next;
		free(n);
		n = temp;
	}
}
