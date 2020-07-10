#include<iostream>
#include<vector>

using namespace std;

int main() {
	long long n,ans;
	cin>>n;
	ans=n*n+2;
	vector<vector<long long> > g;
	for(int i=0;i<n;i++) {
		vector<long long> t(n);
		for(int j=0;j<n;j++)cin>>t[j];
		g.push_back(t);
	}
	vector<vector<pair<long long, long long> > > hov;
	for(int i=0;i<(n*n)+2;i++) {
		vector<pair<long long, long long> > tv;
		hov.push_back(tv);
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			hov[g[i][j]].push_back(make_pair(i, j));
		}
	}
	for(int i=0;i<(n*n)+2;i++) {
		if(hov[i].size()<2)continue;
		for(int j=0;j<hov[i].size();j++) {
			for(int k=j+1;k<hov[i].size();k++) {
				long long tans=abs(hov[i][j].first-hov[i][k].first)+abs(hov[i][j].second-hov[i][k].second);
				if(tans<ans)ans=tans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
