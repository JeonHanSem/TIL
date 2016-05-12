#include <stdio.h>
#include <math.h>

// N:M=K:100
// N+x : M+x = K+1:100

#define AVERAGE(A,B) (B*100)/A

int ratio(long M,long N){
	int k=AVERAGE(M,N);
	double x;

	if(k>=99) return -1;

	x = (double)((k+1)*M-100*N)/(100-(k+1));
	return ceil(x);
}

int main(){
	long M,N;
	int T;

	scanf("%d",&T);

	while(T--){
		scanf("%ld %ld", &M,&N);
		printf("%d\n",ratio(M,N));
	}
}