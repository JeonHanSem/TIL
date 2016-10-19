#include <stdio.h>

#define MAX 1000+1

int sum(int* pass,int w){
	int i,sum=0;
	for(i=0;i<w;i++)
		sum+=pass[i];
	return sum;
}

void push(int* pass,int w){
	int i,flag=0,val;
	for(i=w-1;i>=0;i--){
		pass[i+1]=pass[i];
		if(pass[i+1]!=0 && flag==0){
			val=i;
			flag=1;
		}
	}
	pass[0]=0;
}

int find_pos(int *pass,int w,int num){
	int i;
	for(i=w-1;i>=0;i--){
		if(pass[i]==num) return i;
	}
	return w;
}

int main(){
	int n,w,L;
	int truck[MAX],pass[MAX]={0};
	int i,j,cnt=0,k;

	scanf("%d %d %d",&n,&w,&L);
	for(i=0;i<n;i++)
		scanf("%d",&truck[i]);

	truck[n]=L;
	for(i=0;i<n;i++){
		pass[0]=truck[i];
		if(sum(pass,w)+truck[i+1] <= L){
			cnt++;
			push(pass,w);
		}
		while(find_pos(pass,w,truck[i])<w && (sum(pass,w)+truck[i+1] > L)){
			push(pass,w);
			cnt++;
		}
	}
	printf("%d\n",cnt+1);
}
