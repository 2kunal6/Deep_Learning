#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	map<string, bool> mp;
	for(int i=0;i<n;i++) {
		string t;
		cin>>t;
		sort(t.begin(), t.end());
		mp[t]=1;
	}
	cout<<mp.size()<<endl;
	return 0;
}
