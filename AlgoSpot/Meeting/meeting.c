#include <stdio.h>
#include <stdlib.h>

#define maxSize 10000

int N;
int man[maxSize],woman[maxSize];

int compare(const void *a, const void *b){
	return (*(int*)a- *(int*)b);
}

int meeting(){
	int i;
	int sum=0;

	qsort(man,N,sizeof(int),compare);
	qsort(woman,N,sizeof(int),compare);

	for(i=0;i<N;i++)
		sum+=abs(man[i]-woman[i]);

	return sum;
}

int main(){
	int T;
	int i;

	scanf("%d",&T);

	while(T--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&man[i]);
		for(i=0;i<N;i++)
			scanf("%d",&woman[i]);
		printf("%d\n",meeting());
	}
}