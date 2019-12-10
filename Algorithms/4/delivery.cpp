#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<iomanip>

using namespace std;

vector<vector<double> > g;
int src,dst,n;
vector<pair<int, int> > cs;

void dijk() {
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
		for(int j=0;j<n;j++) {
			if(!sp[j] && g[minv][j]!=-1 && dist[minv]!=DBL_MAX && (dist[minv]+g[minv][j]<dist[j]))dist[j]=dist[minv]+g[minv][j];
		}
	}
	for(int i=0;i<n;i++) {
		if(dist[i]>cs[i].first)g[src][i]=DBL_MAX;
		else g[src][i]/=(double)cs[i].second;
	}
}

int main() {
	int q, csf, css;
	cin>>n>>q;

	for(int i=0;i<n;i++) {
		cin>>csf>>css;
		cs.push_back(make_pair(csf,css));
	}

	for(int i=0;i<n;i++) {
		vector<double> tmp(n);
		for(int j=0;j<n;j++){
			cin>>tmp[j];
			if(tmp[j]==-1)tmp[j]=DBL_MAX;
		}
		g.push_back(tmp);
	}
	for(int i=0;i<n;i++) {
		src=i;
		dijk();
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	/*while(q--) {
		cin>>src>>dst;
		src--;dst--;
		cout << fixed << setprecision(2);
		cout<<dijk()<<" ";
	}*/
	cout<<endl;
	return 0;
}
