#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int value;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void str(int n,int *num){
	int i;
	if(n==1){
		printf("%d\n", value);
		return;
	}

	qsort(num,n,sizeof(int),cmp);
	num[0]+=num[1];
	num[1]=num[n-1];
	value+=num[0];
	str(n-1,num);
}

int main(){
	int T,n;
	int i;
	int num[MAX];

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		value=0;
		str(n,num);
	}
}