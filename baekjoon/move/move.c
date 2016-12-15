#include <stdio.h>

#define MAXSIZE 1001

int N,M;
int arr[MAXSIZE][MAXSIZE]={0};

int max(int a,int b,int c){
	if(a>=b && a>=c) return a;
	if(b>=a && b>=c) return b;
	if(c>=a && c>=b) return c;
	return 0;
}

int move(){
	int i,j;
	int maze[MAXSIZE][MAXSIZE]={0};

	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			maze[i][j]=max(maze[i-1][j],maze[i][j-1],maze[i-1][j-1])+arr[i][j];
		}
	}
/* test
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			printf("%2d ",maze[i][j]);
		}
		puts("");
	}
*/
	return maze[N][M];
}

int main(){
	int i,j;
	
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			scanf("%d",&arr[i][j]);

	printf("%d\n",move());
}

	
