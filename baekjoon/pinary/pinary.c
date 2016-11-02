#include <stdio.h>

#define MAX_SIZE 91

int main(){
	int N,i;
	long long arr[MAX_SIZE];

	scanf("%d",&N);
	
	arr[1]=1;
	arr[2]=1;
	
	for(i=3;i<=N;i++)
		arr[i]=arr[i-1]+arr[i-2];

	printf("%lld\n",arr[N]);
}
