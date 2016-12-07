#include <stdio.h>

#define MAXSIZE 1001

int main(){
	int n,i;
	int arr[MAXSIZE]={0,1,3};

	scanf("%d",&n);

	for(i=3;i<=n;i++){
		arr[i]=(arr[i-1]+arr[i-2]*2)%10007;
	}
	printf("%d\n",arr[n]);
}
