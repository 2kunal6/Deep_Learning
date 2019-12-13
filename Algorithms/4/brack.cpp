#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<bit> s;
	char c;
	while(std::cin>>c) {
		if(c=='(')s.push(1);
		if(c=='?')s.push(0);
		if(c==')') {
			if(s.empty()) {
				cout<<0<<endl;
				return 0;
			}
			s.pop();
		}
	}
	int 
	while(!)
	return 0;
}
