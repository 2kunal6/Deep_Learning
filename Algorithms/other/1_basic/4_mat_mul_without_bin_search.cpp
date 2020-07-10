#include<iostream>
#include<map>
#include<vector>
#include<utility>

using namespace std;

int main() {
	int n,m,vnz;
	cin>>n>>m;
	int mt[m][3];
	for(int i=0;i<m;i++)cin>>mt[i][0]>>mt[i][1]>>mt[i][2];
	cin>>vnz;
	//map<int, int> vm;
	vector<pair<int, int> > vm;
	for(int i=0;i<vnz;i++) {
		int t1,t2;
		cin>>t1>>t2;
		vm.push_back(make_pair(t1, t2));
	}
	for(int i=0;i<m;i++) {
		//mt[i][2]*=(vm[mt[i][1]]);
		for(int j=0;j<vnz;j++) {
			if(vm[j].first==mt[i][1]) {
				mt[i][2]*=(vm[j].second);
				break;
			}
		}
	}
	int ans=mt[0][2];
	for(int i=1;i<m;i++) {
		if(mt[i][0]!=mt[i-1][0]) {
			if(ans!=0)cout<<mt[i-1][0]<<" "<<ans<<endl;
			ans=0;
		}
		ans+=mt[i][2];
	}
	if(ans!=0)cout<<mt[m-1][0]<<" "<<ans<<endl;
	return 0;
}
