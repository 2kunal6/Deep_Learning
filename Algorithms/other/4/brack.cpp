#include<iostream>
#include<stack>

using namespace std;

int main() {
	int s=0,ts=0;
	char c;
	while(std::cin>>c) {
		if(c=='(')s++;
		if(c=='?')ts++;
		if(c==')') {
			if(s==0 && ts==0) {
				cout<<0<<endl;
				return 0;
			}
			if(s==0)ts--;
			else s--;
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
