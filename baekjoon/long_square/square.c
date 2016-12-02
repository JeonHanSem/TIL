#include <stdio.h>

#define MAXSIZE 1001

int main(){
	int N,i,j,max=0;
	int arr[MAXSIZE];
	int ans[MAXSIZE];

	scanf("%d",&N);
	
	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<N;i++){
		ans[i]=1;
		for(j=0;j<i;j++){
			if(arr[i]>arr[j] && ans[j]>=ans[i]){
				ans[i]=ans[j]+1;
			}
		}
	}
	
	for(i=0;i<N;i++)
		max=max>ans[i]?max:ans[i];
	printf("%d\n",max);
}
