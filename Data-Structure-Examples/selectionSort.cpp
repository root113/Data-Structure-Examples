#include <stdio.h>
#include <conio.h>

void selSort(int arr[]){
	int i,j,temp;
	
	for(i=0; i<=3; i++){
		for(j=i+1; j<=4;j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int arr[5] = {23,15,29,11,1};
	
	printf("-----SELECTION SORT-----\n");
	printf("\nArray before sorting:\n");
	
	for (int i=0; i<=4; i++)
		printf("%d\t",arr[i]);
	
	selSort(arr);
	
	printf("\nArray after sorting:\n");
	
	for(int i=0; i<=4; i++)
		printf("%d\t",arr[i]);
}
