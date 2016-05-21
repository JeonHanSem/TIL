#include <stdio.h>
#include <math.h>

int n[4][8];

void swap(){
	int i,j,t;
	
	for(i=0;i<8;i++){
		t = n[0][i];
		n[0][i] = n[3][i];
		n[3][i] = t;
		
		t = n[1][i];
		n[1][i] = n[2][i];
		n[2][i] = t;
	}
}

unsigned int endian(unsigned int num){
	int i,k=0;
	unsigned int t=0;

	for(i=0;i<8*4;i++){
		if(i%8==0 && i!=0) k++;
		n[k][i%8]=num%2;
		num/=2;
	}

	swap();	
	k=3;
	t=0;
	for(i=31;i>=0;i--){
		if(i%8==7 && i!=31)	 k--;	
		t+=n[k][i%8]*pow(2,i);	
	}
	return t;
}

int main(){
	int t;
	unsigned int num;

	scanf("%d",&t);

	while(t--){
		scanf("%u",&num);
		printf("%u\n",endian(num));
	}
}
