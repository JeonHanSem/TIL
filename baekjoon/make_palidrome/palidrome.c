#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1002

int pp[MAX_SIZE][MAX_SIZE];

void check_pal(char *arr,int len){
	int i,j;
	for(i=0;i<len;i++)
		pp[i][i]=pp[i+1][i]=1;

	for(i=0;i<len;i++){
		for(j=0;j<len-i;j++){
			if(arr[j]==arr[j+i] && pp[j+1][j+i-1]==1)
				pp[j][j+i]=1;
		}
	}
}

int main(){
	int i,j,len,pos;
	char arr[MAX_SIZE];

	scanf("%s",arr);

	len = strlen(arr);
	check_pal(arr,len);

	for(i=0;i<len;i++){
		if(pp[i][len-1]==1){
			pos=i;
			break;
		}
	}
	printf("%d\n",len+pos);
}
