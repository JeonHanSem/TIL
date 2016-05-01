#include <stdio.h>
#include <string.h>

#define MAX 100000

typedef enum {false, true}bool;

int find(char ch){
	char arr[6] = {'(','{','[',']','}',')'};
	int i;
	
	for(i=0;i<6;i++){
		if(ch == arr[i])
			return i;
	}
	return -1;
}

bool bracket(char *str){
	char arr[MAX];
	int i,k=0;

	for(i=0;i<strlen(str);i++){
		if(find(str[i])<3)
			arr[k++] = str[i];
		else{
			if(str[i]==']' && arr[k-1]=='[')	k-=1;
			else if(str[i]=='}' && arr[k-1]=='{')	k-=1;
			else if(str[i]==')' && arr[k-1]=='(')	k-=1;
			else return false;
		}
	}
	if(k==0)
		return true;
	return false;
}

int main(){
	int n;
	char str[MAX];

	scanf("%d",&n);

	while(n--){
		scanf("%s",str);
		if(bracket(str))	printf("YES\n");
		else	printf("NO\n");
	}	
}