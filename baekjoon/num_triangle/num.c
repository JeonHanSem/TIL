#include <stdio.h>

#define MAX_SIZE 500+1
#define MAX(A,B) A>B?A:B

int main(){
	int i,j,n;
	int arr[MAX_SIZE][MAX_SIZE]={0};
	int ans=0;

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			scanf("%d", &arr[i][j]);
			arr[i][j] += MAX(arr[i-1][j-1],arr[i-1][j]);
		}
	}
	for(i=1;i<=n;i++)
		ans=MAX(ans,arr[n][i]);
	printf("%d\n",ans);
}
