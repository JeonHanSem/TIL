#include <stdio.h>

#define MAXSIZE 10001

int ans[MAXSIZE][3];

int return_max(int pos,int gap){
	int i;
	int max=0;
	for(i=0;i<=gap;i++)
		max=max>ans[pos][i]?max:ans[pos][i];
	return max;
}

int calc(int *arr,int n){
	int i;

	ans[0][1]=arr[0];
	for(i=1;i<=n;i++){
		ans[i][0]=return_max(i-1,2);
		ans[i][1]=ans[i-1][0]+arr[i];
		ans[i][2]=return_max(i-1,1) + arr[i];
	}
	return ans[n][0];
}

int main(){
	int n,i;
	int arr[MAXSIZE];

	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",calc(arr,n));
}
