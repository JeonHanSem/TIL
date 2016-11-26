#include <stdio.h>

int mark[5];
int graph[5][5]={
{0,0,1,0,0},
{0,0,1,0,1},
{1,1,0,1,0},
{0,0,1,0,0},
{0,1,0,0,0}
};
int cnt=0;

void dfs(int pos){
	int i;
	mark[pos]=1;
	if(cnt==4){
		printf("%d\n",pos);
		return;
	}
	printf("%d -> ",pos);
	cnt++;
	for(i=0;i<5;i++){
		if(graph[pos][i]==1 && mark[i]==0){
			dfs(i);
		}
	}
}

int main(){
	int i,j;

	mark[0]=1;
	printf("0 -> ");
	cnt++;
	for(i=0;i<5;i++){
		if(graph[0][i]==1){
			dfs(i);
		}
	}
}
