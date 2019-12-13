#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<bool> s;
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
	int cnt=0;	
	while(!s.empty()) {
		if(s.top()==0)cnt++;
		else cnt--;
		if(cnt<0) {
			cout<<0<<endl;
			return 0;
		}
		s.pop();
	}
	if(cnt%2==0)cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
