#include <stdio.h>

#define MAXSIZE 100
#define VAL 1000000000

int arr[MAXSIZE][10];

void init(){
	int i;
	arr[1][0]=0;
	for(i=1;i<10;i++)
		arr[1][i]=1;
}

int main(){
	int n,i,j;
	int sum=0;

	scanf("%d",&n);

	init();
	for(i=2;i<=n;i++){
		arr[i][0]=arr[i-1][1];
		for(j=1;j<9;j++){
			arr[i][j]=(arr[i-1][j-1]+arr[i-1][j+1])%VAL;
		}
		arr[i][9]=arr[i-1][8];
	}

	for(i=0;i<10;i++){
		sum+=arr[n][i];
		sum%=VAL;
	}
	printf("%d\n",sum);
}
