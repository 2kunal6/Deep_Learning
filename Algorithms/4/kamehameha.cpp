#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<long long> v;
map<string, long long> mp;

long long part(int n, long long s1, long long s2) {
	if(n<0)return max(s1,s2);
	string key=to_string(n)+">"+to_string(s1);
	if(mp.find(key)==mp.end()) {
		long long inc=part(n-1, s1+v[n], s2);
		long long exc=part(n-1, s1, s2+v[n]);
		mp[key]=min(inc, exc);
	}
	return mp[key];
}
int main() {
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x;
		v.push_back((long long)x);
	}
	cout<<part(n-1, 0, 0)<<endl;
	return 0;
}
