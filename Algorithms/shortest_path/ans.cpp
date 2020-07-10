#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<iomanip>

using namespace std;

vector<vector<double> > g;
vector<vector<double> > dirg;
int src,dst,n;
vector<pair<int, int> > cs;

void dijk() {
	vector<double> dist(n);
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
	//for(int i=0;i<n;i++)cout<<dist[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++) {
		if(dist[i]>cs[src].first)dist[i]=-1;
		else dist[i]/=(double)cs[src].second;
	}
	//for(int i=0;i<n;i++)cout<<dist[i]<<" ";cout<<endl;
	dirg.push_back(dist);
}
double dijka() {
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
			if(!sp[j] && dirg[minv][j]!=-1 && dist[minv]!=DBL_MAX && (dist[minv]+dirg[minv][j]<dist[j]))dist[j]=dist[minv]+dirg[minv][j];
		}
	}
	return dist[dst];
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
		}
		g.push_back(tmp);
	}
	for(int i=0;i<n;i++) {
		src=i;
		dijk();
	}
	/*for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)cout<<dirg[i][j]<<" ";
		cout<<endl;
	}*/
	while(q--) {
		cin>>src>>dst;
		src--;dst--;
		cout << fixed << setprecision(2);
		cout<<dijka()<<" ";
	}
	cout<<endl;
	return 0;
}
