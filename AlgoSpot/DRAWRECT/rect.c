#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){return *(int*)a-*(int*)b;}

void draw(int *xrr,int *yrr){
	qsort(xrr,3,sizeof(int),cmp);
	qsort(yrr,3,sizeof(int),cmp);
	
	if(xrr[0]!=xrr[1]) printf("%d ",xrr[0]);
	else printf("%d ",xrr[2]);

	if(yrr[0]!=yrr[1]) printf("%d\n",yrr[0]);
	else printf("%d\n", yrr[2]);
}

int main(){
	int T,i;
	int xrr[3],yrr[3];

	scanf("%d",&T);

	while(T--){
		for(i=0;i<3;i++){
			scanf("%d %d",&xrr[i],&yrr[i]);
		}
		draw(xrr,yrr);
	}
}
