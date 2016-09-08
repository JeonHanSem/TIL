#include <stdio.h>

#define MAX 100001

void sequencial(int *arr,int T){
	int _max=-1001,sum=0;
	int i;

	for(i=0;i<T;i++){
		sum+=arr[i];
		_max = _max>sum?_max:sum;
		if(sum<0) sum=0;
	}
	printf("%d\n",_max);
}

int main(){
	int T,i;
	int arr[MAX];
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d",&arr[i]);
	}
		sequencial(arr,T);
}
