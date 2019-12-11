#include<iostream>

using namespace std;

int main() {
	char c;
	long long oct=0,qc=0;
	while(std::cin>>c) {
		if(c=='(') {
			oct++;
		}
		if(c==')') {
			if(oct==0 && qc==0) {
				cout<<0<<endl;
				return 0;
			}
			if(oct>0)oct--;
			else qc--;
		}
		if(c=='?') {
			qc++;
		}
	}
	if(oct!=0 && oct>qc) {
		cout<<0<<endl;
		return 0;
	}
	qc-=oct;
	if(qc%2==1) {
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}
