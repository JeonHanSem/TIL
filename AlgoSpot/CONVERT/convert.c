#include <stdio.h>
#include <string.h>

#define MAX 1001

void convert(float num, char *str){
	if(!strcmp(str,"kg"))
		printf("%.4f lb\n", num*2.2046);
	else if(!strcmp(str,"lb"))
		printf("%.4f kg\n", num*0.4536);
	else if(!strcmp(str,"l"))
		printf("%.4f g\n", num*0.2642);
	else
		printf("%.4f l\n", num*3.7854);
}

int main(){
	int i,T;
	float num;
	char str[MAX];

	scanf("%d",&T);

	for(i=1;i<=T;i++){
		scanf("%f %s", &num,str);
		printf("%d ",i);
		convert(num,str);
	}
}
