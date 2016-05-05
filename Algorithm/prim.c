#include <stdio.h>

#define maxSize 5
#define INF 9999

typedef struct{int start,end;}Point;
Point path[maxSize];

int W[maxSize][maxSize]={
	{0,1,3,INF,INF},
	{1,0,3,6,INF},
	{3,3,0,4,2},
	{INF,6,4,0,5},
	{INF,INF,2,5,0}};
int sum=0;
int k=0;

void prim(int n){
	int i,j,vnear;
	int min;
	int nearest[n];
	int distance[n];

	//initialize
	for(i=0;i<n;i++){
		nearest[i] = 0;
		distance[i] = W[0][i];
	}

	for(i=1;i<n;i++){
		min=INF;
		for(j=0;j<n;j++){
			if(distance[j] < min && distance[j] >0){
				min=distance[j];
				vnear=j;
			}
		}
		//record
		path[k].start=nearest[vnear];
		path[k++].end=vnear;
		sum+=distance[vnear];
		//check
		distance[vnear]=-1;

		for(j=0;j<n;j++){
			if(W[j][vnear] < distance[j]){
				distance[j] = W[j][vnear];
				nearest[j] = vnear;
			}
		}
	}
}

int main(){
	int i;

	prim(maxSize);

	printf("sum of distance : %d\n",sum);

	for(i=0;i<k-1;i++){
		printf("(%d %d), ", path[i].start,path[i].end);
	}
	printf("(%d %d)\n", path[k-1].start,path[k-1].end);
}