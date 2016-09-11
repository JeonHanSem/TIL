#include <stdio.h>

#define MAX 1001
#define MIN(A,B) A<B?A:B

int T;
int arr[MAX][MAX];
int min=MAX*MAX;

int main(){
	int i,j;

	scanf("%d",&T);
	for(i=1;i<=T;i++){
		for(j=1;j<=3;j++){
			scanf("%d",&arr[i][j]);
			switch(j){
			case 1:
				arr[i][j] += MIN(arr[i-1][2],arr[i-1][3]);
				break;
			case 2:
				arr[i][j] += MIN(arr[i-1][1],arr[i-1][3]);
				break;
			case 3:
				arr[i][j] += MIN(arr[i-1][1],arr[i-1][2]);
				break;
			}
		}
	}
	for(i=1;i<=3;i++)
		min = MIN(min,arr[T][i]);	
	printf("%d\n",min);
}