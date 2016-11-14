#include <stdio.h>
#define MAX_SIZE 101

int solution(int n){
	int mark[MAX_SIZE]={0};
	int i,j,val;
	int cnt=0;

	for(i=2;i<=n;i++){
		j=1;
		val=i;
		while(val<=n){
			mark[val]=mark[val]==0?1:0;
			val=(++j)*i;
		}
	}
	cnt=0;
	for(i=1;i<=n;i++){
		if(mark[i]==0)	cnt++;
	}
	return cnt;
}

int main(){
	int T,n;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d", &n);
		printf("%d\n",solution(n));
	}
}
