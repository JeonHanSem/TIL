#include <stdio.h>

int main(){
	int T,W,n;
	int sum;
	int i;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&W);
		sum=0;
		for(i=0;i<9;i++){
			scanf("%d",&n);
			sum+=n;
		}
		if(W>=sum) printf("YES\n");
		else printf("NO\n");
	}
}
