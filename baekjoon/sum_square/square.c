#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100001

int main(){
	int N,i,j;
	int arr[MAX_SIZE]={0};
	int val,pos;

	scanf("%d",&N);
	for(i=1;i<=N;i++){
		val=sqrt(i);
		pos=i-(val*val);
		arr[i]=arr[pos]+1;
		for(j=1;j*j<=i;j++){
			if(arr[i]>arr[i-j*j]+1){
				arr[i]=arr[i-j*j]+1;
			}
		}
	}	
	printf("%d\n",arr[N]);
}
