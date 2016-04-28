#include <stdio.h>
#include <string.h>

#define MAX 100

int MM,DD;
char day[MAX];

//find position
int find(){
	char str[][MAX] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int i;

	for(i=0;i<7;i++){
		if(!strcmp(str[i],day))	return i;
	}
	return -1;
}

int judge_month(int num){
	int Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int m;
	if(num > Month[MM-1]) return num - Month[MM-1];
	if(num < 1){
		if((m = MM-1) == 0) m=12; 
		return num + Month[m-1];
	}
	return num;
}

void calendar(){
	int i;
	int pos;
	int cal[7];

	pos = find();
	DD -= pos;
	for(i=0;i<7;i++){
		printf("%d ", judge_month(DD+i));
	}
	printf("\n");
}

int main(){
	int n;

	scanf("%d",&n);

	while(n--){
		scanf("%d %d %s",&MM,&DD,day);
		calendar();
	}
}