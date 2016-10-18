#include<stdio.h>
#include<stdlib.h>

#define MAX 1000+1

int cmp(void const *a,void const *b){return *(int*)a-*(int*)b;}

int main(){
	int n,i;
	int big,small;
	int arr[MAX];

	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	for(i=0;i<n;i++){
		if((n-i)>=arr[i] && (i+1)>=(n-arr[i])){
			printf("%d\n",arr[i]);
			break;
		}
	}
	return 0;
}
