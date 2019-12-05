#include<iostream>
#include<string>

using namespace std;

string s;

bool check(int a) {	
	int sc=0,ans=1;
	for(int i=0;i<s.size();i++) {
		if(s[i]==')') {
			if(sc==0) {
				ans=0;
				break;
			}
			sc--;
		} else sc++;
	}
}

int main() {
	cin>>s;
	if(sc!=0)ans=0;
	cout<<ans<<endl;
	return 0;
}
