#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000+1

int main(){
	int N;
	int i,j;
	char str[MAX];
	int arr[MAX];

	scanf("%s",str);
	for(i=0,j=0;str[i];i++){	//NULL이 아닐때까지 (strlen하면 시관초과)
		if(str[i]!=str[j])	j=i;	//같은숫자 아닐때 초기화
		arr[i]=i-j;	//연속적으로 같으면 갯수 세기
	}
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&i,&j);
		//i,j 구간 내에 모두 같은 값일때 최대값 abs(i-j)
		//배열값과 비교해서 배열값이 더크면 같은수만 있다는 뜻(즉, 최대 최소가 같다는 뜻)
		if(arr[i>j?i:j]>=abs(i-j))	printf("Yes\n");
		else printf("No\n");
	}
}