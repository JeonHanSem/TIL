#include<stdio.h>

#define MAX_SIZE 333

void scan(int *n, int *m){
	scanf("%d %d",&(*n),&(*m));
}

void calc(int n,int m){
	int i,j;
	int arr[MAX_SIZE][MAX_SIZE]={0};

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(j==1) arr[i][j]=arr[i][j-1]+i-1;
			else arr[i][j]=arr[i][j-1]+i;
		}
	}
	printf("%d\n", arr[n][m]);
}

int main(){
	int n,m;

	scan(&n,&m);
	calc(n,m);
}
