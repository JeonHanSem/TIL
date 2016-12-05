#include <stdio.h>

#define MAXSIZE 1001
#define VAL 10007

int arr[MAXSIZE][MAXSIZE];

void init(){
	int i;
	for(i=0;i<10;i++)
		arr[1][i]=1;
}

void print_ans(int n){
	int i,sum=0;
	for(i=0;i<10;i++){
		sum+=arr[n][i];
		sum%=VAL;
	}
	printf("%d\n",sum);
}

int main(){
	int N;
	int i,j,k;
	int sum;

	scanf("%d",&N);

	init();
	for(i=2;i<=N;i++){
		for(j=0;j<10;j++){
			sum=0;
			for(k=0;k<=j;k++){
				sum+=arr[i-1][k];
				sum%=VAL;
			}
			arr[i][j]=sum;
		}
	}
	print_ans(N);
}
