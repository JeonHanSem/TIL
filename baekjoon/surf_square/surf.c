#include <stdio.h>

#define MAXSIZE 101

int main(){
	int T,N,i;
	long long arr[MAXSIZE]={0,1,1};

	for(i=3;i<MAXSIZE;i++)
		arr[i]=arr[i-3]+arr[i-2];
	scanf("%d",&T);

	while(T--){
		scanf("%d",&N);
		printf("%lld\n",arr[N]);
	}
}
