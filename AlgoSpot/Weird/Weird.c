#include <stdio.h>

#define MAX 1000

int judge(int key,int *divisor,int flag){
	int i,t;
	if(key==0) return 0;
	if(key<0) return -1;
	for(i=flag;0<=(t=(key-divisor[i]));i++){
		if(!judge(t,divisor,i+1)) return 0;
	}

	return -1;
}

int weird(int n){
	int i,k=0;
	int sum=0;
	int key;
	int divisor[MAX];

	for(i=1;i<=n/2+1;i++){
		if(n%i==0){
			sum+=i;
			divisor[k++]=i;
		}
	}
	if(n<sum){
		key=sum-n;
		return judge(key,divisor,0);
	}
	else
		return 0;
}

int main(){
	int n,i;
	int natural;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&natural);
		if(weird(natural))
			printf("weird\n");
		else
			printf("not weird\n"); 
	}
}