#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n,ans;
	cin>>n;
	ans=n*n+2;
	vector<vector<long long> > g;
	for(int i=0;i<n;i++) {
		vector<long long> t(n);
		for(int j=0;j<n;j++)cin>>t[j];
		g.push_back(t);
	}
	queue<pair<int, int> > q;
	int hov[n*n][2];
	for(int i=0;i<n*n;i++)hov[i][0]=hov[i][1]=-1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i+1<n)q.push(make_pair(i+1, j));
			if(j+1<n)q.push(make_pair(i, j+1));
			if(hov[g[i][j]][0]!=-1) {
				int px=hov[g[i][j]][0], py=hov[g[i][j]][1];
				if(ans<)
			}
		}
	}
}
