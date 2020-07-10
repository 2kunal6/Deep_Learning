#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

vector<vector<int> > g;
int n,m;
map<int, bool> ans;

void avc() {
	vector<bool> vis(n,0);
	for(int i=0;i<n;i++) {
		if(vis[i]==1)continue;
		stack<int> s;
		s.push(i);
		while(!s.empty()) {
			int val=s.top();
			s.pop();
			for(int j=0;j<g[val].size();j++) {
				if(vis[g[val][j]]==0) {
					vis[g[val][j]]=1;
					vis[val]=1;
					ans[g[val][j]]=1;
					ans[val]=1;
					break;
				}
			}
		}
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
	avc();
	cout<<ans.size()<<endl;
	return 0;
}
