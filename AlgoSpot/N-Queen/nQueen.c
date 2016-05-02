#include <stdio.h>
#include <stdlib.h>

#define MAX 13

int size;
int col[MAX];
int cnt;

int isPromising(int row){
	int k=0;

	while(k<row){
		if(col[k]==col[row] || abs(col[row]-col[k]) == row-k)
			return 0;
		k++;
	}
	return 1;
}

void nQueen(int row){
	int i;

	if(isPromising(row)){
		if(row==size-1)	cnt++;
		else{
			for(i=0;i<size;i++){
				col[row+1]=i;
				nQueen(row+1);
			}
		}
	}
}

int main(){
	int n;
	int i;

	scanf("%d",&n);

	while(n--){
		scanf("%d",&size);
		cnt=0;
		for(i=0;i<size;i++){
			col[0]=i;
			nQueen(0);
		}
		printf("%d\n", cnt);
	}
}