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

void bfs(){
	int i,v;
	int queue[5];
	int front=0,rear=0;

	queue[rear++]=0;
	mark[0]=1;

	while(front<rear){
		v=queue[front++];
		for(i=0;i<5;i++){
			if(graph[v][i] == 1 && mark[i]==0){
				queue[rear++]=i;
				mark[i]=1;
				printf("%d -> %d\n",v,i);
			}
		}
	}
}

int main(){
	bfs();
}
