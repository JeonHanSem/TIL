#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2502

int pp[MAX_SIZE][MAX_SIZE];
int a;
void check_pal(char *arr, int len){
	int i,j;
	for(i=1;i<=len;i++)
		pp[i][i]=pp[i+1][i]=1;

	for(i=1;i<=len;i++){
		for(j=1;j+i<=len;j++){
			if(arr[j-1]==arr[j+i-1] && pp[j+1][j+i-1])
				pp[j][j+i]=1;
		}
	}
}

int count_pal(char *arr,int len){
	int i,j;
	int ans[MAX_SIZE]={0};

	for(i=1;i<=len;i++){
		if((ans[i]!=0 && ans[i]>ans[i-1]+1) || ans[i]==0)
			ans[i]=ans[i-1]+1;

		for(j=i+1;j<=len;j++){
			if(pp[i][j]==1){
				if((ans[j]!=0 && ans[j]>ans[i-1]+1) || ans[j]==0)
					ans[j]=ans[i-1]+1;
			}
		}
	}
	return ans[len];
}

int main(){
	char arr[MAX_SIZE];
	int len,i;
	scanf("%s",arr);

	len=strlen(arr);
	check_pal(arr,len);

	printf("%d\n",count_pal(arr,len));
}
