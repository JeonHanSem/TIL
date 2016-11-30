#include <stdio.h>

#define MAXSIZE 12 

int main(){
	int i;
	int T,n;
	int arr[MAXSIZE]={0,1,2,4};

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=4;i<=n;i++)
			arr[i]=arr[i-1]+arr[i-2]+arr[i-3];

		printf("%d\n",arr[n]);
	}
}
