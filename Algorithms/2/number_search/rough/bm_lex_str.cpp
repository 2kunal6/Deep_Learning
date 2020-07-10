#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long u,v,w;
		cin>>u>>v>>w;
		vector<string> ans;
		for(long long i=-110;i<=110;i++) {
			for(long long j=-110;j<=110;j++) {
				for(long long k=-110;k<=110;k++) {
					if(i==j || i==k || j==k)continue;
					if((((i*i)+(j*j)+(k*k))==w) && (i*j*k==v) && (i+j+k==u)) {
						ans.push_back(std::to_string(i)+" "+std::to_string(j)+" "+std::to_string(k));
					}
				}
			}
		}
		if(ans.size()>0) {
			sort(ans.begin(), ans.end());
			for(int i=0;i<ans.size();i++)cout<<ans[i]<<"|";
			cout<<endl;
			cout<<ans[0]<<endl;
		} else {
			cout<<"empty set"<<endl;
		}
	}
	return 0;
}
