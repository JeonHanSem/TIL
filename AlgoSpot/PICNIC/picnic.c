#include <stdio.h>

#define MAX 10+1

int n,m;
int ans;
int mark[MAX];
int friend[MAX][MAX];

//initialize
void init(){
	int i,j;
	ans=0;
	for(i=0;i<n;i++)
		mark[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			friend[i][j]=0;
}

void picnic(int cnt){
	int i;
	int pos;

	if(cnt==n){ //all matching
		ans++;
		return;
	}
	for(i=0;i<n;i++){
		if(!mark[i]){ //not yet matched
			pos=i;
			break;
		}
	}
	
	for(i=pos+1;i<n;i++){
		if(mark[i]) continue;	//already matched
		if(friend[pos][i] && friend[i][pos]){	//if friend
			mark[i]=mark[pos]=1;
			picnic(cnt+2);
			mark[i]=mark[pos]=0;
		}
	}
}

int main(){
	int T,i;
	int a,b;
	
	scanf("%d",&T);

	while(T--){
		scanf("%d %d",&n,&m);
		init();
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			friend[a][b]=friend[b][a]=1;
		}
		picnic(0);
		printf("%d\n",ans);
	}
}
