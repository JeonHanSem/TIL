#include <stdio.h>

#define MAX_SIZE 1001

int main(){
	int n,i,j;
	int arr[MAX_SIZE]={0};
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		for(j=1;j<=i;j++){
			arr[i]=arr[i]>arr[i-j]+arr[j]?arr[i]:arr[i-j]+arr[j];
		}
	}
	printf("%d\n",arr[n]);
}