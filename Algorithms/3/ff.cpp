#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long long sx,sy,x,y,n,ans=0,dist=1000000000000ll,diff,rv;
	cin>>n;
	cin>>sx>>sy;
	vector<pair<long long,long long> > v;

	v.push_back(make_pair(sx,sy));
	for(int i=1;i<n;i++) {
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(v[j].first==1000000000000ll)continue;
			diff=abs(sx-v[j].first)+abs(sy-v[j].second);
			if(diff<dist) {
				dist=diff;
				sx=v[j].first;
				sy=v[j].second;
				rv=j;
			}
		}
		v[rv].first=v[rv].second=1000000000000ll;
		dist=1000000000000ll;
		ans+=dist;
	}

	cout<<ans<<endl;

	return 0;
}
