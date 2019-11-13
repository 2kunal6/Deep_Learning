#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

map<long long, pair<long long, long long> > mx,my;
map<long long, pair<long long, long long> >:: iterator it;
long long sx,sy,px,py;

long long cal() {
	long long ans=0;
	px=sx;py=sy;
	for(it=mx.begin();it!=mx.end();it++) {
		ans+=(it->second.second-it->second.first);
		ans+=(abs(px-it->first));
		px=it->first;
		if(abs(it->second.first-py)>abs(it->second.second-py)) {
			py=it->second.second;
			ans+=(abs(it->second.first-py));
		} else {
			py=it->second.first;
			ans+=(abs(it->second.second-py));
		}
		//cout<<ans<<endl;
	}
	//cout<<px<<" "<<py<<" "<<sx<<" "<<sy<<endl;
	ans+=(abs(px-sx)+abs(py-sy));
	return ans;
}
long long caly() {
	long long ans=0;
	px=sx;py=sy;
	for(it=my.begin();it!=my.end();it++) {
		ans+=(it->second.second-it->second.first);
		ans+=(abs(px-it->first));
		px=it->first;
		if(abs(it->second.first-py)>abs(it->second.second-py)) {
			py=it->second.second;
			ans+=(abs(it->second.first-py));
		} else {
			py=it->second.first;
			ans+=(abs(it->second.second-py));
		}
		//cout<<ans<<endl;
	}
	//cout<<px<<" "<<py<<" "<<sx<<" "<<sy<<endl;
	ans+=(abs(px-sx)+abs(py-sy));
	return ans;
}
int main() {
	long long n,x,y,ans1=0,ans2=0;
	cin>>n;
	cin>>sx>>sy;
	
	mx[sx]=make_pair(sy, sy);
	my[sy]=make_pair(sx, sx);
	for(int i=1;i<n;i++) {
		cin>>x>>y;
		it=mx.find(x);
		if(it==mx.end())mx[x]=make_pair(y,y);
		else {
			if(y<it->second.first)it->second.first=y;
			if(y>it->second.second)it->second.second=y;
		}
		it=my.find(y);
		if(it==my.end())my[y]=make_pair(x,x);
		else {
			if(x<it->second.first)it->second.first=x;
			if(x>it->second.second)it->second.second=x;
		}
	}
	ans1=cal();
	//cout<<ans1<<endl;

	swap(sx, sy);
	ans2=caly();
	cout<<min(ans1,ans2)<<endl;
	
	return 0;
}
