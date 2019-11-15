#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > g;

int numcc(int n) {
			//cout<<3<<endl;
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
			for(int j=0;j<g[val].size();j++) {
				if(g[val][j]!=-1 && vis[g[val][j]]==0) {
					vis[g[val][j]]=1;
					s.push(g[val][j]);
				}
			}
		}
		ans++;
	}
			//cout<<4<<endl;
	return ans;
}

int main() {
	int n,m,ans=0,icc;
	cin>>n>>m;
	g.resize(n);
	vector<pair<int, int> > v(m);
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		v[i].first=x;
		v[i].second=y;
	}
	icc=numcc(n);
	//cout<<icc<<endl;
	for(int i=0;i<m;i++) {
		int s1=-1,s2=-1;
		//cout<<1;
		for(int j=0;j<g[i].size();j++) {
			s1=g[i][j];
			g[i][j]=-1;
			int k;
			for(k=0;k<g[g[i][j]].size();k++) {
				if(g[g[i][j]][k]==i) {
					s2=g[g[i][j]][k];
					g[g[i][j]][k]=-1;
					break;
				}
			}
			if(numcc(n)>icc)ans++;
			if(s1!=-1)g[i][j]=s1;
			if(s2!=-1)g[g[i][j]][k]=s2;
			//cout<<2<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
