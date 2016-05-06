#include <stdio.h>

#define MAX 8
#define INF 1415*8+1
#define MIN(A,B) A<B?A:B

int n;
int mark[MAX];
double map[MAX][MAX];
double min;

void TSP(int rec, double sum,int cnt){
	int i;

	if(mark[rec])	return;
	mark[rec]=1;

	if(cnt==n){
		min=MIN(min,sum);
		mark[rec]=0;
		return;
	}
	
	for(i=0;i<n;i++){
		if(map[rec][i]==0) continue;
		TSP(i,sum+map[rec][i],cnt+1);
	}
	mark[rec]=0;
}

int main(){
	int t;
	int i,j;

	scanf("%d", &t);

	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%lf",&map[i][j]);
			}
		}
		min=INF;
		for(i=0;i<n;i++){
			TSP(i,0,1);
		}
		printf("%lf\n", min);
	}
}