#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<long long, long long> > uh, lh, uhx,lhx,lehy,rihy;
long long sx,sy;

bool myComparison(const pair<long long, long long> &a,const pair<long long, long long> &b) {
       return a.second<b.second;
}

long long dist() {
	long long ans=0, px=sx, py=sy;
	for(int i=0;i<uh.size();i++) {
		ans+=(abs(px-uh[i].first)+abs(py-uh[i].second));
		px=uh[i].first;
		py=uh[i].second;
	}
	for(int i=0;i<lh.size();i++) {
		ans+=(abs(px-lh[i].first)+abs(py-lh[i].second));
		px=lh[i].first;
		py=lh[i].second;
	}
	ans+=(abs(px-sx)+abs(py-sy));
	return ans;
}

int main() {
	long long n,x,y;
	cin>>n;
	cin>>sx>>sy;
	for(int i=1;i<n;i++) {
		cin>>x>>y;
		if(x<=sx)uhx.push_back(make_pair(x,y));
		else lhx.push_back(make_pair(x,y));

		if(y<=sy)rihy.push_back(make_pair(x,y));
		else lehy.push_back(make_pair(x,y));
	}
	sort(uhx.begin(), uhx.end());
	reverse(uhx.begin(), uhx.end());
	sort(lhx.begin(), lhx.end());
	uh=uhx;lh=lhx;
	long long ans=dist(),oo;
	
	sort(rihy.begin(), rihy.end(), myComparison);
	reverse(rihy.begin(), rihy.end());
	sort(lehy.begin(), lehy.end(), myComparison);
	uh=rihy;lh=lehy;
	oo=dist();

	if(oo<ans)ans=oo;
	cout<<ans<<endl;
	
	return 0;
}
