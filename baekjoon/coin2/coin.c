#include<stdio.h>

#define MAX_SIZE 100000

void scan(int *n,int *k,int *coin){
	int i;
	scanf("%d %d",&(*n),&(*k));
	for(i=0;i<(*n);i++){
		scanf("%d",&coin[i]);
	}
}

int min(int a,int b){return a>b?b:a;}

void calc(int n,int k,int *coin){
	int i,j;
	int cnt[MAX_SIZE];

	for(i=0;i<=k;i++)
		cnt[i]=MAX_SIZE;
	
	for(i=0;i<n;i++){
		cnt[coin[i]]=1;
		for(j=1;j<=k-coin[i];j++){
			cnt[j+coin[i]]=min(cnt[j+coin[i]],cnt[j]+1);
		}
	}
	
	printf("%d\n",(cnt[k]==MAX_SIZE)?-1:cnt[k]);
}

int main(){
	int n,k;
	int coin[MAX_SIZE];

	scan(&n,&k,coin);
	calc(n,k,coin);
}