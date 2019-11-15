#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

map<long long, pair<long long, long long> > mx;
map<long long, pair<long long, long long> >:: iterator it;
long long sx,sy,px,py;
vector<pair<long long, long long> > inp;

long long cal() {
	long long ans=0,x,y;
	px=sx;py=sy;

	mx[sx]=make_pair(sy, sy);
	for(int i=1;i<inp.size();i++) {
		x=inp[i].first;
		y=inp[i].second;
		it=mx.find(x);
		if(it==mx.end())mx[x]=make_pair(y,y);
		else {
			if(y<it->second.first)it->second.first=y;
			if(y>it->second.second)it->second.second=y;
		}
	}
	for(it=mx.begin();it!=mx.end();it++) {
		ans+=(it->second.second-it->second.first);
		ans+=(abs(px-it->first));
		px=it->first;
		if(abs(it->second.first-py)>abs(it->second.second-py)) {
			ans+=(abs(it->second.first-py));
			py=it->second.second;
		} else {
			ans+=(abs(it->second.second-py));
			py=it->second.first;
		}
		//cout<<ans<<endl;
	}
	//cout<<px<<" "<<py<<" "<<sx<<" "<<sy<<endl;
	ans+=(abs(px-sx)+abs(py-sy));
	return ans;
}
int main() {
	long long x,y,n,ans1=0,ans2=0;
	cin>>n;
	cin>>sx>>sy;

	for(int i=1;i<n;i++) {
		cin>>x>>y;
		inp.push_back(make_pair(x,y));
	}

	ans1=cal();
	//cout<<ans1<<endl;

	swap(sx, sy);
	for(int i=0;i<n;i++)swap(inp[i].first, inp[i].second);
	ans2=cal();
	cout<<min(ans1,ans2)<<endl;

	return 0;
}
