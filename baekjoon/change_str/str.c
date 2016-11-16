#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

int change(char *A,char *B){
	int arr[MAX_SIZE],brr[MAX_SIZE];
	int i,j,ans=0;
	int a=strlen(A);
	int b=strlen(B);
	int posA=0,posB=0;

	if(a!=b) return -1;
	for(i=0;i<a;i++){
		if(A[i]=='a')
			arr[posA++]=i;
		if(B[i]=='a')
			brr[posB++]=i;
	}
	if(posA!=posB) return -1;
	for(i=0;i<posA;i++)
		ans+=abs(arr[i]-brr[i]);
	return ans;
}

int main(){
	int T;
	char A[MAX_SIZE],B[MAX_SIZE];

	scanf("%d",&T);
	while(T--){
		scanf("%s %s",A,B);
		printf("%d\n",change(A,B));
	}
}	
