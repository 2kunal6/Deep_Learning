#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct edge {
	long long len;
	int from, to;
};
long long x,y,n,ans=0;
vector<pair<long long, long long> > nodes;
vector<edge> edges;
vector<vector<int> > mst;

bool mycom(edge a, edge b) {
	return a.len<b.len;
}
void kruskal() {
	vector<bool> vis(n,0);
	for(int i=0;i<n;i++) {
		vector<int> temp;
		mst.push_back(temp);
	}
	for(int i=0;i<edges.size();i++) {
		if(vis[edges[i].from]==1 && vis[edges[i].to]==1)continue;
		vis[edges[i].from]=vis[edges[i].to]=1;
		mst[edges[i].from].push_back(edges[i].to);
		mst[edges[i].to].push_back(edges[i].from);
	}
}
void preord() {
	vector<bool> vis(n,0);
	int prev;
	stack<int> s;
	s.push(0);
	prev=0;
	while(!s.empty()) {
		int val=s.top();
		s.pop();
		if(vis[val]==1)continue;
		vis[val]=1;
		ans+=(abs(nodes[prev].first-nodes[val].first)+abs(nodes[prev].second-nodes[val].second));
		prev=val;
		for(int j=0;j<mst[val].size();j++) {
			if(vis[mst[val][j]]==0)s.push(mst[val][j]);
		}
	}
	ans+=(abs(nodes[prev].first-nodes[0].first)+abs(nodes[prev].second-nodes[0].second));
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		nodes.push_back(make_pair(x,y));
		for(int j=0;j<i;j++) {
			edge e;
			e.from=j;
			e.to=i;
			e.len=abs(nodes[e.from].first-nodes[e.to].first)+abs(nodes[e.from].second-nodes[e.to].second);
			edges.push_back(e);
			swap(e.from,e.to);
			edges.push_back(e);
		}
	}
	sort(edges.begin(), edges.end(), mycom);
	//for(int i=0;i<edges.size();i++)cout<<edges[i].len<<" "<<edges[i].from<<" "<<edges[i].to<<endl;
	kruskal();
	/*for(int i=0;i<mst.size();i++) {
	  cout<<i<<":";
	  for(int j=0;j<mst[i].size();j++)cout<<mst[i][j]<<" ";
	  cout<<endl;
	  }*/
	preord();
	cout<<ans<<endl;
	return 0;
}
