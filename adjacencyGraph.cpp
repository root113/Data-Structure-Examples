#include <stdio.h>
#include <stdlib.h>

int main(){
	int **adjMatrix;
	char d;
	int r,c,nodes;

	printf("Adjacency Matrix Demo\n");
	printf("Number of nodes: ");
	scanf("%d",&nodes);

	//Dynamic allocation of matrix array
	adjMatrix = (int**)malloc(sizeof(int**)*nodes);
	
	if(!adjMatrix){
		printf("\nFatal error in memory allocation!");
		return -1;
	}

	for(r=0; r<nodes; r++){
		adjMatrix[r] = (int*)malloc(sizeof(int)*nodes);

		if(!adjMatrix[r]){
			printf("\nFatal error in memory allocation!");
			return -1;
		}
	}

	for(r=0; r<nodes; r++){
		for(c=0; c<nodes; c++){
			adjMatrix[r][c] = 0;
		}
	}

	r = 0;
	c = 0;

	printf("\nNode pair format <U/D> <V1> <V2>\n");

	do{
		printf("Enter node pair: ");
		fflush(stdin);
		scanf("%c %d %d",&d,&r,&c);

		if(r > 0 && r <= nodes && c > 0 && c <= nodes){
			adjMatrix[r-1][c-1] = 1;

			if(d == 'U' || d == 'u'){
				printf("\nUndirected connection between %d to %d\n",r,c);
			}
			else{
				printf("\nDirected connection between %d to %d\n",r,c);
			}
		}
	}while(r > 0 && c > 0);
		
	printf("Adjacency matrix\n");
	printf(" ");

	for(c=0; c<nodes; c++){
		printf("%.1d ",c+1);
	}
	
	printf("\n");
	
	for(c=0; c<nodes; c++){
		printf("---");
	}
	
	printf("\n");
	
	for(r=0; r<nodes; r++){
		printf("%.1d| ",r+1);
		
		for(c=0; c<nodes; c++){
			printf("%.1d ",adjMatrix[r][c]);
		}
		printf("\n");
	}
	
	return 0;
}
