#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<iomanip>

using namespace std;

vector<vector<double> > g;
int src,dst,n;

double dijk() {
	double dist[n];
	bool sp[n];
	for(int i=0;i<n;i++) {
		dist[i]=DBL_MAX;
		sp[i]=0;
	}
	dist[src]=0;
	for(int i=0;i<n-1;i++) {
		int minv;
		double mindist=DBL_MAX;
		for(int j=0;j<n;j++) {
			if(sp[j]==0 && dist[j]<mindist) {
				mindist=dist[j];
				minv=j;
			}
		}
		sp[minv]=1;
		if(minv==dst)return dist[dst];
		for(int j=0;j<n;j++) {
			if(!sp[j] && g[minv][j]!=-1 && dist[minv]!=DBL_MAX && (dist[minv]+g[minv][j]<dist[j]))dist[j]=dist[minv]+g[minv][j];
		}
		//for(int j=0;j<n;j++)cout<<dist[j]<<" ";
		//cout<<endl;
	}
	return dist[dst];
}

int main() {
	int q;
	cin>>n>>q;

	vector<pair<int, int> > cs(n);
	for(int i=0;i<n;i++)cin>>cs[i].first>>cs[i].second;

	for(int i=0;i<n;i++) {
		vector<double> tmp(n);
		for(int j=0;j<n;j++){
			cin>>tmp[j];
			if(cs[i].first<tmp[j])tmp[j]=-1;
			if(tmp[j]==-1)continue;
			tmp[j]/=(double)cs[i].second;
		}
		g.push_back(tmp);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	while(q--) {
		cin>>src>>dst;
		src--;dst--;
		cout << fixed << setprecision(2);
		cout<<dijk()<<" ";
	}
	cout<<endl;
	return 0;
}
