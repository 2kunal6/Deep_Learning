#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long long px,py,sx,sy,x,y,n,ans=0,dist=1000000000000ll,diff,rv;
	cin>>n;
	cin>>sx>>sy;
	vector<pair<long long,long long> > v;

	v.push_back(make_pair(sx,sy));
	for(int i=1;i<n;i++) {
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	px=sx;py=sy;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(v[j].first==1000000000000ll)continue;
			diff=abs(px-v[j].first)+abs(py-v[j].second);
			if(diff<dist) {
				dist=diff;
				px=v[j].first;
				py=v[j].second;
				rv=j;
			}
		}
		v[rv].first=v[rv].second=1000000000000ll;
		dist=1000000000000ll;
		ans+=diff;
	}
	ans+=abs(px-sx)+abs(py-sy);

	cout<<ans<<endl;

	return 0;
}
