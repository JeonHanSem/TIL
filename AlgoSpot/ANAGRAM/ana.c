#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int cmp(const void *a, const void *b){return *(char*)a-*(char*)b;}

void ANAGRAM(char *str,char *str1){
	if(!strcmp(str,str1)){
		printf("No.\n");
		return;
	} 
	qsort(str,strlen(str),sizeof(char),cmp);
	qsort(str1,strlen(str1),sizeof(char),cmp);

	if(strcmp(str,str1)) printf("No.\n");
	else printf("Yes\n");
}

int main(){
	int T;
	char str[MAX],str1[MAX];

	scanf("%d",&T);

	while(T--){
		scanf("%s %s",str,str1);
		ANAGRAM(str,str1);
	}
}
