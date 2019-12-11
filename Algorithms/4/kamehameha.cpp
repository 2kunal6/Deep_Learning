#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	long long s1=0,s2=0;
	cin>>n;
	vector<long long> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for(int i=0;i<n;i++) {
		if(s1<s2)s1+=v[i];
		else s2+=v[i];
	}
	cout<<max(s1,s2)<<endl;
	return 0;
}
