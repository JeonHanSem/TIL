#include <stdio.h>
#include <string.h>

#define MAX 81

void mis(int M,char *str){
	int j;
	
	for(j=0;j<strlen(str);j++){
		if(j!=M-1) printf("%c",str[j]);
	}
}

int main(){
	int T,M,cnt=1;
	char str[MAX];

	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&M,str);
		printf("%d ",cnt++);
		mis(M,str);
		printf("\n");
	}
}
