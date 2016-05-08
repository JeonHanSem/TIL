#include <iostream>

#define maxSize 10000

using namespace std;

int N,man[maxSize],woman[maxSize];

int meeting(){
	int sum=0;

	sort(begin(man),begin(man)+N); //내림차순 [](int a,int b){return a>b}
	sort(begin(woman),begin(woman)+N);

	for(int i=0;i<N;i++)
		sum+=abs(man[i]-woman[i]);

	return sum;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> man[i];
		for(int i=0;i<N;i++)
			cin >> woman[i];
		cout << meeting() << endl;
	}
}