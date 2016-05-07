#include <stdio.h>

#define MAX 5000+1
#define maxSize 100+1

long coin(int money,int n,int *arr){
	long cnt[MAX]={0};
	int i,j;
	int coin;

	for(i=0;i<n;i++){
		if(money<arr[i]) break;
		coin = arr[i];
		cnt[coin]++;

		for(j=1;coin+j<=money;j++){
			cnt[coin+j]+=cnt[j];
		}
	}
	return cnt[money];
}

int main(){
	int i;
	int T,money,n;
	int arr[MAX];
	long cnt;

	scanf("%d",&T);

	while(T--){
		scanf("%d %d",&money,&n);
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		cnt = coin(money,n,arr);
		if(cnt>1000000007)
			printf("%ld\n", cnt%1000000007);
		else
			printf("%ld\n", cnt);
	}
}