#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool g[10000][10000];

bool allvis(int n) {
	vector<bool> vis(n,0);
	stack<int> s;
	s.push(0);
	while(!s.empty()) {
		int val=s.top();
		cout<<val<<endl;
		s.pop();
		vis[val]=1;
		for(int i=0;i<n;i++) {
			if(g[val][i]==1 && vis[i]==0) {
				vis[i]=1;
				s.push(i);
			}
		}
	}
	for(int i=0;i<n;i++)if(vis[i]==0)return 0;
	return 1;
}

int main() {
	int n,m,ans=0;
	cin>>n>>m;
	vector<pair<int, int> > v(m);
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		v[i].first=x;
		v[i].second=y;
	}
	for(int i=0;i<m;i++) {
		g[v[i].first][v[i].second]=0;
		if(!allvis(n))ans++;
		g[v[i].first][v[i].second]=1;
	}
	cout<<ans<<endl;
	return 0;
}
