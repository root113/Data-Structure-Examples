#include <stdio.h>
#include <conio.h>

void bubbleSort(int arr[]){
	int i,j,temp;
	for(i=0; i<=3; i++){
		for(j=0; j<=3; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int arr[5] = {23,15,29,11,1};
	
	printf("-----BUBBLESORT-----\n");
	printf("\nArray before sorting:\n");
	for(int i=0; i<=4; i++)
		printf("%d\t",arr[i]);
	
	bubbleSort(arr);
	
	printf("\nArray after sorting:\n");
	for(int i=0; i<=4; i++)
		printf("%d\t",arr[i]);
}
