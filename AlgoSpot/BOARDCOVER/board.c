#include <stdio.h>

#define MAX 20+2

int H,W;
int cnt;
int ans;
char map[MAX][MAX];
char temp[MAX][MAX];

int init(){
	int i,j;

	for(i=0;i<=H+1;i++){
		for(j=0;j<=W+1;j++){
			map[i][j]='#';
		}
	}
	return 0;
}

int copy(){
	int i,j;

	for(i=1;i<=H;i++){
		for(j=1;j<=W;j++){
			map[i][j] = temp[i-1][j-1];
			if(map[i][j]=='.') cnt++;
		}
	}
	return cnt;
}

int check(int i,int j,int *mark){
	if(map[i-1][j]=='.' && map[i][j+1]=='.' && !mark[0]) return 0;
	if(map[i+1][j]=='.' && map[i][j+1]=='.' && !mark[1]) return 1;
	if(map[i+1][j]=='.' && map[i][j-1]=='.' && !mark[2]) return 2;
	if(map[i-1][j]=='.' && map[i][j-1]=='.' && !mark[3]) return 3;
	return -1;
}

void board(int fcnt,int row,int col){
	int i,j,k,l;
	int mark[4]={0};

	if(fcnt == cnt){
		ans++;
		return;
	} 

	for(i=row;i<=H;i++){
		if(i!=row) col=1;
		for(j=col;j<=W;j++){
			if(map[i][j]=='.'){
				col=j;
				map[i][j]='#';
				//.
				//..
				if(check(i,j,mark)==0){
					mark[0]=1;
					map[i-1][j]='#';
					map[i][j+1]='#';
					board(fcnt+3,i,col);
					map[i-1][j]='.';
					map[i][j+1]='.';
				}
				//..
				//.
				if(check(i,j,mark)==1){
					mark[1]=1;
					map[i+1][j]='#';
					map[i][j+1]='#';
					board(fcnt+3,i,col);
					map[i+1][j]='.';
					map[i][j+1]='.';
				}
				//..
				// .
				if(check(i,j,mark)==2){
					mark[2]=1;
					map[i][j-1]='#';
					map[i+1][j]='#';
					board(fcnt+3,i,col);
					map[i][j-1]='.';
					map[i+1][j]='.';
				}
				// .
				//..
				if(check(i,j,mark)==3){
					mark[3]=1;
					map[i][j-1]='#';
					map[i-1][j]='#';
					board(fcnt+3,i,col);
					map[i][j-1]='.';
					map[i-1][j]='.';
				}

				map[i][j]='.';
				//init mark
				for(k=0;k<4;k++)
					mark[k]=0;
			}
		}	
	}
}

int main(){
	int T,i,j;

	scanf("%d",&T);

	while(T--){
		scanf("%d %d",&H,&W);
		cnt = init();
		for(i=0;i<H;i++){
			scanf("%s",temp[i]);
		}
		cnt = copy();

		board(0,1,1);
		
		printf("%d\n", ans);
	}
}