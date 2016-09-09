#include <stdio.h>

#define MAX 1001

int T;
int arr[MAX][MAX];
int min=MAX*MAX;

void RGB(int pos,int sum,int mark){
	int i,j;

	if(pos==T){
		min = min<sum?min:sum;
		return; 
	}

	for(i=0;i<T;i++){
		if(mark==i) continue;
		RGB(pos+1,sum+arr[pos][i],i);
	}
	return;
}	

int main(){
	int i,j;

	scanf("%d",&T);
	for(i=0;i<T;i++){
		for(j=0;j<T;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	RGB(0,0,T);	
	printf("%d\n",min);
}
