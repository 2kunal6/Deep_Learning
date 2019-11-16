#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<bool> > g;
vector<bool> vis;
int brs,n,id;
vector<int> ids,low;

void dfs(int at, int par) {
	vis[at]=1;
	id++;
	low[at]=ids[at]=id;
	for(int to=0;to<n;to++) {
		if(g[at][to]==1) {
			if(to==par)continue;
			if(!vis[to]) {
				dfs(to,at);
				low[at]=min(low[at], low[to]);
				if(ids[at]<low[to])brs++;
			} else {
				low[at]=min(low[at], ids[to]);
			}
		}
	}
}

void findbs() {
	for(int i=0;i<n;i++) {
		ids.push_back(0);
		low.push_back(0);
		vis.push_back(0);
	}
	for(int i=0;i<n;i++) {
		if(!vis[i])dfs(i, -1);
	}
}

int main() {
	int x,y,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		vector<bool> temp;
		for(int j=0;j<n;j++)temp.push_back(0);
		g.push_back(temp);
	}

	for(int i=0;i<m;i++) {
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	findbs();
	cout<<brs<<endl;
	return 0;
}
