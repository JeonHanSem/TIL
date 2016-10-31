#include <stdio.h>

#define MAX_SIZE 300+1
#define MAX(A,B) A>B?A:B

typedef struct{
	int val1;
	int val2;
}STAIR;

void stairs(int *arr,int n){
	int i;
	STAIR stair[MAX_SIZE];

	stair[0].val1=arr[0];
	stair[0].val2=0;
	stair[1].val1=arr[1];
	stair[1].val2=0;

	for(i=2;i<=n;i++){
		stair[i].val1=MAX(stair[i-2].val1,stair[i-2].val2);
		stair[i].val1+=arr[i];
		stair[i].val2=stair[i-1].val1+arr[i];
	}

	printf("%d\n",MAX(stair[n].val1,stair[n].val2));
}

int main(){
	int i,n;
	int arr[MAX_SIZE]={0};
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	stairs(arr,n);
}
