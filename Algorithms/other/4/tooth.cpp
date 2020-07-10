#include<iostream>
#include<vector>

using namespace std;

int c,t,ans=-1,tmp;
vector<vector<int> > cp;
vector<int> ct;

bool satisfy(int p, int cn) {
	if(cn==c)return 1;
	bool sat=0;
	for(int i=0;i<c;i++) {
		for(int j=0;j<=p;j++) {
			if(cp[i][j]==0)continue;
			cp[i][j]--;
			sat=satisfy(p, i+1);
			cp[i][j]++;
		}
	}
	return sat;
}
int main() {
	cin>>c>>t;
	for(int i=0;i<t;i++) {
		cin>>tmp;
		ct.push_back(tmp);
	}
	for(int i=0;i<c;i++) {
		vector<int> prf(t);
		for(int j=0;j<t;j++)cin>>prf[j];
		cp.push_back(prf);
	}
	for(int i=0;i<t;i++) {
		if(satisfy(i, 0)) {
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
