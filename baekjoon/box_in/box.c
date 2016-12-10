#include<stdio.h>

#define MAXSIZE 1001

int main(){
	int n,i,j,max=0;
	int arr[MAXSIZE];
	int dis[MAXSIZE];

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		dis[i]=1;
		for(j=0;j<i;j++){
			if(arr[i]>arr[j] && dis[j]>=dis[i])
				dis[i]=dis[j]+1;
		}
	}
	for(i=0;i<n;i++)
		max=max>dis[i]?max:dis[i];
	printf("%d\n",max);
}
