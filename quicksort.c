#include <stdio.h>
#include <stdlib.h>

void swap(int* arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int* arr,int start, int end){
	int pivot = start;
	int i = start;
	int j = end;
	while(i<j){
		while(arr[i]<=arr[pivot] && i<=high-1){
			i++;
		}
		while(arr[j]>arr[pivot] && j>=low+1){
			j--;
		}
		if(i<j){
			swap(arr,i,j);
		}

	}
	swap(arr,pivot,j)
	return j;
}
void quicksort(int* arr,int start, int end){
	if(start<high){
		int p =  partition(arr,start,end);
		quicksort(arr,start,p);
		quicksort(arr,p+1,end);
	}
}
int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	int* arr = malloc(sizeof(int)*size);
	printf("Enter the values of the array: ");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	} 
	quicksort(arr,0,size-1);
	for(int i =0;i<size;i++){
		printf("%d",arr[i]);
	}
}
