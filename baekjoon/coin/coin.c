#include <stdio.h>

#define MAXSIZE 21
#define MAXVALUE 10001

int exchange(int N,int M,int *arr){
	int coin[MAXVALUE]={0};
	int i,j;
	int val;

	for(i=0;i<N;i++){
		val=arr[i];
		coin[val]+=1;
		for(j=1;j+val<=M;j++){
			coin[val+j]+=coin[j];
		}
	}
	return coin[M];
}

int main(){
	int T,N,M,i;
	int arr[MAXSIZE];

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&M);

		printf("%d\n",exchange(N,M,arr));
	}
}
