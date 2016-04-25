#include <stdio.h>

#define MAX 100

void hamming(char *str){
	int dec=0;
	
	//1st
	dec+=((str[0]-48)^(str[2]-48)^(str[4]-48)^(str[6]-48));
	//2nd
	dec+=2*((str[1]-48)^(str[2]-48)^(str[5]-48)^(str[6]-48));
	//3rd
	dec+=4*((str[3]-48)^(str[4]-48)^(str[5]-48)^(str[6]-48));

	if(dec!=0)
		str[dec-1] = str[dec-1] == '0' ? '1' : '0';

	printf("%c%c%c%c\n", str[2],str[4],str[5],str[6]);
}

int main(){
	char str[MAX];
	int n,i;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s",str);
		hamming(str);
	}
}