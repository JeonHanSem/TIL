#include <stdio.h>

int arr[]={2,51,35,66,57,88,94,5,6,23,64};

void merge(int left,int mid,int right){
	int i,j,pos;
	int brr[sizeof(arr)/sizeof(int)];
	i=left;
	j=mid+1;
	pos=left;

	while(i<=mid && j<=right){
		if(arr[i]<arr[j])
			brr[pos++]=arr[i++];
		else
			brr[pos++]=arr[j++];
	}
	for(;i<=mid;i++)
		brr[pos++]=arr[i];
	for(;j<=right;j++)
		brr[pos++]=arr[j];
	for(i=left;i<=right;i++)
		arr[i]=brr[i];
}

void merge_sort(int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left,mid,right);
	}
}

int main(){
	int i,len=sizeof(arr)/sizeof(int);
	merge_sort(0,len-1);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
}
