#include <stdio.h>

#define MAX_SIZE 10001

int main(){
	int M,N,i;
	int min=MAX_SIZE;
	int sum=0;
	
	scanf("%d %d",&M,&N);

	for(i=1;i*i<=N;i++){
		if(i*i >= M){
			sum+=i*i;
			min=min>i*i?i*i:min;
		}
	}
	if(sum==0)	printf("-1\n");
	else printf("%d\n%d\n",sum,min);
}
