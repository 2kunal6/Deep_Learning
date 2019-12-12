#include<iostream>
#include<vector>

using namespace std;

bool satisfy() {
	for(int i=0;i<)
}
int main() {
	int c,t,ans=-1;
	vector<int> ct(t);
	vector<vector<int> > cp;
	for(int i=0;i<t;i++)cin>>ct[i];
	for(int i=0;i<c;i++) {
		vector<int> prf(t);
		for(int j=0;j<t;j++)cin>>prf[j];
		cp.push_back(prf);
	}
	for(int i=0;i<t;i++) {
		if(satisfy()) {
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
