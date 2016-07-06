#include "grammarChecker.cpp"

int main(){
	string fname;

	cout << "insert the file name : ";
	cin >> fname;
	Grammar g;
	if(!g.LoadGrammar(fname)){
		cout << "file is not exist" << endl;
		exit(1);
	}
	if(!g.print_all()){
		cout << "data is empty" << endl;
		exit(2);
	}
	set<char> e = g.getErules();
	set<char>::iterator i;
	for(i=e.begin();i!=e.end();i++)
		cout << (short)*i << " ";
	cout << endl;
}
