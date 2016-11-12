#include<stdio.h>

#define MAX_SIZE 10000

void scan(int *n){
	scanf("%d",&(*n));
}

void make(int n){
	int i;
	long long arr[MAX_SIZE]={0};
	arr[1]=1;
	arr[2]=2;

	for(i=3;i<=n;i++){
		arr[i]=(arr[i-1]+arr[i-2])%10007;
	}
	printf("%d\n",arr[n]%10007);
}

int main(){
	int n;

	scan(&n);
	make(n);
}
