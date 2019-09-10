#include <stdio.h>

void inserSort(int arr[],int n){
	int i,j,temp;
	
	for(i=0; i<n; i++){
		j = i;
		for(j=1; j<=n-1; j++){
			while(j > 0 && arr[j-1] > arr[j]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				j--;
			}
		}
	}
}

int main(){
	int n,arr[1000],i,j,temp;
	
	printf("-----INSERTION SORT-----\n");
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter %d integers: ",n);
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
		
	inserSort(arr,n);
	
	printf("\nSorted list in ascending order:\n");
	for(i=0; i<=n-1; i++)
		printf("%d\n",arr[i]);
	
	return 0;
}
