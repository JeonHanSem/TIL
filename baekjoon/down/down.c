#include <stdio.h>

#define MAXSIZE 100001

int N;
int arr[MAXSIZE][MAXSIZE];
int max_maze[MAXSIZE][MAXSIZE];
int min_maze[MAXSIZE][MAXSIZE];

int max(int a,int b,int pos){
	int i;
	int _max=0;

	for(i=a;i<=b;i++)
		_max=_max>max_maze[pos][i]?_max:max_maze[pos][i];
	return _max;
}

int min(int a,int b,int pos){
	int i;
	int _min=2e9;

	for(i=a;i<=b;i++)
		_min=_min<min_maze[pos][i]?_min:min_maze[pos][i];
	return _min;
}

void down(){
	int i,j;
	int _max=0;
	int _min=2e9;

	for(i=1;i<=N;i++){
		max_maze[i][1]=max(1,2,i-1)+arr[i][1];
		min_maze[i][1]=min(1,2,i-1)+arr[i][1];

		for(j=2;j<N;j++)
			max_maze[i][j]=max(j-1,j+1,i-1)+arr[i][j];
			min_maze[i][j]=min(j-1,j+1,i-1)+arr[i][j];

		max_maze[i][N]=max(N-1,N,i-1)+arr[i][N];
		min_maze[i][N]=min(N-1,N,i-1)+arr[i][N];
	}
	for(i=1;i<=N;i++)
		_max=_max>max_maze[N][i]?_max:max_maze[N][i];
		_min=_min<min_maze[N][i]?_min:min_maze[N][i];
		
	printf("%d %d\n",_max,_min);
}

int main(){
	int i,j;
	scanf("%d",&N);

	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			scanf("%d",&arr[i][j]);

	down();
}
