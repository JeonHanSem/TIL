#include <stdio.h>

#define MAX_SIZE 25000

int main(){
	int n,k;
	int coin[MAX_SIZE]={0};
	int i,j,val;

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&val);
		coin[val]+=1;
		for(j=1;j+val<=k;j++){
			coin[j+val]+=coin[j];
		}
	}
	printf("%d\n",coin[k]);
}
