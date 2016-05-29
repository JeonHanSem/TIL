#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int K;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void jose(int N,int pos,int *arr){
	int i;
	int size=N;

	while(pos<=N){
		arr[pos]=MAX;
		pos+=K;
		size-=1;
		if(size==2) break;
	}

	qsort(arr,N+1,sizeof(int),cmp);
	
	if(size==2){
		printf("%d %d\n", arr[1],arr[2]);
		return;
	} 

	jose(size,pos%N,arr);
}

int main(){
	int T,N,i;
	int arr[MAX];

	scanf("%d",&T);

	while(T--){
		scanf("%d %d",&N,&K);
		for(i=1;i<=N;i++)
			arr[i]=i;
		jose(N,1,arr);
	}
}