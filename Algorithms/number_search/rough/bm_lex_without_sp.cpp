#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long u,v,w;
		cin>>u>>v>>w;
		string ans="empty set", hold="9999999999";
		for(long long i=-110;i<=110;i++) {
			for(long long j=-110;j<=110;j++) {
				for(long long k=-110;k<=110;k++) {
					if(i==j || i==k || j==k)continue;
					if((((i*i)+(j*j)+(k*k))==w) && (i*j*k==v) && (i+j+k==u)) {
						string is = std::to_string(i);
						string js = std::to_string(j);
						string ks = std::to_string(k);
						string th = is+" "+js+" "+ks;
						if(th<ans) {
							//hold=i;
							ans=th;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
