#include <stdio.h>
#include <string.h>

#define MAX 100

void encrypt(char *str){
	int i;

	for(i=0;i<strlen(str);i++){
		if(i%2==0) printf("%c", str[i]);
	}
	for(i=0;i<strlen(str);i++){
		if(i%2==1) printf("%c", str[i]);
	}
	printf("\n");
}

int main(){
	int T;
	char str[100];

	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		encrypt(str);
	}
}