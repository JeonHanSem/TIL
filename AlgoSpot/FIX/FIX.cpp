#include <iostream>

using namespace std;

int main(){
	int T,N;

	cin >> T;

	while(T--){
		int t,cnt=0;
		cin >> N;
		for(int i=1;i<=N;i++){
			cin >> t;
			if(t==i) cnt++;
		}
		cout << cnt << endl;
	}
}
