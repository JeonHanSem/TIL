#include <stdio.h>

#define MAXSIZE 30

// nCr = n-1Cr-1 + n-1Cr

int arr[MAXSIZE][MAXSIZE];

void combination(){
	int i,j;

	arr[0][1]=1;
	for(i=1;i<MAXSIZE;i++){
		for(j=0;j<=i;j++){
			if(j==0) arr[i][j]=1;
			else arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}	
}

int main(){
	int T,N,M;

	scanf("%d",&T);
	combination();
	while(T--){
		scanf("%d %d",&N,&M);
		printf("%d\n",arr[M][N]);
	}
}
