#include <stdio.h>

#define MAXSIZE 100002

int ans[MAXSIZE][3];

int MAX(int pos){
	int max;	
	if(ans[pos][0]>ans[pos][1]){
		if(ans[pos][0]>ans[pos][2])
			max=ans[pos][0];
		else
			max=ans[pos][2];
	}
	else{
		if(ans[pos][1]>ans[pos][2])
			max=ans[pos][1];
		else
			max=ans[pos][2];
	}
	return max;
}

int main(){
	int arr[MAXSIZE*2+1];
	int i,j,T,n;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<2*n;i++)
			scanf("%d",&arr[i]);

		ans[0][0]=0;
		ans[0][1]=arr[0];
		ans[0][2]=arr[n];
		for(i=1;i<=n;i++){
			ans[i][0]=MAX(i-1);
			ans[i][1]=((ans[i-1][0]>ans[i-1][2])?ans[i-1][0]:ans[i-1][2]) + arr[i];
			ans[i][2]=((ans[i-1][0]>ans[i-1][1])?ans[i-1][0]:ans[i-1][1]) + arr[i+n];
		}
		printf("%d\n",ans[n][0]);
	}
}
