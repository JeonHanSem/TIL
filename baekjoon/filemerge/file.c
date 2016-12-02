#include <stdio.h>

#define MAXSIZE 501
#define _MAX 2e9

int k;
int arr[MAXSIZE];
int ans[MAXSIZE][MAXSIZE];
int sum[MAXSIZE][MAXSIZE];

void make_sum(){
	int i,j;

	for(i=0;i<k;i++)
		sum[i][i]=arr[i];

	for(i=1;i<k;i++){		//거리
		for(j=0;j<k-i;j++){	//시작점
			sum[j][j+i]=sum[j][j+i-1] + sum[j+i][j+i];
		}
	}
}

int MIN(int a,int b){return a>b?b:a;}

void calc_file(){
	int i,j,l;
	int min;

	for(i=0;i<k;i++)
		ans[i][i]=0;

	for(i=1;i<k;i++){		//거리
		for(j=0;j<k-i;j++){	//시작점
			min=_MAX;
			for(l=j;l<j+i;l++){
				min=MIN(min,ans[j][l]+ans[l+1][j+i]);
			}
			ans[j][j+i]=min+sum[j][j+i];
		}
	}	

/*
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("%3d ",ans[i][j]);
		}
		puts("");
	}
*/
	printf("%d\n",ans[0][k-1]);
}

int main(){
	int T,i,j;

	scanf("%d",&T);

	while(T--){
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&arr[i]);
		}
		make_sum();	
		calc_file();
	}
}
