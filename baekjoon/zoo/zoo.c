#include <stdio.h>

#define MAX 110000

int zoo(int n){
	int arr[MAX][3];
	int i;

	arr[1][0]=arr[1][1]=arr[1][2]=1;
	for(i=2;i<=n+1;i++){
		arr[i][0]=(arr[i-1][0]+arr[i-1][1]+arr[i-1][2])%9901;
		arr[i][1]=(arr[i-1][0]+arr[i-1][2])%9901;
		arr[i][2]=(arr[i-1][0]+arr[i-1][1])%9901;
	}
	return arr[n+1][0];
}

int main(){
	int n;
	scanf("%d",&n);
	
	printf("%d\n",zoo(n));
}
