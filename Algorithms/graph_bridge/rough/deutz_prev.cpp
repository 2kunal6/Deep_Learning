#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<bool> > g;

int numcc(int n) {
	int ans=0;
	vector<bool> vis(n,0);
	for(int i=0;i<n;i++) {
		if(vis[i]==1)continue;
		//if(g[3][4]==0)cout<<i<<endl;
		stack<int> s;
		s.push(i);
		while(!s.empty()) {
			int val=s.top();
			s.pop();
			vis[val]=1;
			for(int j=0;j<n;j++) {
				if(g[val][j]==1 && vis[j]==0) {
					vis[j]=1;
					s.push(j);
				}
			}
		}
		ans++;
	}
	return ans;
}

int main() {
	int n,m,ans=0,icc;
	cin>>n>>m;
	vector<pair<int, int> > v(m);
	for(int i=0;i<n;i++) {
		vector<bool> temp;
		for(int j=0;j<n;j++)temp.push_back(0);
		g.push_back(temp);
	}
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
		v[i].first=x;
		v[i].second=y;
	}
	icc=numcc(n);
	//cout<<icc<<endl;
	for(int i=0;i<m;i++) {
		g[v[i].first][v[i].second]=0;
		g[v[i].second][v[i].first]=0;
		if(numcc(n)>icc)ans++;
		//cout<<numcc(n)<<endl;
		g[v[i].first][v[i].second]=1;
		g[v[i].second][v[i].first]=1;
	}
	cout<<ans<<endl;
	return 0;
}
