#include <stdio.h>
#include <string.h>

#define MAX 100

int i,j,n;
char str[MAX][MAX];
char arr[10];

void initial(){
	arr[0] = ' ';
	arr[1] = '!';
	arr[2] = '*';
	arr[4] = '$';
	arr[5] = '%';
	arr[8] = '(';
	arr[9] = ')';
}

void change(){
	char temp = str[i][j+2];

	if(temp=='a')
		temp = '2';

	j+=2;
	str[i][j] = arr[temp-48];
}

int main(){
	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%s",str[i]);
	}

	initial();

	for(i=0;i<n;i++){
		for(j=0;j<strlen(str[i]);j++){
			if(str[i][j]=='%' && str[i][j+1]=='2'){
				change();
			}
			printf("%c", str[i][j]);
		}
		printf("\n");
	}
}
