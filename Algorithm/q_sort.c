#include <stdio.h>

int arr[]={5,12,42,56,1,3,2,77,98,14,34};

void swap(int a,int b){
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
int partition(int left,int right){
	int pivot=arr[left];
	int low=left+1;
	int high=right;
	int temp;

	while(low<=high){
		if(pivot>=arr[low] && low<=right)	low++;
		if(pivot<=arr[high] && high>=left+1) high--;
		if(low<=high){
			swap(low,high);
		}
	}
	swap(left,high);
	return high;
}

void quick(int left,int right){
	int p;

	if(left<=right){
		p=partition(left,right);
		quick(left,p-1);
		quick(p+1,right);
	}
}

int main(){
	int i,len=sizeof(arr)/sizeof(int);

	quick(0,len-1);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	puts("");
}
