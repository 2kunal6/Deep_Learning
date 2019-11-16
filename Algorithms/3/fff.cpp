#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > g;
int ans=0,n,m;

void dfs() {
	vector<bool> vis(n,0);
	for(int i=0;i<n;i++) {
		if(vis[i]==1)continue;
		int non=0;
		stack<int> s;
		s.push(i);
		while(!s.empty()) {
			int val=s.top();
			s.pop();
			vis[val]=1;
			non++;
			for(int j=0;j<g[val].size();j++) {
				if(vis[g[val][j]]==0)s.push(g[val][j]);
			}
		}
		//cout<<non<<endl;
		ans+=(non/2);
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		vector<int> temp;
		g.push_back(temp);
	}

	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs();
	cout<<ans<<endl;
	return 0;
}
