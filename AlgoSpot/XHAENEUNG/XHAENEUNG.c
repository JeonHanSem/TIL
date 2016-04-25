#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10+1

int cmpfunc (const void * a, const void * b) { return ( *(char*)a - *(char*)b ); }

char arr[MAX][MAX];
char strA[MAX],strB[MAX],strC[MAX];
char op,equal;

void initial(){
	strcpy(arr[0],"zero");
	strcpy(arr[1],"one");
	strcpy(arr[2],"two");
	strcpy(arr[3],"three");
	strcpy(arr[4],"four");
	strcpy(arr[5],"five");
	strcpy(arr[6],"six");
	strcpy(arr[7],"seven");
	strcpy(arr[8],"eight");
	strcpy(arr[9],"nine");
	strcpy(arr[10],"ten");
}

int compare(int num){
	char temp[MAX];
	strcpy(temp,arr[num]);

	qsort(temp,strlen(temp),sizeof(char),cmpfunc);
	qsort(strC,strlen(strC),sizeof(char),cmpfunc);

	if(strcmp(temp,strC)==0)
		return 1;
	else return 0;
}

int matching(char *temp){
	int i;

	for(i=0;i<MAX;i++){
		if(strcmp(temp,arr[i])==0)
			return i;
	}
}

int calc(){
	int num=0;
	
	num += matching(strA);
	if(op == '+') num += matching(strB);
	else if(op == '-') num -= matching(strB);
	else if(op == '*') num *= matching(strB);

	if(num>10)
		return 0;

	return compare(num);
}

int main(){
	int n,i;

	initial();

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s %c %s %c %s",strA,&op,strB,&equal,strC);
		if(calc())
			printf("Yes\n");
		else
			printf("No\n");
	}
}