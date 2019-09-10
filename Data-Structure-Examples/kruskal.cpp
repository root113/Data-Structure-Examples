#include <stdio.h>
#define MAX 30

typedef struct edge{
	int u,v,w;
}edge;

typedef struct edgeList{
	edge data[MAX];
	int n;
}edgeList;

edgeList eList;

int G[MAX][MAX],n;
edgeList spanList;

void kruskal();
int find(int belongs[],int vertexNo);
void union1(int belongs[],int c1,int c2);
void sort();
void print();

int main(){
	int n,i,j,totalCost;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	printf("\nEnter the adjustnacy matrix");
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",&G[i][j]);
	kruskal();
	print();
}

void kruskal(){
	int belongs[MAX],i,j,cno1,cno2;
	eList.n = 0;
	
	for(i=0; i<n; i++)
		for(j=0; j<i; j++){
			if(G[i][j] != 0){
				eList.data[eList.n].u = i;
				eList.data[eList.n].v = j;
				eList.data[eList.n].w = G[i][j];
				eList.n++;
			}
		}
	sort();
		
	for(i=0; i<n; i++)
		belongs[i] = i;
			
	spanList.n = 0;
		
	for(i=0; i<eList.n; i++){
		cno1 = find(belongs,eList.data[i].u);
		cno2 = find(belongs,eList.data[i].v);
			
		if(cno1 != cno2){
			spanList.data[spanList.n] = eList.data[i];
			spanList.n = spanList.n + 1;
			union1(belongs,cno1,cno2);
		}
	}
}

int find(int belongs[],int vertexNo){
	return (belongs[vertexNo]);
}

void union1(int belongs[],int c1,int c2){
	int i;
	
	for(i=0; i<n; i++)
		if(belongs[i] == c2)
			belongs[i] = c1;
}

void sort(){
	int i,j;
	edge temp;
	
	for(i=1; i<eList.n; i++)
		for(j=0; j<eList.n-1; j++)
			if(eList.data[j].w > eList.data[j+1].w){
				temp = eList.data[j];
				eList.data[j] = eList.data[j+1];
				eList.data[j+1] = temp;
			}
}

void print(){
	int i,cost=0;
	
	for(i=0; i<spanList.n; i++){
		printf("\n%d\t%d\t%d",spanList.data[i].u,spanList.data[i].v,spanList.data[i].w);
		cost = cost + spanList.data[i].w;
	}
	printf("\n\nThe cost of Minimum Spanning Tree = %d",cost);
}
