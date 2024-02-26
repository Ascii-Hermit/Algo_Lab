#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start,int mid,int end){
	int left_size = mid-start+1;
	int right_size = end-mid;
	int left_arr[left_size];
	int right_arr[right_size];

	for(int i = 0;i<left_size;i++){
		left_arr[i] = arr[start + i];
	}
	for(int i = 0;i<right_size;i++){
		right_arr[i] = arr[mid+1+i];
	}
	int i = 0;
	int j = 0;
	int k = start;
	while(i<left_size && j<right_size){
		if(left_arr[i]<=right_arr[j]){
			arr[k] = left_arr[i];
			i++;
			k++;
		}
		else{
			arr[k] = right_arr[j];
			j++;
			k++;
		}
	} 
	while(i<left_size){
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	while(j<right_size){
		arr[k] = right_arr[j];
		j++;
		k++;
	}



}

void mergesort(int* arr,int start,int end){
	if(start<end){
		int mid = (start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
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
	mergesort(arr,0,size-1);
	for(int i =0;i<size;i++){
		printf("%d",arr[i]);
	}
}