#include <stdio.h>

#define maxSize 100000+1
#define MAXIMUM(A,B) A>B?A:B

int maxSum(int *num,int N){
	int i,j;
	int max=0;
	int sum=0;

	for(i=0;i<N;i++){
		sum+=num[i];
		max=MAXIMUM(max,sum);
		if(sum<0){
			sum=0;
		}
	}
	return max;
}

int main(){
	int T,N,i;
	int num[maxSize];

	scanf("%d",&T);

	while(T--){
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d",&num[i]);
		}
		printf("%d\n",maxSum(num,N));
	}
}