#include <stdio.h>

#define MAX_SIZE 2010

int pp[MAX_SIZE][MAX_SIZE];

int main(){
	int N,M;
	int i,j;
	int arr[MAX_SIZE];

	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		pp[i][i]=pp[i+1][i]=1;
	}

	for(i=1;i<=N;i++){
		for(j=1;j<=N-i;j++){
			if(arr[j]==arr[j+i] && pp[j+1][j+i-1]==1)
				pp[j][j+i]=1;
		}
	}

	scanf("%d",&M);
	while(M--){
		scanf("%d %d",&i,&j);
		printf("%d\n",pp[i][j]);
	}
}
