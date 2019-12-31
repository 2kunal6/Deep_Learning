#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<bool> s,ts;
	char c;
	while(std::cin>>c) {
		if(c=='(')s.push(1);
		if(c=='?')s.push(0);
		if(c==')') {
			if(s.empty() && ts.empty()) {
				cout<<0<<endl;
				return 0;
			}
			while((!s.empty()) && (!s.top()==1)) {
				ts.push(s.top());
				s.pop();
			}
			if(s.empty())ts.pop();
			else s.pop();
		}
	}
	while(!ts.empty()) {
		s.push(ts.top());
		ts.pop();
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
