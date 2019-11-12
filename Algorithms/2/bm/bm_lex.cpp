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
						//std::to_string(12)
						string is=std::to_string(i);
						string js=std::to_string(j);
						string ks=std::to_string(k);
						
						vector<string> tvfs;
						tvfs.push_back(is);tvfs.push_back(js);tvfs.push_back(ks);
						sort(tvfs.begin(), tvfs.end());
						string tsfs=tvfs[0]+" "+tvfs[1]+" "+tvfs[2];

						ans.push_back(tsfs);
					}
				}
			}
		}
		if(ans.size()>0) {
			sort(ans.begin(), ans.end());
			cout<<ans[0]<<endl;
		} else {
			cout<<"empty set"<<endl;
		}
	}
	return 0;
}
